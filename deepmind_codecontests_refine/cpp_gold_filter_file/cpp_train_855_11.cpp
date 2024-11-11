#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, maxn = 2e5 + 5;
int fact[maxn], ifact[maxn];
int N, K;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}
int power(int a, int b) {
  if (b == 0) return 1;
  int res = power(a, b / 2);
  if (b & 1) return 1ll * res * res % mod * a % mod;
  return 1ll * res * res % mod;
}
int C(int k, int n) {
  if (k > n) return 0;
  return 1ll * fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}
int euler(int k, int n) { return C(n - 1, k - 1); }
void prep(void) {
  fact[0] = 1;
  for (int i = 1; i < maxn; ++i) fact[i] = 1ll * i * fact[i - 1] % mod;
  ifact[maxn - 1] = power(fact[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; --i)
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  prep();
  cin >> N >> K;
  if (K > N - 1) {
    cout << 0;
    return 0;
  }
  int c = N - K;
  int res = 0;
  for (int i = 0; i <= c; ++i) {
    int way = 1ll * C(c, N) * C(i, c) % mod * power(i, N) % mod;
    if (i % 2 == c % 2) {
      add(res, way);
    } else {
      add(res, -way);
    }
  }
  if (K > 0) res = 2ll * res % mod;
  cout << res;
}
