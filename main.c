#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    double F, delta, x1, x2;
    char group_name[40];
    char student_name[40];

    FILE * fp_input, * output, * outbin;

    fp_input = fopen( "C:\\Users\\Leon\\Desktop\\Основи програмування\\Lab_5\\data.txt" , "r" );

    if(fp_input == NULL)
    {
       printf("Error");
    }

    fscanf( fp_input , "%lf" , &x1 );
    fscanf( fp_input , "%lf" , &x2 );
    fscanf( fp_input , "%d" , &N );
    fscanf( fp_input , "%lf\n" , &delta );
    fgets( group_name , 40 , fp_input );
    fgets( student_name , 40 , fp_input );

    //F = (9 * pow(x1, 3) + 1000);

    output = fopen( "C:\\Users\\Leon\\Desktop\\Основи програмування\\Lab_5\\table.txt" , "w" );

    if(output == NULL)
    {
       printf("Error");
    }

    system("cls");
        fprintf(output, "\n\r--------------------------------------\n\r");
        fprintf(output, "\n\r|    N    |     X     |    F(X)      |\n\r");
        fprintf(output, "\n\r--------------------------------------\n\r");
double t1;
t1 = x1;
    for(int i = 1;i <= N; i++)
        {
            F = (9 * pow(t1, 3) + 1000);
            fprintf(output, "\n|%4d     |%10.2f |%10.2f    |", i, t1, F);
            fprintf(output, "\n\r--------------------------------------\n\r");
            t1 += delta;
        }
        fprintf(output, "%s",group_name);

    outbin = fopen( "C:\\Users\\Leon\\Desktop\\Основи програмування\\Lab_5\\binar.bin" , "wb" );

    if(outbin == NULL)
    {
       printf("Error");
    }

    fwrite(&N, sizeof(int), 1, outbin );
double t2;
t2 = x1;
    for(int i = 1;i <= N; i++)
        {
            F = (9 * pow(t2, 3) + 1000);
            fwrite(&t2, sizeof(double), 1, outbin );
            fwrite(&F, sizeof(double), 1, outbin );
            t2 += delta;
        }

    if ((fclose(fp_input)!= 0)||(fclose(output)!= 0)||(fclose(outbin)!= 0))
    {
        printf("Error");
    }


    outbin = fopen( "C:\\Users\\Leon\\Desktop\\Основи програмування\\Lab_5\\binar.bin" , "rb" );

    if(outbin == NULL)
    {
       printf("Error");
    }

    N = 0;
    fread(&N, sizeof(int), 1, outbin);

    double *A;
    A = (double *) calloc (2*N, sizeof (double));
    if( A == NULL )
    {
        printf("Memory has not been allocated");
        exit(0);
    }
int t3 = 0;

    for(int i = 0;i < N; i++)
        {
            fread(&A[t3], sizeof(double), 1, outbin);
            fread(&A[t3+1], sizeof(double), 1, outbin);
            t3 = t3+2;
        }

        //system("cls");
        printf("\n\r--------------------------------------\n\r");
        printf("\n\r|    N    |     X     |    F(X)      |\n\r");
        printf("\n\r--------------------------------------\n\r");
int t=0;
    for(int i = 1;i <= N; i++)
        {
            printf("\n|%4d     |%10.2f |%10.2f    |", i, A[t], A[t+1]);
            printf("\n\r--------------------------------------\n\r");
            t=t+2;
        }

    return 0;
}
