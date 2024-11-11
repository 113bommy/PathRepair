#include <bits/stdc++.h>
using namespace std;
bool b[405][405];
int sauske() {
  int d[405], n, m, v, u;
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> v >> u, v--, u--, b[v][u] = b[u][v] = true;
  queue<int> q;
  q.push(0);
  while (q.size()) {
    v = q.front(), q.pop();
    for (int u = 1; u < n; u++)
      if (b[v][u] != b[0][n - 1] && !d[u]) d[u] = d[v] + 1, q.push(u);
  }
  if (d[n - 1])
    cout << d[n - 1];
  else
    cout << -1;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) sauske();
}
