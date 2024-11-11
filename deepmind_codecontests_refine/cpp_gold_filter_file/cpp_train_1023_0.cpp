#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define M 1000000007
#define N 100005
int u[N*2],v[N*2],p[N],r[N*2],w[N*2],n,m,i,j,k=0;

struct zb{
    int x, y,id,prx,pry;
}a[N];
int cmp(const int i, const int j){return w[i]<w[j];}
int cmp1(struct zb i, struct zb j){return i.x<j.x;}
int cmp2(struct zb i, struct zb j){return i.y<j.y;}
int fin(int x){return p[x]==x?x:p[x]=fin(p[x]);}
LL kru()
{
    LL ans=0;
    for(int i=0;i<n;i++)
        p[i]=i;
    for(int i=0;i<m;i++)
        r[i]=i;
    sort(r,r+m,cmp);
    for(int i=0;i<m;i++)
    {
        int e=r[i];
        int x=fin(u[e]);
        int y=fin(v[e]);
        if(x!=y){ans+=w[e];p[x]=y;}
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    m=(n-1)*2;
    for(i=0;i<n;i++)
        {scanf("%d%d",&a[i].x,&a[i].y);a[i].id=i;}
    sort(a,a+n,cmp1);
    for(i=n-1;i>0;i--)
        {a[i].x=a[i].x-a[i-1].x;a[i].prx=a[i-1].id;}
    for(i=1;i<=n-1;i++)
    {
        u[k]=a[i].id;v[k]=a[i].prx;w[k++]=a[i].x;
    }
    sort(a,a+n,cmp2);
    for(i=n-1;i>0;i--)
        {a[i].y=a[i].y-a[i-1].y; a[i].pry=a[i-1].id;}
    for(i=1;i<=n-1;i++)
    {
        u[k]=a[i].id;v[k]=a[i].pry;w[k++]=a[i].y;
    }
    printf("%lld",kru());
    return 0;
}
