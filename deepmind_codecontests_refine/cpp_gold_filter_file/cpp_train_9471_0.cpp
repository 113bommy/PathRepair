#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

struct Edge{
    int to,cost;
    Edge(int to,int cost) :to(to),cost(cost){}
    Edge(){}
};
struct Lost{
    int s,t;
    Lost(int s,int t) :s(s),t(t){}
    Lost(){}
};
struct State{
    int v;
    int cost;
    int bit1,bit2;
    State(int v,int cost,int bit1,int bit2):
        v(v),cost(cost),bit1(bit1),bit2(bit2){}
    State(){}

    bool operator>(const State rth) const {
        return this->cost>rth.cost;
    }
};
int n,m,k,p;
vector<Edge> G[1003];
Lost lost[10];
int dp[1003][1<<6][1<<6];

int dijk() {
    rep(i,1003) rep(j,1<<6) rep(c,1<<6) dp[i][j][c]=INF;
    dp[p][0][0]=0;
    priority_queue<State,vector<State> ,greater<State> > que;
    que.push(State(p,0,0,0));

    while(que.size()) {
        State s=que.top(); que.pop();
        if(dp[s.v][s.bit1][s.bit2]>s.cost) continue;

        rep(i,G[s.v].size()) {
            Edge e=G[s.v][i];
            rep(a,k) {
                if(lost[a].s==e.to) {
                    if(dp[e.to][s.bit1|1<<a][s.bit2]>dp[s.v][s.bit1][s.bit2]+e.cost) {
                        dp[e.to][s.bit1|1<<a][s.bit2]=dp[s.v][s.bit1][s.bit2]+e.cost;
                        que.push(State(e.to,dp[e.to][s.bit1|1<<a][s.bit2],s.bit1|1<<a,s.bit2));
                    }
                }
                if(lost[a].t==e.to&&(s.bit1>>a)&1) {
                    if(dp[e.to][s.bit1][s.bit2|1<<a]>dp[s.v][s.bit1][s.bit2]+e.cost) {
                        dp[e.to][s.bit1][s.bit2|1<<a]=dp[s.v][s.bit1][s.bit2]+e.cost;
                        que.push(State(e.to,dp[e.to][s.bit1][s.bit2|1<<a],s.bit1,s.bit2|1<<a));
                    }
                }
            }
            if(dp[e.to][s.bit1][s.bit2]>dp[s.v][s.bit1][s.bit2]+e.cost) {
                dp[e.to][s.bit1][s.bit2]=dp[s.v][s.bit1][s.bit2]+e.cost;
                que.push(State(e.to,dp[e.to][s.bit1][s.bit2],s.bit1,s.bit2));
            }
        }
    }

    int ans=INF;
    rep(i,n) ans=min(ans,dp[i][(1<<k)-1][(1<<k)-1]);

    return ans;
}

int main() {
    cin>>n>>m>>k>>p;
    p--;
    rep(i,m) {
        int x,y,w;
        cin>>x>>y>>w;
        x--,y--;
        G[x].pb(Edge(y,w));
        G[y].pb(Edge(x,w));
    }
    rep(i,k) {
        int s,t;
        cin>>s>>t;
        s--,t--;
        lost[i].s=s;
        lost[i].t=t;
    }
    int ans=dijk();
    if(ans==INF) cout<<"Cannot deliver"<<endl;
    else cout<<ans<<endl;
    return 0;
}