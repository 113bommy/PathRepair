#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

const int SIZE = 425252;

int n,m,s,gg;
map<pii,int> ids;
pii rev[SIZE];
inline int getid(const pii P){
  if(ids.count(P)==0){
    int id = ids.size();
    ids[P] = id;
    rev[id] = P;
  }
  return ids[P];
}
vi tms[125252];

vector<pii> g[SIZE];
int dist[SIZE];

int main(){
  scanf("%d%d%d%d",&n,&m,&s,&gg);
  --s;--gg;
  int start = getid(pii(s,0));
  tms[s].push_back(0);
  REP(i,m){
    int u,v,t,c;
    scanf("%d%d%d%d",&u,&v,&t,&c);
    --u;--v;
    tms[u].push_back(t);
    tms[v].push_back(t+c);
    g[getid(pii(u,t))].push_back(pii(getid(pii(v,t+c)),0));
  }
  REP(i,n){
    sort(ALL(tms[i]));
    tms[i].erase(unique(ALL(tms[i])),tms[i].end());
    REP(j,tms[i].size()-1){
      g[getid(pii(i,tms[i][j]))].push_back(pii(getid(pii(i,tms[i][j+1])),tms[i][j+1]-tms[i][j]));
    }
  }

  REP(i,ids.size())dist[i] = 1e9;

  int ans = 1e9;
  priority_queue<pll> Q;
  Q.push(pll(-0, start));
  dist[start] = 0;
  while(!Q.empty()){
    pll P = Q.top(); Q.pop();
    int p = P.second;
    ll d = dist[p];
    for(pii S : g[p]){
      int to = S.first;
      ll cost = S.second;
      ll nd = d + cost;
      if(dist[to] <= nd)continue;
      dist[to] = nd;
      if(rev[to].first==gg)CHMIN(ans,(int)nd);
      Q.push(pll(-nd, to));
    }
  }
  printf("%d\n",ans);
  return 0;
}