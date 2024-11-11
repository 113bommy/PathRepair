#include <bits/stdc++.h>
using namespace std;
const int SZ = 8e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const long double eps = 1e-8;
long long read() {
  long long n = 0;
  char a = getchar();
  bool flag = 0;
  while (a > '9' || a < '0') {
    if (a == '-') flag = 1;
    a = getchar();
  }
  while (a <= '9' && a >= '0') {
    n = n * 10 + a - '0', a = getchar();
  }
  if (flag) n = -n;
  return n;
}
int a[SZ], f[1010][1010], b[SZ], c[SZ];
int main() {
  int n = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      b[++b[0]] = a[j] - a[i];
    }
  }
  sort(b + 1, b + 1 + b[0]);
  b[0] = unique(b + 1, b + 1 + b[0]) - b - 1;
  int ans = 0;
  for (int j = 1; j <= b[0]; j++) {
    int minx = b[j];
    if (minx > 1e5 / (k - 1)) break;
    for (int i = 1; i <= n; i++) f[i][1] = f[i - 1][1] + 1;
    for (int l = 2; l <= k; l++) {
      for (int i = 2, lst = 0; i <= n; i++) {
        while (lst < i && a[lst + 1] <= a[i] - minx) lst++;
        f[i][l] = f[lst][l - 1];
      }
      for (int i = 1; i <= n; i++) (f[i][l] += f[i - 1][l]) %= mod;
    }
    c[j] = f[n][k];
  }
  for (int j = 1; j <= b[0]; j++)
    (ans += 1ll * b[j] * (c[j] - c[j + 1] + mod) % mod) %= mod;
  printf("%d\n", ans);
}
