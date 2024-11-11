#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[100010], l[110], num[21][21], f[1 << 21], d[100010];
void bfs(int x) {
  deque<int> q;
  q.push_back(x);
  while (!q.empty()) {
    int a = q.front();
    q.pop_front();
    for (int i = 1; i <= k; ++i) {
      if (a > l[i] && !d[a - l[i]]) {
        d[a - l[i]] = d[a] + 1;
        q.push_back(a - l[i]);
      }
      if (a + l[i] <= n && !d[a + l[i]]) {
        d[a + l[i]] = d[a] + 1;
        q.push_back(a + l[i]);
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!d[i]) d[i] = 1e9;
}
void read() {
  int ls1;
  static bool b[100010];
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) scanf("%d", &ls1), a[ls1] = 1;
  for (int i = 1; i <= n; ++i) b[i] = a[i] ^ a[i - 1];
  for (int i = 1; i <= k; ++i) scanf("%d", l + i);
  m = 0;
  for (int i = 1; i <= n; ++i)
    if (b[i]) a[++m] = i;
  if (m & 1) a[++m] = n + 1;
  return;
}
void solve() {
  for (int i = 1; i <= m; ++i) {
    d[a[i]] = 1;
    bfs(a[i]);
    for (int j = 1; j <= m; ++j) num[i][j] = d[a[j]] - 1;
    for (int j = 1; j <= n; ++j) d[j] = 0;
  }
  int U = (1 << m) - 1;
  f[1] = f[2] = 1e9;
  for (int i = 3; i <= U; ++i) {
    int v[21], _v = 0;
    for (int j = 1; j <= m; ++j) {
      if ((i >> (j - 1)) & 1) v[++_v] = j;
    }
    f[i] = 1e9;
    for (int j = 1; j <= _v; ++j) {
      for (int k = j + 1; k <= _v; ++k) {
        f[i] = min(f[i], f[i - (1 << (v[j] - 1)) - (1 << (v[k] - 1))] +
                             num[v[k]][v[j]]);
      }
    }
  }
  printf("%d\n", f[U] > 1e8 ? -1 : f[U]);
}
int main() {
  read();
  solve();
  return 0;
}
