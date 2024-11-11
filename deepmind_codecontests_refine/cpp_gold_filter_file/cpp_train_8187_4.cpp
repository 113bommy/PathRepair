#include <bits/stdc++.h>
using namespace std;
const int N = 4007;
const int MX = 1e9 + 7;
const long long int INF = 1e18 + 9LL;
int n, n1, n2, m;
vector<pair<int, int> > G[N];
int d[N];
pair<int, int> p[N];
bool res[N];
int flow[N + N];
queue<int> Q;
bool bfs(int s, int t) {
  for (int i = 1; i <= n; ++i) d[i] = -1;
  d[s] = 0;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (pair<int, int> v : G[u])
      if (d[v.first] == -1 && flow[v.second]) {
        d[v.first] = d[u] + 1;
        p[v.first] = {u, v.second};
        Q.push(v.first);
      }
  }
  return d[t] != -1;
}
void maxFlow() {
  while (bfs(0, n)) {
    int cur = n;
    while (cur != 0) {
      pair<int, int> t = p[cur];
      flow[t.second] -= 1;
      if (t.second <= m)
        flow[t.second + m] += 1;
      else if (t.second <= m + m)
        flow[t.second - m] += 1;
      cur = t.first;
    }
  }
}
int main() {
  scanf("%d %d %d", &n1, &n2, &m);
  n = n1 + n2 + 1;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    flow[i] = 1;
    G[u].push_back({v + n1, i});
    G[v + n1].push_back({u, i + m});
  }
  int turns = m;
  for (int i = 1; i <= n1; ++i) {
    G[0].push_back({i, 2 * m + i});
    turns = min(turns, (int)G[i].size());
  }
  for (int i = n1 + 1; i < n; ++i) {
    G[i].push_back({n, 2 * m + i});
    turns = min(turns, (int)G[i].size() - 1);
  }
  puts("0");
  for (int i = 1; i <= turns; ++i) {
    for (int j = 1; j <= m; ++j) res[j] = false;
    for (int j = 2 * m + 1; j < 2 * m + n; ++j) ++flow[j];
    maxFlow();
    for (int j = 1; j <= m; ++j)
      if (flow[j] == 0) res[j] = true;
    for (int j = 1; j < n; ++j) {
      int need = flow[2 * m + j];
      for (pair<int, int> v : G[j]) {
        int type = v.second > m ? v.second - m : v.second;
        if (!res[type] && need) {
          --need;
          res[type] = true;
        }
      }
    }
    int ile = 0;
    for (int j = 1; j <= m; ++j)
      if (res[j]) ++ile;
    printf("%d ", ile);
    for (int j = 1; j <= m; ++j)
      if (res[j]) printf("%d ", j);
    puts("");
  }
  return 0;
}
