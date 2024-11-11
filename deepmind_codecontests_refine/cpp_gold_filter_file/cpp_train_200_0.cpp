#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
struct ConfusionRatio
{
    int fm,fz;
    ConfusionRatio(int a=1,int b=1)
    {
        int g=gcd(a,b);
        fz=a/g;
        fm=b/g;
    }
    bool operator < (const ConfusionRatio &t) const
    {
        return (fz*1LL*t.fm-fm*1LL*t.fz)<=0;
    }
    bool operator == (const ConfusionRatio &t)
    {
        return (fz*1LL*t.fm-fm*1LL*t.fz)==0;
    }
}t[2000005];
int n,a[25];
bool dp[21][200002];
bool check(int id)
{
    int l[25],r[25];
    for(int i=0;i<n;++i)
    {
        long long delt=t[id].fz*1LL*a[i]/t[id].fm;
        l[i]=(int)max(1LL,a[i]-delt);
        r[i]=(int)min(2*a[i]-1LL,a[i]+delt);
    }
    memset(dp,0,sizeof(dp));
    for(int i=l[0];i<=r[0];++i) dp[0][i]=1;
    for(int i=0;i<n-1;++i)
    {
        for(int j=l[i];j<=r[i];++j)
        {
            if(!dp[i][j]) continue;
            int m1=l[i+1]/j,m2=r[i+1]/j;
            while(m1*j<l[i+1]) m1++;
            for(int t=m1;t<=m2;++t) dp[i+1][t*j]=1;
        }
    }
    for(int i=l[n-1];i<=r[n-1];++i) if(dp[n-1][i]) return true;
    return false;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int m=0;
    scanf("%d",&n);
    t[m++]=ConfusionRatio(0,1);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        for(int j=1;j<a[i];++j) t[m++]=ConfusionRatio(j,a[i]);
    }
    sort(t,t+m);
    int N=0;
    for(int i=0;i<m;)
    {
        t[N++]=t[i];
        int j=i+1;
        while(j<m&&(t[j]==t[i])) j++;
        i=j;
    }
    int l=0,r=N-1;
    while(l+1<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(check(l)) printf("%.12f\n",t[l].fz*1.0/t[l].fm);
    else printf("%.12f\n",t[r].fz*1.0/t[r].fm);
    return 0;
}