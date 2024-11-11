#include<cstdio>
int a, b;
int main()
{
    scanf("%d%d",&a, &b);
    if(a+b == 15) printf("+");
    else if(a*b == 15) printf("*);
    else printf("x");
    return 0;
}