#include <bits/stdc++.h>
using namespace std;
long long p[500000], n, m, c[500000], res = 0;
int v[100000], d[100000], tot = 0, is[100000];
vector<int> g[100000], r, q[100000];
int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }
set<pair<int, int> > s;
stack<int> sk;
void dfs(int x) {
  v[x] = tot;
  d[x] = tot++;
  sk.push(x);
  is[x] = 1;
  for (int i = 0; i < q[x].size(); i++) {
    int t = q[x][i];
    if (v[t] == -1)
      dfs(t), d[x] = min(d[x], d[t]);
    else if (is[t])
      d[x] = min(d[x], v[t]);
  }
  if (d[x] == v[x]) {
    while (sk.top() != x) {
      is[sk.top()] = 0;
      p[sk.top()] = x;
      sk.pop();
    }
    is[x] = 0;
    sk.pop();
  }
}
int main() {
  for (int i = 0; i < 500000; i++) p[i] = i;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> c[i];
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    q[u].push_back(v);
  }
  memset(v, -1, sizeof(v));
  memset(d, -1, sizeof(d));
  for (int i = 0; i < n; i++)
    if (v[i] == -1) dfs(i);
  for (int i = 0; i < n; i++) g[f(i)].push_back(i);
  for (int i = 0; i < n; i++) {
    if (g[i].empty()) continue;
    long long best = 1000000001LL, cnt = 0;
    for (int j = 0; j < g[i].size(); j++) best = min(best, c[g[i][j]]);
    res += best;
    for (int j = 0; j < g[i].size(); j++)
      if (c[g[i][j]] == best) cnt++;
    r.push_back(cnt);
  }
  cout << res << " ";
  res = 1;
  for (int i = 0; i < r.size(); i++) {
    res = (res * r[i]) % 1000000007LL;
  }
  cout << res << endl;
  return 0;
}
