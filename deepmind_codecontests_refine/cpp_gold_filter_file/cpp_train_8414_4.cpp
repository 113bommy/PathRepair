#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
const ll mod=1000000007;
const ll INF=1e15;
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
struct edge{ ll to; ll cap; ll rev;};
const ll MAXN=105;
vector<edge> G[MAXN];

bool used[MAXN];

void addEdge0(ll from, ll to, ll cap){
    edge A={to,cap,(ll)G[to].size()};
    edge B={from,0,(ll)G[from].size()};
    G[from].push_back(A);
    G[to].push_back(B);
    return;
}//有向グラフを作る

void addEdge1(ll a, ll b, ll cap){
    edge A={b,cap,(ll)G[b].size()};
    edge B={a,cap,(ll)G[a].size()};
    G[a].push_back(A);
    G[b].push_back(B);
    return;
}//無向グラフを作る

ll dfs(ll v, ll t, ll f){
    if(v==t) return f;
    used[v]=true;
    rep(i,G[v].size()){
        edge &e=G[v][i];
        if(!used[e.to] && e.cap>0){
            ll d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

ll MaxFlow(ll Start, ll Goal){
    ll ans=0;
    while(true){
        rep(i,MAXN) used[i]=false;
        ll P=dfs(Start,Goal,INF);
        if(P==0) break;
        ans+=P;
    }
    return ans;
}

int main(){
    ll N; cin>>N;
    ll SUM=0;
    REP(i,1,N+1){
        ll x; cin>>x;
        if(x<=0) addEdge0(102,i,-x);
        if(x>0) {addEdge0(i,103,x); SUM+=x;}
    }

    REP(i,1,N){
        ll K=2*i;
        while(K<=N) {
            addEdge0(i,K,INF);
            K+=i;
        }
    }
    cout<<SUM-MaxFlow(102,103)<<endl;

    
}
