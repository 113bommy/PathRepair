#include <bits/stdc++.h>
template <class T>
inline bool rd(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <class T>
inline void pt(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) pt(x / 10);
  putchar(x % 10 + '0');
}
using namespace std;
const int N = 105;
int n, m, a[N];
double dp[N][N], tmp[N][N];
int main() {
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++) rd(a[i]);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) dp[i][j] = 1;
    double P = (double)n * (n + 1) / 2.0;
    while (m--) {
      memcpy(tmp, dp, sizeof dp);
      memset(dp, 0, sizeof dp);
      for (int x = 1; x <= n; x++)
        for (int y = x; y <= n; y++) {
          for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
              int a = i, b = j;
              if (x <= a && a <= y) a = x + y - a;
              if (x <= b && b <= y) b = x + y - b;
              if (a > b) swap(a, b);
              if (x <= i && j <= y)
                dp[a][b] += (1 - tmp[i][j]) * P;
              else
                dp[a][b] += tmp[i][j] * P;
            }
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++) {
        if (a[i] > a[j])
          ans += dp[i][j];
        else
          ans += 1 - dp[i][j];
      }
    printf("%.10f\n", ans);
  }
  return 0;
}
