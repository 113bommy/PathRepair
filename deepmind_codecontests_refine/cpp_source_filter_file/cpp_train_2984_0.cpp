#include <bits/stdc++.h>
using namespace std;
const int INF = 30;
vector<vector<int> > g, d;
vector<pair<int, int> > sc;
vector<int> cost, w, cn, c;
vector<bool> used;
int dfs(int v) {
  used[v] = true;
  int cnt = 1;
  for (vector<int>::iterator it = g[v].begin(); it != g[v].end(); ++it)
    if (!used[*it]) cnt += dfs(*it);
  return cnt;
}
int main() {
  int n, m;
  cin >> n >> m;
  used.resize(n, false);
  g.resize(n);
  int a, b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i)
    if (!used[i]) c.push_back(dfs(i));
  cn.resize(n + 1, 0);
  for (int i = 0; i < c.size(); ++i) ++cn[c[i]];
  for (int i = 0; i < cn.size(); ++i)
    if (cn[i] > 0) sc.push_back(make_pair(i, cn[i]));
  int M = 0, N;
  for (int i = 0; i < sc.size(); ++i) {
    int st = 1;
    while (sc[i].second >= st) {
      cost.push_back(st);
      w.push_back(st * sc[i].first);
      sc[i].second -= st;
      st *= 2;
    }
    if (sc[i].second > 0) {
      cost.push_back(sc[i].second);
      w.push_back(sc[i].second * sc[i].first);
    }
  }
  N = cost.size();
  M = n;
  d.resize(N + 1, vector<int>(M + 1, INF));
  for (int i = 0; i <= N; ++i) d[i][0] = 0;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) {
      d[i][j] = d[i - 1][j];
      if (j - w[i - 1] >= 0 && d[i - 1][j - w[i - 1]] + cost[i - 1] < d[i][j])
        d[i][j] = d[i - 1][j - w[i - 1]] + cost[i - 1];
    }
  int ans = INF;
  for (int i = 4; i <= M; ++i) {
    int tmp = i;
    bool good = true;
    while (tmp > 0 && good) {
      if (!(tmp % 10 == 4 || tmp % 10 == 7)) good = false;
      tmp /= 10;
    }
    if (good && ans > d[N][i]) ans = d[N][i];
  }
  if (ans < INF)
    cout << ans - 1;
  else
    cout << -1;
  return 0;
}
