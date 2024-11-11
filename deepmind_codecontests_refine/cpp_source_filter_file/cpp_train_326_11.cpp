#include <bits/stdc++.h>
using namespace std;
struct E {
  int to, i;
};
const long long INF = 1e18;
const int N = 105, M = 1e5 + 5, V = 2005, Z = 3e6, S = V - 2, T = V - 1;
int best[M], pos[M], atk[M], fuel[M], dt[V], p[V];
long long cp[Z], fl[Z], d[N][N], cost[M];
int ce = 0;
vector<E> g[V];
vector<pair<int, int>> lt[N];
bool notFree[M], loser[M];
void addEdge(int a, int b, long long c) {
  cp[ce] = c;
  g[a].push_back({b, ce++});
  cp[ce] = 0;
  g[b].push_back({a, ce++});
}
bool bfs() {
  queue<int> q;
  fill(dt, dt + V, -1);
  dt[S] = 0;
  q.push(S);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (E e : g[node]) {
      if (cp[e.i] > fl[e.i] && dt[e.to] == -1) {
        dt[e.to] = dt[node] + 1;
        q.push(e.to);
      }
    }
  }
  return dt[T] != -1;
}
long long dfs(int node, long long flow) {
  if (node == T) return flow;
  for (int &i = p[node]; i < g[node].size(); i++) {
    E e = g[node][i];
    if (cp[e.i] > fl[e.i] && dt[e.to] == dt[node] + 1) {
      int ret = dfs(e.to, min(flow, cp[e.i] - fl[e.i]));
      if (ret) {
        fl[e.i] += ret;
        fl[e.i ^ 1] -= ret;
        return ret;
      }
    }
  }
  return 0;
}
long long maxFlow() {
  long long flow = 0;
  while (bfs()) {
    memset(p, 0, sizeof(p));
    long long ret = 0;
    while (ret = dfs(S, INF)) {
      flow += ret;
    }
  }
  return flow;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      d[i][j] = INF;
    }
    d[i][i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    d[b][a] = d[a][b] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        d[j][k] = min(d[j][i] + d[i][k], d[j][k]);
      }
    }
  }
  int s, b, k;
  cin >> s >> b >> k;
  for (int i = 0; i < s; i++) {
    cin >> pos[i] >> atk[i] >> fuel[i] >> cost[i];
    pos[i]--;
  }
  for (int i = 0; i < b; i++) {
    int pl, def, gold;
    cin >> pl >> def >> gold;
    pl--;
    lt[pl].push_back({def, gold});
  }
  for (int i = 0; i < n; i++) {
    lt[i].push_back({0, 0});
    sort(lt[i].begin(), lt[i].end());
    for (int j = 1; j < lt[i].size(); j++) {
      lt[i][j].second = max(lt[i][j].second, lt[i][j - 1].second);
    }
  }
  for (int i = 0; i < s; i++) {
    loser[i];
    for (int j = 0; j < n; j++) {
      if (d[pos[i]][j] <= fuel[i]) {
        int q =
            upper_bound(lt[j].begin(), lt[j].end(), make_pair(atk[i] + 1, -1)) -
            lt[j].begin();
        if (q > 0) loser[i] = false;
        best[i] = max(best[i], lt[j][q - 1].second);
      }
    }
  }
  vector<int> vip;
  vector<pair<int, int>> dep;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    vip.push_back(a);
    vip.push_back(b);
    notFree[a] = notFree[b] = 1;
    dep.push_back({a, b});
  }
  sort(vip.begin(), vip.end());
  vip.erase(unique(vip.begin(), vip.end()), vip.end());
  long long ans = 0;
  for (int i = 0; i < s; i++) {
    if (!notFree[i] && best[i] > cost[i]) {
      ans += best[i] - cost[i];
    }
  }
  for (int i = 0; i < vip.size(); i++) {
    if (loser[vip[i]]) cost[vip[i]] = INF;
    addEdge(S, i, cost[vip[i]]);
    addEdge(i, T, best[vip[i]]);
    ans += best[vip[i]];
  }
  for (auto e : dep) {
    e.first = lower_bound(vip.begin(), vip.end(), e.first) - vip.begin();
    e.second = lower_bound(vip.begin(), vip.end(), e.second) - vip.begin();
    addEdge(e.second, e.first, INF);
  }
  ans -= maxFlow();
  cout << ans;
  return 0;
}
