#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=300010,M=100010;
int n,m,q,ans=0;
int v[N],w[N],d[N],f[1030][M];
inline void dfs1(int x)
{
    d[x]=d[x/2]+1;
    for(int k=0;k<=1e5;k++)
        f[x][k]=f[x/2][k];
    for(int k=w[x];k<=1e5;k++)
        f[x][k]=max(f[x][k],f[x/2][k-w[x]]+v[x]);
    if(d[x]==m) return;
    dfs1(x<<1);
    dfs1(x<<1|1);
    return;
}
inline void dfs2(int x,int y,long long z)
{
    if(d[x]==m)
    {
        ans=max(ans,z+f[x][y]);
        return;
    }
    if(y>=w[x]) dfs2(x/2,y-w[x],z+v[x]);
    dfs2(x/2,y,z);
    return;
}
int main()
{
    scanf("%d",&n);
    m=log2(n)/2;
    if(m==0) m=1;
    for(int k=1;k<=n;k++)
        scanf("%d%d",&v[k],&w[k]);
    dfs1(1);
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans=0;
        if(d[x]) printf("%d\n",f[x][y]);
        else dfs2(x,y,0ll),printf("%d\n",ans);
    }
    return 0;
}
