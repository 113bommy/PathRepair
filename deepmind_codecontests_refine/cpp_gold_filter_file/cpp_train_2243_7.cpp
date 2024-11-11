#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &a, U b) {
  a = (a > b ? b : a);
}
template <typename T, typename U>
inline void amax(T &a, U b) {
  a = (a > b ? a : b);
}
const int N = 1e6 + 5, mod = 1e6 + 3;
int64_t fac[N], inv[N];
long long int expo(long long int n, long long int p, long long int M) {
  long long int res = 1;
  while (p) {
    if (p & 1) res = (res * n) % M;
    n = (n * n) % M;
    p >>= 1;
  }
  return res;
}
void pre() {
  fac[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= mod;
    inv[i] = expo(fac[i], mod - 2, mod);
  }
}
int64_t nck(int n, int k) {
  if (k > n) return 0;
  return (fac[n] * inv[n - k] % mod * inv[k] % mod);
}
void solve() {
  pre();
  int n, c;
  cin >> n >> c;
  int64_t ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += nck(i + c - 1, c - 1);
    ans %= mod;
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tests = 1;
  while (tests--) {
    solve();
  }
}
