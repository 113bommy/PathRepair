#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  T flag = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') flag = -1;
  for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  x *= flag;
}
const int maxn = 405;
int n;
int v[maxn], w[maxn];
int u[maxn][maxn], d[maxn][maxn], f[maxn][maxn], dp[maxn];
int ans;
void cmax(int &x, int y) { x = max(x, y); }
int main() {
  memset(f, 0xcf, sizeof(f));
  memset(d, 0xcf, sizeof(f));
  memset(u, 0xcf, sizeof(f));
  read(n);
  for (int i = 1; i <= n; i++) read(v[i]);
  for (int i = 1; i <= n; i++) read(w[i]);
  for (int i = 1; i <= n; i++) f[i][i] = v[1], u[i][i] = d[i][i] = 0;
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      for (int k = i; k < j - 1; k++) {
        if (w[k] + 1 == w[j]) {
          cmax(u[i][j], u[i][k] + f[k + 1][j - 1]);
        }
      }
      if (w[j - 1] + 1 == w[j]) cmax(u[i][j], u[i][j - 1]);
      for (int k = i + 2; k <= j; k++) {
        if (w[k] + 1 == w[i]) {
          cmax(d[i][j], d[k][j] + f[i + 1][k - 1]);
        }
      }
      if (w[i + 1] + 1 == w[i]) cmax(d[i][j], d[i + 1][j]);
      for (int k = i; k < j; k++) {
        cmax(f[i][j], f[i][k] + f[k + 1][j]);
      }
      if (w[j] > w[i] && w[j] - w[i] + 1 <= n)
        cmax(f[i][j], u[i][j] + v[w[j] - w[i] + 1]);
      if (w[j] < w[i] && w[i] - w[j] + 1 <= 0)
        cmax(f[i][j], d[i][j] + v[w[i] - w[j] + 1]);
      for (int k = i + 1; k < j; k++) {
        if (2 * w[k] - w[i] - w[j] > 0 && 2 * w[k] - w[i] - w[j] + 1 <= n)
          cmax(f[i][j], u[i][k] + d[k][j] + v[2 * w[k] - w[i] - w[j] + 1]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    for (int j = 0; j < i; j++) {
      dp[i] = max(dp[i], dp[j] + f[j + 1][i]);
    }
  }
  printf("%d\n", dp[n]);
  return 0;
}
