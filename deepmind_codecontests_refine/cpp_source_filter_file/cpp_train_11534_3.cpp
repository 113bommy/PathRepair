#include<bits/stdc++.h>
#define see(x) cerr<<#x<<"="<<x<<endl;
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll fast(ll x,ll n) {ll ans=1;for(;n;n>>=1,x=x*x%mod) if(n&1) ans=ans*x%mod; return ans;}
const int N=1e6+100;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll c(ll x) {
    return x*(x+1)/2;
}
ll ans[N],siz[N],temp[N],a[N],n;
vector<int>edge[N];

void dfs(int x,int f) {
    ll t=temp[a[x]];
    siz[x]=1;
    for(auto v:edge[x]) if(v!=f) {
        ll pre=temp[a[x]];
        dfs(v,x);siz[x]+=siz[v];
        ans[a[x]]-=c(siz[v]-(temp[a[x]]-pre));
    }
    temp[a[x]]=t+siz[x];
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++) {
        int u,v;
        u=read();b=read();
        //scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) {
        ans[i]+=c(n)-c(n-temp[i]);
        printf("%lld\n",ans[i]);
    }
}
