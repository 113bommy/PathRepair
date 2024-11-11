#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[300010];
int main()
{
    scanf("%d%d",&k,&n);
    if(k%2==1)
    {
        for(i=1;i<=n;i++)
            a[i]=(k+1)/2;
        int last=n;
        for(i=1;i<=n/2;i++)
           { if(a[last]==1) last--;
            else 
            {
                a[last]--;
                for(j=last+1;j<=n;j++)
                    a[j]=k;
                last=n;
            }
            }
        for(i=1;i<=last;i++)
            printf("%d ",a[i]); 
    }
    else
    {
        printf("%d ",k/2);
        for(i=2;i<=n;i++)
            printf("%d ",k);
    }
    return 0;
}