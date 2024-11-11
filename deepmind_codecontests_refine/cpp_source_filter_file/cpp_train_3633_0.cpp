#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF (1<<29)
#define EPS 1e-10
#define MOD 1000000007

typedef pair<int, int> P;
typedef pair<int, P> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int N, M, K;
vector<P> G[4096];
int d[4096];


int main(){
  scanf("%d%d%d",&N,&M,&K);
  int a, b, l;
  rep(i,M){
    scanf("%d%d%d",&a,&b,&l); a--; b--;
    G[a].push_back(P(b, l));
    G[b].push_back(P(a, l));
  }

  priority_queue<P, vector<P>, greater<P> >q;
  int s;
  fill(d, d+N, INF);
  rep(i,K){
    scanf("%d", &s); s--;
    d[s] = 0;
    q.push(P(0, s));
  }
  
  /*  rep(i, N){
    rep(j, G[i].size()) printf("%d %d ", G[i][j].first, G[i][j].second);
    cout << endl;
    }*/
  
  while(!q.empty()){
    int cur = q.top().second, v = q.top().first;
    q.pop();
    //    cout << "cur " << cur << "v " << v << endl;
    if(v > d[cur]) continue;
    rep(i, G[cur].size()){
      P next = G[cur][i];
      //      cout << next.first << " " << d[next.first] << endl;
      if(d[next.first] > next.second + v){
	d[next.first] = next.second + v;
	q.push(P(d[next.first], next.first));
      }
    }
  }

  int res = 0;
  rep(i, N) if(d[i]!=INF) res = max(res, d[i]);
  //  rep(i, N) printf("%d ", d[i]); puts("");
  //  printf("%d\n", res);

  rep(i, N){
    rep(j, G[i].size()){
      P p = G[i][j];
      res = max(res, (int)((p.second+d[i]+d[p.first])/2.0 + 0.5));
      //      cout << i << " " << j << " " << res << endl;
    }
  }
  printf("%d\n", res);
  return 0;
}