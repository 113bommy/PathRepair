#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
long long fa[MAXN],a[MAXN],b[MAXN],cnt[MAXN],ans[MAXN];
long long find1(long long v)
{
    return fa[v]=fa[v]==v?v:find1(fa[v]);
}
void merge1(long long x,long long y)
{
    fa[x]=y;
    cnt[y]+=cnt[x];
}
int main()
{

    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        fa[i]=i;
        cnt[i]=1;
    }
    for(long long i=0;i<m;i++)
        cin>>a[i]>>b[i];
    ans[m-1]=n*(n-1)/2;
    for(long long i=m-1;i>0;i--)
    {
        long long x=find1(a[i]);
        long long y=find1(b[i]);
        if(x!=y)
        {
            ans[i-1]=ans[i]-cnt[x]*cnt[y];
            merge1(x,y);
        }
        else
            ans[i-1]=ans[i];
    }
    for(long long i=0;i<m;i++)
        cout<<ans[i]<<endl;
    return 0;
}
