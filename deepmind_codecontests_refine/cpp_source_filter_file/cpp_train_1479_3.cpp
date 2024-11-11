#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
vector<int> a, b, c;
vector<int> parent;
void dfs(int v, int p, int colv, int colp, vector<int> adj[]) {
  parent[p] = v;
  if (colv == 0) ans += a[v];
  if (colv == 1) ans += b[v];
  if (colv == 2) ans += c[v];
  int col = 3 - colp - colv;
  for (int u : adj[v]) {
    if (u != p) {
      dfs(u, v, col, colv, adj);
    }
  }
}
int main() {
  int n, x, y, k1 = -1, k = -1;
  cin >> n;
  vector<int> adj[n + 1];
  a.assign(n + 1, 0);
  b.assign(n + 1, 0);
  c.assign(n + 1, 0);
  parent.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int maxi = 0;
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() == 1) {
      k = i;
      k1 = adj[i][0];
    } else
      maxi = max(maxi, int(adj[i].size()));
  }
  if (maxi > 2) {
    cout << -1 << endl;
    return 0;
  }
  long long fin = INT_MAX, p = -1, q = -1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        ans = 0;
        if (i == 0) ans = a[k];
        if (i == 1) ans = b[k];
        if (i == 2) ans = c[k];
        dfs(k1, k, j, i, adj);
        if (fin > ans) {
          fin = ans;
          p = i;
          q = j;
        }
      }
    }
  }
  cout << fin << endl;
  vector<int> ans1(n + 1, 0);
  ans1[k] = p + 1;
  ans1[k1] = q + 1;
  ans = 2, fin = p + q + 2;
  while (ans != n) {
    ans1[parent[k1]] = 6 - fin;
    fin = 6 - fin + ans1[k1];
    k1 = parent[k1];
    ans++;
  }
  for (int i = 1; i <= n; i++) cout << ans1[i] << " ";
}
