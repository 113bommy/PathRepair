#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
template <class T>
inline void rd(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
int n;
int cnt, al[105 << 1], cl[105 << 1], kk[105];
int sz[105];
long long C[105][105], dp[105][105][105], dr[105][105];
long long As[105], Ans[105];
void jia(int x, int y) {
  al[++cnt] = y;
  cl[cnt] = kk[x];
  kk[x] = cnt;
}
long long dit(long long x) { return x > mo ? x - mo : x; }
void ddt(long long &x, long long y) {
  x += y;
  if (x >= mo) x -= mo;
}
void dfs(int x, int y) {
  int v, w;
  sz[x] = 1;
  dp[x][0][1] = 1;
  for (int i = kk[x]; i; i = cl[i])
    if ((v = al[i]) != y) {
      dfs(v, x);
      w = sz[x] + sz[v];
      for (int j = 0; j <= w; ++j)
        for (int k = 0; k <= w; ++k) dr[j][k] = 0;
      for (int u = sz[x] - 1; u >= 0; --u)
        for (int q = 1; q <= sz[x] - u; ++q)
          for (int k = sz[v] - 1; k >= 0; --k)
            for (int j = 1; j <= sz[v] - k; ++j) {
              ddt(dr[u + k][j + q], dp[x][u][q] * dp[v][k][j] % mo);
              ddt(dr[u + k + 1][q], dp[x][u][q] * dp[v][k][j] * j % mo);
            }
      for (int j = 0; j <= w; ++j)
        for (int k = 0; k <= w; ++k) dp[x][j][k] = dr[j][k];
      sz[x] = w;
    }
}
int main() {
  rd(n);
  int x, y;
  long long lc = 1;
  for (int i = 1; i < n; ++i) {
    rd(x);
    rd(y);
    jia(x, y);
    jia(y, x);
  }
  for (int i = 0; i <= n; ++i) C[i][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j) {
      C[i][j] = dit(C[i - 1][j - 1] + C[i - 1][j]);
    }
  dfs(1, 0);
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= n; ++j) ddt(As[n - 1 - i], dp[1][i][j] * j % mo);
  }
  As[n - 1] = 1;
  for (int i = 1; i <= n - 1; ++i, lc = lc * n % mo)
    As[n - 1 - i] = As[n - 1 - i] * lc % mo;
  for (int i = 0, j; i <= n - 1; ++i) {
    j = 1;
    for (int k = i; k <= n - 1; ++k, j = mo - j)
      ddt(Ans[i], j * C[k][i] % mo * As[k] % mo);
  }
  for (int i = 0; i < n; ++i) printf("%lld ", Ans[i]);
  return 0;
}
