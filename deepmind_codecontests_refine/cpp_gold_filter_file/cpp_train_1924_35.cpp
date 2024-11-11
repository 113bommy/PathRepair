#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, int p = (int)1e9 + 7) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
void addmod(int& a, int val, int p = (int)1e9 + 7) {
  if ((a = a + val) >= p) a -= p;
}
template <class T>
void setmin(T& a, T val) {
  a = min(a, val);
}
template <class T>
void setmax(T& a, T val) {
  a = max(a, val);
}
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = 2 * acos((long double)0);
const int maxn = 110;
int n, k;
int a[maxn];
long double f[2][maxn][maxn];
long double x[maxn][maxn];
long double y[maxn][maxn];
long double z[maxn][maxn];
void solve() {
  scanf("%d%d", &n, &k);
  k = min(k, 2000);
  for (int i = (0); i < (n); i++) scanf("%d", a + i);
  int cnt = 0;
  for (int i = (0); i < (n); i++)
    for (int j = (i + 1); j < (n); j++) {
      f[cnt][i][j] = a[i] > a[j];
    }
  for (int t = (0); t < (k); t++) {
    for (int i = (0); i < (n); i++)
      for (int j = (i + 1); j < (n); j++) {
        f[cnt][j][i] = 1 - f[cnt][i][j];
      }
    for (int j = (0); j < (n); j++)
      for (int i = (0); i < (n); i++) {
        if (!i)
          x[i][j] = f[cnt][i][j];
        else
          x[i][j] = x[i - 1][j] + f[cnt][i][j];
      }
    for (int j = (0); j < (n); j++)
      for (int i = (1); i < (n); i++) {
        x[i][j] += x[i - 1][j];
      }
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (n); j++) {
        if (!j)
          y[i][j] = f[cnt][i][j];
        else
          y[i][j] = y[i][j - 1] + f[cnt][i][j];
      }
    for (int i = (0); i < (n); i++)
      for (int j = (1); j < (n); j++) {
        y[i][j] += y[i][j - 1];
      }
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (i + 1); j++) {
        if (!j)
          z[i][j] = f[cnt][i][j];
        else
          z[i][j] = z[i - 1][j - 1] + f[cnt][i][j];
      }
    for (int i = (1); i < (n); i++)
      for (int j = (1); j < (i + 1); j++) {
        z[i][j] += z[i - 1][j - 1];
      }
    for (int i = (0); i < (n); i++)
      for (int j = (i + 1); j < (n); j++) {
        f[cnt ^ 1][i][j] = (j - 1 >= 0 ? x[j - 1][j] : 0) -
                           (j - i - 2 >= 0 ? x[j - i - 2][j] : 0) -
                           (i - 1 >= 0 ? x[i - 1][j] : 0);
        f[cnt ^ 1][i][j] += y[i][n - 1] - y[i][n - 1 + i - j] -
                            (j - 1 >= 0 ? y[i][j - 1] : 0) +
                            (i - 1 >= 0 ? y[i][i - 1] : 0);
        f[cnt ^ 1][i][j] +=
            z[n - 1][n - 1 + i - j] -
            (n - 1 - j - 1 >= 0 ? z[n - 1 - i - 1][n - 1 - j - 1] : 0) -
            (i - 1 >= 0 ? z[j - 1][i - 1] : 0);
        f[cnt ^ 1][i][j] += ((long double)(i + 1) * i / 2 +
                             (long double)(n - j - 1) * (n - j) / 2 +
                             (long double)(j - i - 1) * (j - i) / 2) *
                            f[cnt][i][j];
        f[cnt ^ 1][i][j] /= n * (n + 1) / 2;
      }
    cnt ^= 1;
  }
  long double ans = 0;
  for (int i = (0); i < (n); i++)
    for (int j = (i + 1); j < (n); j++) ans += f[cnt][i][j];
  cout << fixed << setprecision(12) << ans;
}
int main() {
  solve();
  return 0;
}
