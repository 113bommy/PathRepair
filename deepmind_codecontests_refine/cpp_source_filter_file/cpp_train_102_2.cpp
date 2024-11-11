#include<stdio.h>
int selectionSort(int A[], int N)
{
int i, j, t, sw = 0, minj;
for(i=0;i<N-1;i++){
 minj = i;
 for(j=i;j<N;j++){
  if(A[j]<A[minj])
  minj=j;
  }
  t = A[i];
  A[i] = A[minj];
  a[minj] = t;
  if(i!=minj)
  sw++; 
}
return sw;
}


int main(void)
{
int i, n, A[100], sw;

scanf("%d", &N);
for(i=0;i<0;i++)
scanf("%d", &A[i]);

sw = selectionSort(A, N);

for(i=0;i<N;i++)
if(i>0)
printf(" ");
printf("%d", A[i]);
}
printf("\n");
printf("%d\n", sw);

return 0;
}