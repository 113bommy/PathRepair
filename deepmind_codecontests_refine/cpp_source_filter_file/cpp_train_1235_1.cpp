#include<ios>
int n,c;
main()
{
    while(scanf("%d",&n),n)
    {
        c=0;
        while(n>4)c+=n/=5,;
        printf("%d\n",c);
    }
}
