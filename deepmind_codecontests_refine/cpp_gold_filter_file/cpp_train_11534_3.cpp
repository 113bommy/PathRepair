#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
#define int long long
#define il inline
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define  pi  acos(-1)
#define ld  double
#define mod 1000000007
#pragma GCC optimize(2)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int c[N];
vector<ll> g[N],ans;
int sz[N],cnt[N];
void dfs1(int x,int fa){
    sz[x]=1;
    for(auto i:g[x]){
        if(i!=fa){
            dfs1(i,x);
            sz[x]+=sz[i];
        }
    }
}
void dfs2(int x,int fa){
    int tmp=cnt[c[x]];
    for(auto i:g[x]){
        if(i==fa)continue;
        int now=cnt[c[x]];
        dfs2(i,x);
        int dif=cnt[c[x]]-now;
        int d=sz[i]-dif;
        ans[c[x]]-=(d-1)*d/2;
    }
    cnt[c[x]]=tmp+sz[x];
}
signed main() {
   // IOS
    int n;
    cin>>n;
    memset(cnt,0, sizeof(cnt));
    ans.assign(n+10,n*(n-1)/2);
    for(int i=1;i<=n;i++){cin>>c[i];ans[c[i]]++;}
    for (int j = 0; j <n-1 ; ++j) {
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs1(1,0);
    dfs2(1,0);
    for (int i = 1; i <=n ; ++i) {
        ans[i]-=(n-cnt[i])*(n-cnt[i]-1)/2;
    }
    for (int i = 1; i <=n ; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}