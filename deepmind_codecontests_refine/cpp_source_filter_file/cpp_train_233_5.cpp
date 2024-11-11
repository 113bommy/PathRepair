#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int oo = 1e9;
template <typename num>
inline num ceil(num a, num b) {
  return (a + b - 1) / b;
}
template <typename num>
inline num lcm(num a, num b) {
  return a * (b / __gcd(a, b));
}
template <typename num>
inline num sum(num x) {
  return x * (x + 1) / 2;
}
long long binpow(long long b, long long e) {
  long long res = 1;
  while (e)
    if (e & 1)
      res = (res * b % MOD), --e;
    else
      b = (b * b % MOD), e >>= 1;
  return res;
}
const int MAXN = 3e5 + 5;
long long fac[MAXN];
inline long long inv(long long n) { return binpow(n, MOD - 2); }
inline long long C(long long n, long long k) {
  if (n < k) return 0;
  return fac[n] * inv(fac[k]) % MOD * inv(fac[n - k]) % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fac[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
  int t = 1;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > a;
    for (int i = 0, l, r; i < n; ++i) {
      cin >> l >> r;
      a.push_back({l, 1});
      a.push_back({r + 1, 0});
    }
    sort(begin(a), end(a));
    long long cnt = 0, ans = 0;
    for (int i = 0; i < (int)(a).size(); ++i) {
      int s = a[i].second;
      if (s) {
        ans = (ans + C(cnt, k - 1));
        cnt++;
      } else {
        cnt--;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
