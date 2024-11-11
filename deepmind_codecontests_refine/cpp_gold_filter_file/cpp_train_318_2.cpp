#include <bits/stdc++.h>
using namespace std;
int getint() {
  int ans = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * f;
}
const int N = 310;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
long long a[N], b[N], c[N];
long long sa[N], sb[N], sc[N];
long long f[N][N][2], g[N][N][2];
inline void Min(long long &a, long long b) { (b < a ? a = b : 0); }
int main() {
  int n = getint(), t = getint(), k = getint();
  for (int i = 1; i <= n; i++) {
    a[i] = getint();
    b[i] = getint();
    c[i] = getint();
    sa[i] = sa[i - 1] + a[i];
    sb[i] = sb[i - 1] + b[i];
    sc[i] = sc[i - 1] + c[i];
  }
  n++;
  a[n] = inf, b[n] = 0, c[n] = inf;
  sa[n] = sa[n - 1] + a[n];
  sb[n] = sb[n - 1] + b[n];
  sc[n] = sc[n - 1] + c[n];
  memset(f, 0x3f, sizeof(f));
  memset(g, 0x3f, sizeof(g));
  memset(f[0], 0, sizeof(f[0]));
  memset(g[0], 0, sizeof(g[0]));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= t; j++) {
      for (int z = 0; z <= 1; z++) {
        if (f[i - 1][j][z] < inf && a[i] * z + b[i] * j <= c[i]) {
          Min(f[i][j][z], f[i - 1][j][z]);
          long long val = (z * sa[i - 1] + j * sb[i] + k - 1) / k;
          if (val * k <= z * sa[i] + j * sb[i]) {
            Min(g[i][j][z], val);
          }
        }
        for (int r = 0; r < j; r++) {
          if (g[i][r][z] >= inf) continue;
          long long rem = z * sa[i] + r * sb[i] - k * g[i][r][z];
          long long x = (max(0ll, rem + (j - r) * b[i] - c[i]) + k - 1) / k;
          if (x * k > rem) continue;
          if (f[i - 1][j - r][0] >= inf) continue;
          Min(f[i][j][z], g[i][r][z] + x + f[i - 1][j - r][0]);
          long long val = ((j - r) * sb[i - 1] + k - 1) / k;
          if (val * k > (j - r) * sb[i] + rem - x * k) continue;
          Min(g[i][j][z], g[i][r][z] + x + val);
        }
      }
    }
  }
  cout << f[n][t][1];
  return 0;
}
