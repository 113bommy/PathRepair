#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long ans = 0;
  char last = ' ', ch = getchar();
  while (ch < '0' || ch > '9') last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9')
    ans = (ans << 3) + (ans << 1) + ch - '0', ch = getchar();
  if (last == '-') ans = -ans;
  return ans;
}
const int INF = 0x3f3f3f3f;
const int N = 60;
double fac[N];
int a[N];
long long f[N][N][N];
int n, p;
void pre() {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = 1.0 * i * fac[i - 1];
  }
}
double ans = 0;
int sum = 0;
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), sum += a[i];
  p = read();
  if (sum <= p) {
    printf("%.6lf\n", 1.0 * n);
    return 0;
  }
  pre();
  for (int x = 1; x <= n; ++x) {
    memset(f, 0, sizeof f);
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= i; ++j) {
        for (int k = 0; k <= p; ++k) {
          if (i == x) {
            f[i][j][k] = f[i - 1][j][k];
            continue;
          }
          f[i][j][k] = f[i - 1][j][k];
          if (k >= a[i] && j > 0) f[i][j][k] += f[i - 1][j - 1][k - a[i]];
        }
      }
    }
    for (int j = 1; j < n; ++j) {
      for (int k = max(0, p - a[x] + 1); k <= p; ++k) {
        ans += j * fac[j] * fac[n - j - 1] * f[n][j][k];
      }
    }
  }
  printf("%.6lf\n", ans / fac[n]);
  return 0;
}
