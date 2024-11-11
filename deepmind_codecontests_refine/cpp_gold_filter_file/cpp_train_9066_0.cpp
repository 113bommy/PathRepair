#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x * f;
}
vector<int> g[N];
int f[N], rt;
int res = 0;
void dfs(int x, int fa, int k) {
  int mx1 = 0, mx2 = 0;
  for (int to : g[x]) {
    if (to == fa) continue;
    dfs(to, x, k);
    if (f[to] >= mx1)
      mx2 = mx1, mx1 = f[to];
    else if (mx2 < f[to])
      mx2 = f[to];
  }
  if (mx1 + 1 == k)
    res++, f[x] = 0;
  else if (mx1 + mx2 + 1 >= k)
    res++, f[x] = 0;
  else
    f[x] = mx1 + 1;
}
int solve(int n, int k) {
  res = 0;
  for (int i = 1; i <= n; i++) f[i] = 0;
  dfs(1, 0, k);
  return res;
}
int ans[N];
int n;
void dfs(int l, int r, int L, int R) {
  if (l > r || L > R) return;
  if (L == R) {
    for (int i = l; i <= r; i++) ans[i] = L;
    return;
  }
  int mid = (l + r) >> 1;
  int res = solve(n, mid);
  ans[mid] = res;
  dfs(l, mid - 1, res, R);
  dfs(mid + 1, r, L, res);
}
int main() {
  n = read();
  int block = min(n, 200);
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, n, 0, n);
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}
