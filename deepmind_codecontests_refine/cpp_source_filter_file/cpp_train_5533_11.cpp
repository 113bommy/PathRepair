#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int m, as;
inline int MOD(int x) { return x >= mod ? x - mod : x; }
int qpow(int a, int b) {
  a = (a % mod + mod) % mod;
  int as = 1;
  while (b) {
    if (b & 1) as = 1ll * as * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return as;
}
int vs[100005], pm[100005], tt, mu[100005];
void init() {
  mu[1] = 1;
  for (int i = (2); i <= (100000); ++i) {
    if (vs[i] == 0) pm[++tt] = i, mu[i] = mod - 1;
    for (int j = 1; j <= tt && pm[j] * i <= 100000; ++j) {
      vs[i * pm[j]] = 1;
      if (i % pm[j]) break;
      mu[i * pm[j]] = mod - mu[i];
    }
  }
}
int main() {
  init();
  scanf("%d", &m);
  int k = qpow(m, mod - 2);
  for (int i = (2); i <= (m); ++i)
    for (int j = (1); j <= (m / i); ++j) {
      as = (as +
            1ll * mu[j] *
                ((qpow(1 - 1ll * (m / i / j) * k % mod, mod - 2) - 1 + mod) %
                 mod) %
                mod) %
           mod;
    }
  cout << as + 1 << endl;
  return 0;
}
