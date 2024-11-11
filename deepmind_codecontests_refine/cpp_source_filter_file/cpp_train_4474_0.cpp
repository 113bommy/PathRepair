#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF 1e16
#define mod 1000000007

int N,M;
vector<int> g[100010];
int p[100010];
vector<int> ds;
int c0,c1;
int dp[100010];
ll sum=0;

bool dfs(int v,int pari){
  p[v]=pari;
  if(pari==0)c0++;
  else c1++;
  bool ok=true;
  for(int nv : g[v]){
    if(p[v]==p[nv])ok=false;
    else{
      if(p[nv]==-1&&!dfs(nv,1-pari))ok=false;
    }
  }
  return ok;
}

int main(){
  cin>>N>>M;
  rep(i,M){
    int a,b;
    cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  memset(p,-1,sizeof(p));
  rep(i,N){
    if(p[i]!=-1)continue;
    c0=0;
    c1=0;
    if(!dfs(i,0)){
      cout<<-1<<endl;
      return 0;
    }
    ds.push_back(abs(c0-c1));
    sum+=abs(c0-c1);
  }
  sort(all(ds));
  vector<int> a,m;
  rep(i,ds.size()){
    int j=i;
    a.push_back(ds[i]);
    int cnt=1;
    while(j<ds.size()&&ds[j]==ds[i]){
      j++;
    }
    m.push_back(cnt);
    i=j-1;
  }
  memset(dp,-1,sizeof(dp));
  dp[0]=0;
  rep(i,a.size()){
    rep(j,N+1){
      if(dp[j]>=0)dp[j]=m[i];
      else if(j<a[i]||dp[j-a[i]]<=0)dp[j]=-1;
      else dp[j]=dp[j-a[i]]-1;
    }
  }

  ll res=-INF;
  rep(j,N+1){
    if(dp[j]<0)continue;
    ll d=abs(sum-2*j);
    ll x=(N+d)/2,y=(N-d)/2;
    assert(x+y==N);
    maxch(res,x*y-M);
  }
  cout<<res<<endl;
  return 0;
}

