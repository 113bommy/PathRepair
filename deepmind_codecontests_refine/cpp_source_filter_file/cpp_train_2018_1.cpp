#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 41e5 + 10;
const double eps = 1e-8;
const int MOD = 1e9 + 7;
void fre() { freopen("in.txt", "r", stdin); }
void freout() { freopen("out.txt", "w", stdout); }
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int c[55][55];
double poww[55];
int n, m;
void init() {
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }
  poww[0] = 1;
  for (int i = 1; i <= n; i++) poww[i] = poww[i - 1] * double(1) / double(m);
}
double dp[55][55][55];
int a[55];
int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  dp[0][0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
        if (dp[i][j][k] != 0) {
          for (int t = 0; t <= n - j; t++) {
            int tem = (t) / a[i + 1];
            if (t % a[i + 1] != 0) tem++;
            tem = max(tem, k);
            dp[i + 1][j + t][tem] += dp[i][j][k] * c[n - j][t] * poww[t];
          }
        }
      }
    }
  }
  double ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += double(i) * dp[m][n][i];
  }
  printf("%.10f\n", ans);
  return 0;
}
