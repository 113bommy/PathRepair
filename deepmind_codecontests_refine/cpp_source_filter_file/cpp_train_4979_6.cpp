#include<cstdio>
int a, b;
int main()
{
    scanf("%d%d",&a, &b);
    if(a+b == 15) printf("+\n");
    else if(a*b == 15) printf("*\n);
    else printf("x\n");
    return 0;
}