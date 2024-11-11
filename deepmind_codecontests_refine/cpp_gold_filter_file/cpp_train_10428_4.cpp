#include <bits/stdc++.h>
const int maxn = 1e3 + 23;
const int mod = 998244353;
using namespace std;
void read(int &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
int T, n, m, q, k;
long long f[maxn][maxn];
int a[maxn];
int main() {
  read(n);
  read(k);
  for (int i = 1; i <= n; i++) read(a[i]);
  sort(a + 1, a + n + 1);
  int inf = a[n] / (k - 1);
  long long ans = 0;
  for (int i = 1; i <= inf; i++) {
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= k; j++) f[i][j] = 0;
    for (int i = 1; i <= n; i++) f[i][0] = 1;
    f[0][0] = 1;
    f[1][0] = f[1][1] = 1;
    int j = 0, p = 1;
    for (j = 2; j <= n; j++) {
      for (; p <= j; p++) {
        if (a[j] - a[p] < i) {
          p--;
          break;
        }
      }
      p = max(p, 0);
      for (int l = 1; l <= min(k, j); l++) {
        f[j][l] = f[j - 1][l] + f[p][l - 1];
        f[j][l] %= mod;
      }
    }
    ans += f[n][k];
    ans %= mod;
  }
  printf("%lld", ans);
}
