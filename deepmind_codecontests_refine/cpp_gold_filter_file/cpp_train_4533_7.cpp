#include <bits/stdc++.h>
using namespace std;
const int N = 21;
const int MOD = 1e9 + 7;
void fwt(int f[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < (1 << n); j++) {
      if (j & (1 << i)) continue;
      int u = f[j], v = f[j | (1 << i)];
      f[j] = (u + v) % MOD, f[j | (1 << i)] = (u - v + MOD) % MOD;
    }
}
int pow_mod(int x, int nn, int M) {
  long long res = 1;
  while (nn) {
    if (nn & 1) res = res * x % M;
    nn >>= 1;
    x = 1ll * x * x % M;
  }
  return (int)res;
}
char ch[1010000];
int a[1010000];
int n, m;
int g[1 << N], f[1 << N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", ch);
    for (int s = 0; s < m; ++s) a[s] |= ((ch[s] - '0') << i);
  }
  for (int i = 0; i < m; ++i) {
    f[a[i]]++;
  }
  for (int i = 0; i < (1 << n); ++i) {
    int one_num = __builtin_popcount(i);
    g[i] = min(n - one_num, one_num);
  }
  fwt(f, n);
  fwt(g, n);
  for (int i = 0; i < (1 << n); ++i) {
    f[i] = 1ll * f[i] * g[i] % MOD;
  }
  fwt(f, n);
  long long ans = n * m, tmp = pow_mod(1 << n, MOD - 2, MOD);
  for (int i = 0; i < (1 << n); ++i) {
    ans = min(ans, 1ll * f[i] * tmp % MOD);
  }
  int aans = ans;
  printf("%d\n", aans);
}
