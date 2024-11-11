#include<bits/stdc++.h>
#define fort(i,a,b) for(long long i=a;i<=b;i++)
#define forn(i,a,b) for(long long i=a;i>=b;i--)
#define x first
#define y second
#define MP make_pair
#define pb push_back
#define ii pair<long long ,long long >
#define MT make_tuple
#define tp tuple
bool getbit(long long x,long long y)
{
    return (x>>y)&1;
}
using namespace std;
const long long M=1e9+7;
long long test,n,f[205][205],h[205],l[205][205],tam1,tam2,tam3,tam4,rs;
vector<long long> a[205];
long long power(long long x,long long y)
{
    if (y==0) return 1;
    long long p=power(x,y/2);
    p=p*p%M;
    return y%2? p*x%M : p;
}
void dfs(long long u,long long pa)
{
    h[u]=h[pa]+1;
    l[u][0]=pa;
    for(long long v:a[u])
        if (v!=pa) dfs(v,u);
}
void build_lca()
{
    fort(i,1,log2(n))
        fort(j,1,n) l[j][i]=l[l[j][i-1]][i-1];
}
long long lca(long long u,long long v)
{
    if (h[u]<h[v]) swap(u,v);
    forn(i,log2(h[u]),0)
        if (h[l[u][i]]>=h[v]) u=l[u][i];
    if (u==v) return u;
    forn(i,log2(h[u]),0)
        if (l[u][i]!=l[v][i])
        {
            u=l[u][i];
            v=l[v][i];
        }
    return l[u][0];
}
long long dist(long long u,long long v)
{
    return h[u]+h[v]-2*h[lca(u,v)];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    fort(i,1,n-1)
    {
        long long u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    long long p2=power(2,M-2);
    fort(i,1,n) f[0][i]=1;
    fort(i,1,n)
        fort(j,1,n)
            f[i][j]=(f[i-1][j]+f[i][j-1])%M*p2%M;
    fort(i,1,n)
    {
        long long r=i;
        dfs(r,0);
        build_lca();
        fort(x,1,n)
            fort(y,1,x-1)
            {
                tam1=lca(x,y);
                tam3=dist(tam1,x);
                tam4=dist(tam1,y);
                rs=rs+f[tam3][tam4];
            }
    }
    rs=rs*power(n,M-2)%M;
    cout<<rs<<'\n';
}
