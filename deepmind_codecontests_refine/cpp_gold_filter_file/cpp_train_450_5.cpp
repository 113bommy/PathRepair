#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const long long mod = (int)1e9 + 7;
const int N = 2e3 + 100;
int n, k;
int a[N], b[N];
int inv[N];
int c[N][N];
void init() {
  int MOD = mod;
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
  }
  c[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    c[i][0] = 1;
    int now = k + i - 1;
    for (int j = 1; j <= n; ++j) {
      c[i][j] = 1ll * c[i][j - 1] * now % mod * inv[j] % mod;
      --now;
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  init();
  if (k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        b[i] = (b[i] + 1ll * a[j] * c[i - j][i - j]) % mod;
      }
    }
    for (int i = 1; i <= n; ++i) a[i] = b[i];
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", a[i], " \n"[i == n]);
  }
  return 0;
}
