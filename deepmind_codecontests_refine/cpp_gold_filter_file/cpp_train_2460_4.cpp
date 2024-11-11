#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int root[1 << 15];
int par[1 << 15];
int tmp[1 << 15];
int n, m;
bool a[1 << 15];
int getbit(int x, int i) { return (x >> i) & 1; }
int getpar(int u) { return (par[u] < 0) ? u : (par[u] = getpar(par[u])); }
bool join(int u, int v) {
  u = getpar(u);
  v = getpar(v);
  if (u == v) return false;
  if (par[u] > par[v]) swap(u, v);
  par[u] += par[v];
  par[v] = u;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = i & 1;
    int pre = cur ^ 1;
    for (int j = 0; j < m; j += 4) {
      char c;
      cin >> c;
      int val = 0;
      if (isdigit(c))
        val = c - '0';
      else
        val = 10 + c - 'A';
      for (int k = 0; k < 4; k++) {
        a[(j + k) << 1 | cur] = getbit(val, 3 - k);
        par[(j + k) << 1 | cur] = -1;
      }
    }
    for (int j = 0; j < m; j++)
      if (a[j << 1 | cur]) {
        ans++;
        if (j > 0 && a[(j - 1) << 1 | cur])
          ans -= join(j << 1 | cur, (j - 1) << 1 | cur);
        if (i > 1 && a[j << 1 | pre]) ans -= join(j << 1 | cur, j << 1 | pre);
      }
    if (i == 1) continue;
    for (int j = 0; j < m; j++) {
      tmp[j << 1 | cur] = getpar(j << 1 | cur);
    }
    memset(root, -1, sizeof(root));
    for (int j = 0; j < m; j++) {
      int p = tmp[j << 1 | cur];
      if (root[p] < 0) {
        par[j << 1 | cur] = -1;
        root[p] = j << 1 | cur;
      } else
        par[j << 1 | cur] = root[p];
    }
  }
  cout << ans;
  return 0;
}
