#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<int> g[N];
int mn[N];
int mx[N];
int ans;
void dfs(int u, int p) {
  bool leaf = true;
  mn[u] = 1e9;
  mx[u] = -1e9;
  for (int v : g[u])
    if (v != p) {
      dfs(v, u);
      leaf = false;
      mn[u] = min(mn[u], mn[v] + 1);
      mx[u] = max(mx[u], mx[v] + 1);
    }
  if (leaf) {
    mn[u] = 0;
    mx[u] = 0;
  }
}
void dfs2(int u, int p) {
  const int m = g[u].size();
  bool ok = true;
  vector<int> hh;
  for (int v : g[u]) {
    if (mx[v] != mn[v]) ok = false;
    hh.push_back(mx[v] + 1);
  }
  if (ok) {
    sort(hh.begin(), hh.end());
    hh.erase(unique(hh.begin(), hh.end()), hh.end());
    if (hh.size() <= 2) {
      int len = 0;
      for (int e : hh) len += e;
      while (len % 2 == 0) len /= 2;
      ans = min(ans, len);
    }
  }
  vector<int> maxl(m);
  vector<int> maxr(m);
  vector<int> minl(m);
  vector<int> minr(m);
  maxl[0] = -1e9;
  minl[0] = 1e9;
  maxr[m - 1] = -1e9;
  minr[m - 1] = 1e9;
  for (int i = 1; i < m; i++) {
    maxl[i] = max(maxl[i - 1], mx[g[u][i - 1]] + 1);
    minl[i] = min(minl[i - 1], mn[g[u][i - 1]] + 1);
  }
  for (int i = m - 2; i >= 0; i--) {
    maxr[i] = max(maxr[i + 1], mx[g[u][i + 1]] + 1);
    minr[i] = min(minr[i + 1], mn[g[u][i + 1]] + 1);
  }
  for (int i = 0; i < m; i++) {
    int v = g[u][i];
    if (v == p) continue;
    mn[u] = min(minl[i], minr[i]);
    mx[u] = max(maxl[i], maxr[i]);
    dfs2(v, u);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (n == 2) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (g[i].size() >= 2) {
      ans = 1e9;
      dfs(i, -1);
      dfs2(i, -1);
      if (ans >= 1e8) ans = -1;
      cout << ans << endl;
      return 0;
    }
  }
}
