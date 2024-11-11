#include <bits/stdc++.h>
const int inf = 1000000000;
using namespace std;
const int maxn = 50005;
int ans[maxn], u[maxn], ne[maxn], he[maxn], to[maxn], col, n, r1, r2;
void addedge(int a, int b) {
  ne[col] = he[a], he[a] = col, to[col] = b, ++col;
  ne[col] = he[b], he[b] = col, to[col] = a, ++col;
}
void dfs(int v, int prv) {
  if (v != r2) {
    ans[v] = prv;
  }
  u[v] = 1;
  int _u = he[v];
  while (_u != -1) {
    int r = to[_u];
    if (u[r] == 0) dfs(r, v);
    _u = ne[_u];
  }
}
int main() {
  memset(u, 0, sizeof(u));
  memset(he, -1, sizeof(he));
  memset(ne, -1, sizeof(ne));
  cin >> n >> r1 >> r2;
  --r1, --r2;
  for (int i = 0; i < n; ++i) {
    if (i == r1) continue;
    int p;
    cin >> p;
    --p;
    addedge(i, p);
  }
  dfs(r2, -1);
  for (int i = 0; i < n; ++i) {
    if (i == r2) continue;
    cout << ans[i] + 1 << " ";
  }
  return 0;
}
