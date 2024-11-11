#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const int M = 1e6;
const long long base = 998244353;
const int digit = 9;
const long long mod = 998244353;
long long p, s, r;
vector<long long> gt({1}), dv({1});
long long mu(long long a, long long b) {
  if (b == 0) return 1;
  long long d = mu(a, b / 2);
  d = (d * d) % mod;
  if (b % 2) d = (d * a) % mod;
  return d;
}
long long inv(long long q) { return mu(q, mod - 2); }
long long C(long long n, long long k) {
  return ((gt[n] * dv[k] % base) * dv[n - k]) % base;
}
long long star(long long n, long long k) { return C(n + k - 1, k - 1); }
long long cntgame(long long n, long long k, long long x) {
  if (k == 0) return (n == 0);
  long long ans = 0;
  for (int i = 0; i <= k; i++) {
    long long t = n - x * i;
    if (t < 0) break;
    if (i % 2)
      ans = (ans - C(k, i) * star(t, k)) % base;
    else
      ans = (ans + C(k, i) * star(t, k)) % base;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> p >> s >> r;
  for (int i = 1; i <= 5005; i++) {
    gt.push_back((gt[i - 1] * i) % base);
    dv.push_back(inv(gt[i]));
  }
  long long sz = cntgame(s - r, p, 1e18);
  sz = inv(sz);
  long long res = 0;
  for (int q = r; q <= s; q++) {
    for (int i = 0; i < p; i++) {
      long long t = s - (i + 1) * q;
      if (t < 0) break;
      res =
          (res + (((C(p - 1, i) * cntgame(t, p - 1 - i, q)) % mod) * sz % mod) *
                     inv(i + 1)) %
          mod;
    }
  }
  cout << res;
  return 0;
}
