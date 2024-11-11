#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int x[2010],y[2010],pow[2010],sum[2010],n;
int main()
{
    scanf("%d",&n);int i,j;
    for (i=1;i<=n;i++) 
    {
        scanf("%d%d",&x[i],&y[i]);
        sum[i]=abs(x[i]+y[i]);
    }
    for (i=1;i<n;i++)
        if (sum[i]%2!=sum[i+1]%2) {printf("%d",-1);return 0;}
    int maxd=0,cnt=0;
    for (i=1;i<=n;i++) maxd=max(maxd,sum[i]);
    if  (!(sum[1]%2)) {pow[++cnt]=1;maxn--;} 
    int tmp=1;
    while (tmp<=maxd+1) {pow[++cnt]=tmp;tmp*=2;}
    printf("%d\n",cnt);
    for (i=1;i<=cnt;i++) printf("%d ",pow[cnt-i+1]);printf("\n");
    for (i=1;i<=n;i++)
    {
        int fx=x[i],fy=y[i],nx=0,ny=0;
        for (j=cnt;j>=1;j--)
        {
            int chax=fx-nx,chay=fy-ny;
            if (abs(chax)>abs(chay))
            {
                if (chax>0) {printf("R");nx+=pow[j];}
                else {printf("L");nx-=pow[j];}
            }
            else 
            {
                if (chay>0) {printf("U");ny+=pow[j];}
                else {printf("D");ny-=pow[j];}
            }
        }
        printf("\n");
    }
    return 0;
}