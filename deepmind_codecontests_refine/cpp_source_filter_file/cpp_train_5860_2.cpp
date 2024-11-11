#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long INF = 1e18;
const long long NEG_INF = -1 * (1e18);
using namespace std;
void usaco(string prob) {
  freopen((prob + ".in").c_str(), "r", stdin);
  freopen((prob + ".out").c_str(), "w", stdout);
}
bool prime(int n) {
  if (n < 2) return false;
  for (int x = 2; x * x <= n; x++) {
    if (n % x == 0) return false;
  }
  return true;
}
vector<int> getFactors(int n) {
  vector<int> f;
  for (int x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.push_back(x);
      n /= x;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
const long long MOD = 1e9 + 7;
vector<long long> fact(1005, 1), inv(1005, 1);
long long binPow(long long x, long long n) {
  int res = 1;
  while (n) {
    if (n & 1) res = (1LL * res * x) % MOD;
    x = (1LL * x * x) % MOD;
    n >>= 1;
  }
  return res;
}
void binSearch(long long n, long long pos, long long &cntBig,
               long long &cntLess) {
  long long l = 0, r = n;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (mid > pos) {
      cntBig++;
      r = mid;
    } else {
      if (mid != pos) {
        cntLess++;
      }
      l = mid + 1;
    }
  }
}
long long C(long long n, long long k) {
  if (k > n) {
    return 0;
  }
  long long mult = (fact[n] * inv[k]) % MOD;
  mult = (mult * inv[n - k]);
  return mult;
}
void solve() {
  long long n, x, pos;
  cin >> n >> x >> pos;
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = (binPow(fact[i], MOD - 2LL)) % MOD;
  }
  long long cntBig = 0, cntLess = 0;
  binSearch(n, pos, cntBig, cntLess);
  long long hasLess = 0, hasBig = 0;
  hasLess = x - 1;
  hasBig = n - x;
  long long rem = n - cntBig - cntLess - 1;
  long long ans = 1;
  long long cBig = C(hasBig, cntBig);
  long long cLess = C(hasLess, cntLess);
  cBig = (cBig * fact[cntBig]) % MOD;
  cLess = (cLess * fact[cntLess]) % MOD;
  ans = (ans * cBig) % MOD;
  ans = (ans * cLess) % MOD;
  ans = (ans * fact[rem]) % MOD;
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long TC = 1;
  for (long long tt = 1; tt <= (long long)(TC); ++tt) {
    solve();
  }
  return 0;
}
