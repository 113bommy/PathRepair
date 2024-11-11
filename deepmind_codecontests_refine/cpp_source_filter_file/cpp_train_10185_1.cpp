#include<cstdio>
using namespace std;
int a,b,c,i,j,n,anss;
int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&n);
    for (i=0;i<=a;i++)
     for (j=0;j<=b;j++)
      if ((n-i*500-j*100>=0)&&(n-i*500-j*100<=c*50)) anss++;
    printf("%d\n",ans);
    return 0;
}