#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define pb push_back
#define Rep(i, N) for(int i = 0; i < N; i++)
#define INF 1 << 28
#define LLINF 1LL << 60
typedef pair<int,int> Pi;
typedef pair<int,Pi> Ti;

struct Edge {
  int to, cost;
};

int sz[2], K;
vector<Edge> G[2][200005];
int mc[2][200005];

void Dijkstra()
{
  priority_queue<Ti, vector<Ti>, greater<Ti> >pq;
  mc[0][0] = 0;
  pq.push(Ti(0, Pi(0, 0)));
  while(!pq.empty()) {
    int v = pq.top().S.F, w = pq.top().F, t = pq.top().S.S; pq.pop();
    if(w > mv[t][v]) continue;
    Rep(i, G[t][v].size()) {
      int u = G[t][v][i].to, nw = G[t][v][i].cost + w, nnw = nw;
      if(u != K + 1) nnw++;
      if(nnw < mc[1 - t][u]) {
	mc[1 - t][u] = nnw;
	pq.push(Ti(nnw, Pi(u, 1 - t)));
      }
      if(nw < mc[t][u]) {
	mc[t][u] = nw;
	pq.push(Ti(nw, Pi(u, t)));
      }
    }
  }
}
	  
signed main()
{
  int X, Y;
  vector<Pi> len[2][100006];

  cin >> sz[0] >> sz[1] >> K;
  len[0][1].pb(Pi(0, 0));
  for(int i = 1; i <= K; i++) {
    cin >> X >> Y;
    len[0][X].pb(Pi(Y, i));
    len[1][Y].pb(Pi(X, i));
  }
  len[0][sz[0]].pb(Pi(sz[1], K + 1));
  len[1][sz[1]].pb(Pi(sz[0], K + 1));
  
  Rep(i, 2) {
    Rep(j, sz[i] + 1) {
      sort(len[i][j].begin(), len[i][j].end());
      Rep(k,len[i][j].size()) {
	Pi v = len[i][j][k];
	if(k - 1 >= 0) {
	  Pi u = len[i][j][k - 1];
	  G[i][v.S].pb((Edge){ u.S, v.F - u.F });
	}
	if(k + 1 < len[i][j].size()) {
	  Pi u = len[i][j][k + 1];
	  G[i][v.S].pb((Edge){ u.S, u.F - v.F });
	}
      }
    }
  }

  fill_n(*mc, 2 * 200005, LLINF);
  Dijkstra();
  
  int ans = min(mc[0][K + 1], mc[1][K + 1]);
  if(ans == LLINF) cout << -1 << endl;
  else cout << ans - 1 << endl;
  
  return 0;
}