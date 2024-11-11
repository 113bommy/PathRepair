#include<stdio.h>
int main()
{
int n,k,x,y,;
scanf("%d %d %d %d",&n, &k, &x, &y);
 if(n<=k) printf("%d\n",x*k);
else printf("%d\n",x*k+y*(n-k));
 return 0;
}