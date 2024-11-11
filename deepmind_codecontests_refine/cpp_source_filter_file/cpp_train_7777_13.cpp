#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2005;
int n, u[N], v[N], f[N][11][11][11][11];
int dis(int a, int b) { return abs(a - b); }
int dfs(int i, int cur, int a, int b, int c) {
  if (~f[i][cur][a][b][c]) return f[i][cur][a][b][c];
  int ret = 0x3f3f3f3f;
  if (i > n) {
    if (a == 0 && b == 0 && c == 0) return 0;
    if (a) ret = min(ret, dfs(i, a, 0, b, c) + dis(cur, a) + 1);
    if (b) ret = min(ret, dfs(i, b, a, 0, c) + dis(cur, b) + 1);
    if (c) ret = min(ret, dfs(i, c, a, b, 0) + dis(cur, c) + 1);
    return f[i][cur][a][b][c] = ret;
  }
  if (a) ret = min(ret, dfs(i, a, 0, b, c) + dis(cur, a) + 1);
  if (b) ret = min(ret, dfs(i, b, a, 0, c) + dis(cur, b) + 1);
  if (c) ret = min(ret, dfs(i, c, a, b, 0) + dis(cur, c) + 1);
  if (a && b && c) {
    ret = min(ret,
              dfs(i + 1, v[i], a, b, c) + dis(cur, u[i]) + dis(u[i], v[i]) + 2);
    ret =
        min(ret, dfs(i + 1, a, v[i], b, c) + dis(cur, u[i]) + dis(u[i], a) + 2);
    ret =
        min(ret, dfs(i + 1, b, a, v[i], c) + dis(cur, u[i]) + dis(u[i], b) + 2);
    ret =
        min(ret, dfs(i + 1, b, a, b, v[i]) + dis(cur, u[i]) + dis(u[i], c) + 2);
  } else {
    if (!a)
      ret = min(ret, dfs(i + 1, u[i], v[i], b, c) + dis(cur, u[i]) + 1);
    else if (!b)
      ret = min(ret, dfs(i + 1, u[i], a, v[i], c) + dis(cur, u[i]) + 1);
    else
      ret = min(ret, dfs(i + 1, u[i], a, b, v[i]) + dis(cur, u[i]) + 1);
  }
  return f[i][cur][a][b][c] = ret;
}
int main() {
  memset(f, 0xff, sizeof f);
  cin >> n;
  for (int i = 1; i < n + 1; ++i) cin >> u[i] >> v[i];
  cout << dfs(1, 1, 0, 0, 0);
  return 0;
}
