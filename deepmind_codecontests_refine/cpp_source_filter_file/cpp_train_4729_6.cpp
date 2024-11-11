#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<long long, long long>;
void xmax(long long& a, long long b) { a = max(a, b); }
void xmin(long long& a, long long b) { a = min(a, b); }
void print(vc<long long>& a, string second) {
  cerr << "prinitng " << second << ": ";
  for (long long i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
long long mod = 1e9 + 7;
long long inv2 = 5e8 + 4;
vc<vc<long long> > bin(51, vc<long long>(51, -1));
long long binom(long long n, long long k) {
  if (k < 0) return 0;
  if (bin[n][k] != -1) return bin[n][k];
  if (k == 0) return 1;
  if (n == 0) return 0;
  return bin[n][k] = (binom(n - 1, k - 1) + binom(n - 1, k)) % mod;
}
vc<vc<vc<long long> > > dps(51, vc<vc<long long> >(51, vc<long long>(2)));
long long dp(long long n, long long k, long long w) {
  if (n < 0 || k < 0) return 0;
  return dps[n][k][w];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long nn, kk;
  cin >> nn >> kk;
  dps[1][0][0] = 1;
  dps[0][0][0] = 0;
  dps[0][0][1] = 1;
  long long e = 1;
  for (long long i = 2; i <= nn; i++) {
    long long n = i;
    for (long long k = 0; k <= kk; k++) {
      for (long long j = 0; j < i; j++) {
        for (long long k1 = 0; k1 <= k; k1++) {
          long long add1 =
              max(e, j) * max(e, i - 1 - j) *
              (binom(i - 1, j) *
               (dp(j, k1, 1) * dp(i - j - 1, k - k1, 1) % mod) % mod) %
              mod;
          long long add2 =
              max(e, j) *
              (max(e, i - 1 - j) *
               ((dp(j, k1 - 1, 0) * dp(i - j - 1, k - k1, 1)) % mod +
                (dp(j, k1 - 1, 1) * dp(i - j - 1, k - k1, 0)) % mod +
                (dp(j, k1 - 1, 0) * dp(i - j - 1, k - k1, 0)) % mod) %
               mod) %
              mod;
          long long f_add1 = add1 * inv2 % mod;
          long long f_add2 = inv2 * (binom(i - 1, j) * add2 % mod) % mod;
          dps[i][k][0] = (dps[i][k][0] + f_add1) % mod;
          dps[i][k][1] = (dps[i][k][1] + f_add2) % mod;
        }
      }
    }
  }
  cout << dps[nn][kk][1] + dps[nn][kk][0] << endl;
}
