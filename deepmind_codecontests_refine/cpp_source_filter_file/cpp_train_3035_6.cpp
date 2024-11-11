#include <bits/stdc++.h>
using namespace std;
const int N = 75, M = 500;
int n, m, X, Y, s, sta, mn, x, y, z, sum, num, S, cnt, cnt2, a[M], b[M], c[M],
    d[M], a_[M], b_[M], c_[M], col[N], fl[N], f[N][1 << 17];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >,
               greater<tuple<int, int, int> > >
    Q;
inline void add(int x, int y, int z) {
  a[++cnt] = y, b[cnt] = c[x], c[x] = cnt, d[cnt] = z;
}
inline void ad(int x, int y) { a_[++cnt2] = y, b_[cnt2] = c_[x], c_[x] = cnt2; }
inline void dfs(int x) {
  if (fl[x]) return;
  fl[x] = num, ++sum;
  for (int i = c_[x]; i; i = b_[i]) dfs(a_[i]);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &X, &Y);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (z == X) ad(x, y), ad(y, x);
    add(x, y, z), add(y, x, z);
  }
  memset(col, -1, sizeof col);
  for (int i = 1; i <= n; i++)
    if (col[i]) {
      ++num, sum = 0, dfs(i);
      if (sum > 3) {
        for (int j = 1; j <= n; j++)
          if (fl[j] == num) col[j] = S;
        ++S;
      }
    }
  memset(f, 63, sizeof f);
  if (~col[1]) s = 1 << col[1];
  Q.push(make_tuple(0, 1, s)), f[1][s] = 0;
  while (!Q.empty()) {
    x = get<1>(Q.top()), y = get<2>(Q.top()), Q.pop();
    for (int i = c[x]; i; i = b[i]) {
      sta = y;
      if (d[i] == Y) {
        if (col[x] == col[a[i]])
          continue;
        else if (~col[a[i]] && (y & (1 << col[a[i]])))
          continue;
        if (~col[a[i]]) sta |= (1 << col[a[i]]);
      }
      if (f[x][y] + d[i] < f[a[i]][sta])
        f[a[i]][sta] = f[x][y] + d[i],
        Q.push(make_tuple(f[a[i]][sta], a[i], sta));
    }
  }
  for (int i = 1; i <= n; i++) {
    mn = 1 << 30;
    for (int j = 0; j < 1 << S; j++) mn = min(mn, f[i][j]);
    printf("%d ", mn);
  }
  return 0;
}
