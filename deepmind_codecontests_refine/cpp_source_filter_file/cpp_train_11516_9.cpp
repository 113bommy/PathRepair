#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int fact[310], vaz[310], grup[310], d[310][310];
long long v[310];
int rid_put(int a, int b) {
  int sol = 1;
  for (int i = 1; i <= b; i <<= 1) {
    if (b & i) sol = (1LL * sol * a) % mod;
    a = (1LL * a * a) % mod;
  }
  return sol;
}
int comb(int n, int k) {
  if (n < 0 or k < 0 or k > n) return 1;
  return 1LL * fact[n] * rid_put((1LL * fact[n - k] * fact[k]) % mod, mod - 2) %
         mod;
}
int main() {
  int n, p = 0, l = -1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &v[i]);
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = (1LL * fact[i - 1] * i) % mod;
  for (int i = 1; i <= n; i++)
    if (vaz[i] == 0) {
      vaz[i] = 1;
      grup[++l] = 1;
      for (int j = i + 1; j <= n; j++) {
        long long p = sqrt(v[i] * v[j]);
        if (1LL * p * p == v[i] * v[j]) {
          grup[l]++;
          vaz[j] = 1;
        }
      }
    }
  int t = 0;
  l++;
  d[0][0] = 1;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j <= t; j++) {
      if (d[i][j] == 0) continue;
      for (int k = 1; k <= min(grup[i], t + 1); k++)
        for (int m = 0; m <= min(j, k); m++) {
          int c = 1LL * comb(grup[i] - 1, k - 1) * comb(j, m) % mod;
          c = 1LL * c * comb(t + 1 - j, k - m) % mod;
          c = 1LL * c * d[i][j] % mod;
          d[i + 1][j - m + grup[i] - k] =
              (d[i + 1][j - m + grup[i] - k] + c) % mod;
        }
    }
    t += grup[i];
  }
  int sol = d[l][0];
  for (int i = 0; i < l; i++) sol = 1LL * sol * fact[grup[i]] % mod;
  printf("%d", sol);
  return 0;
}
