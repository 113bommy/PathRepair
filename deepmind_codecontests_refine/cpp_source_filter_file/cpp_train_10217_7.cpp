#include <bits/stdc++.h>
using namespace std;
const long long mod = 100000007LL;
const long long MXSZ = 1000000LL;
long long fpow(long long b, long long e) {
  long long ret = 1;
  while (e > 0) {
    if (e & 1) (ret *= b) %= mod;
    (b *= b) %= mod;
    e >>= 1;
  }
  return ret;
}
long long fac[MXSZ + 5];
void prec() {
  fac[0] = 1;
  for (long long i = 1; i <= MXSZ; i++) {
    fac[i] = fac[i - 1] * i;
    fac[i] %= mod;
  }
}
long long inv(long long u) { return fpow(fac[u], mod - 2); }
inline long long comb(long long n, long long k) {
  long long ret = fac[n];
  (ret *= inv(k)) %= mod;
  (ret *= inv(n - k)) %= mod;
  return ret;
}
inline long long perm(long long n, long long k) {
  long long ret = fac[n];
  (ret *= inv(n - k)) %= mod;
  return ret;
}
long long n, m, a, b;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  prec();
  cin >> n >> m >> a >> b;
  long long tot = 0LL;
  for (int btwn = 0; btwn < n - 2; btwn++) {
    if (m < btwn + 1) break;
    long long vleft = n - btwn - 2;
    long long k = btwn + 2;
    long long curr = comb(m - 1, btwn) * perm(n - 2, btwn);
    curr %= mod;
    curr *= k;
    curr %= mod;
    curr *= fpow(n, n - k - 1);
    curr %= mod;
    curr *= fpow(m, vleft);
    curr %= mod;
    tot += curr;
    tot %= mod;
  }
  if (m - 1 >= n - 2) {
    long long curr = comb(m - 1, n - 2) * perm(n - 2, n - 2);
    curr %= mod;
    tot += curr;
    tot %= mod;
  }
  cout << tot << '\n';
  return 0;
}
