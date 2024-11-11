#include <bits/stdc++.h>
using namespace std;
template <long long MOD>
struct ModInt {
  int n;
  ModInt(const ModInt<MOD> &v) : n(v.n) {}
  ModInt() : n(0) {}
  ModInt(long long nn) {
    if (nn < -MOD || nn >= MOD) nn %= MOD;
    if (nn < 0) nn += MOD;
    n = nn;
  }
  ModInt<MOD> operator+(const ModInt<MOD> &M) const {
    int r = (n + M.n);
    if (r >= MOD) r -= MOD;
    return ModInt::safe(r);
  }
  ModInt<MOD> operator-(const ModInt<MOD> &M) const {
    int r = (n - M.n);
    if (r < 0) r += MOD;
    return ModInt::safe(r);
  }
  ModInt<MOD> operator*(const ModInt<MOD> &M) const {
    return ModInt::safe(((long long)n * M.n) % MOD);
  }
  ModInt<MOD> operator+=(const ModInt<MOD> &M) {
    return ModInt::safe(n = ((*this) + (M)).n);
  }
  ModInt<MOD> operator-=(const ModInt<MOD> &M) {
    return ModInt::safe(n = ((*this) - (M)).n);
  }
  long long solveLinear(long long a, long long b, long long m) const {
    if (b == 0 || b == m) return 0;
    if (a == 0) return -1;
    long long y = solveLinear(m % a, -b % a + a, a);
    return y < 0 ? y : (m * y + b) / a;
  }
  ModInt<MOD> operator/(const ModInt<MOD> &B) const {
    long long o_t(solveLinear(B.n, 1, MOD));
    return (*this) * ModInt(o_t);
  }
  ModInt<MOD> power(const ModInt<MOD - 1> &B) {
    if (B.n == 0) return 1;
    ModInt<MOD> sq = power(B.n / 2);
    sq = sq * sq;
    if (B.n & 1) sq = sq * (*this);
    return sq;
  }
  inline static ModInt<MOD> safe(long long n) {
    ModInt<MOD> m;
    m.n = n;
    return m;
  }
};
int memo[2][105][55][55];
int sumP = 0, sumN = 0;
int dp(bool isGood, int cw, int sp, int sn, int m) {
  if (m == 0) return cw;
  if (memo[isGood][cw][sp][sn] != -1) return memo[isGood][cw][sp][sn];
  ModInt<998244353> e(0);
  ModInt<998244353> curN(sumN - sn);
  ModInt<998244353> curP(sumP + sp);
  if (isGood) {
    if (curN.n > 0) {
      ModInt<998244353> P = curN / (curN + curP);
      e += P * dp(isGood, cw, sp, sn + 1, m - 1);
    }
    if (curP.n > cw) {
      ModInt<998244353> P = (curP - cw) / (curN + curP);
      e += P * dp(isGood, cw, sp + 1, sn, m - 1);
    }
    if (cw > 0) {
      ModInt<998244353> P = ModInt<998244353>(cw) / (curN + curP);
      e += P * dp(isGood, cw + 1, sp + 1, sn, m - 1);
    }
  } else {
    if (curP.n > 0) {
      ModInt<998244353> P = curP / (curN + curP);
      e += P * dp(isGood, cw, sp + 1, sn, m - 1);
    }
    if (curN.n > cw) {
      ModInt<998244353> P = (curN - cw) / (curN + curP);
      e += P * dp(isGood, cw, sp, sn + 1, m - 1);
    }
    if (cw > 0) {
      ModInt<998244353> P = ModInt<998244353>(cw) / (curN + curP);
      e += P * dp(isGood, cw - 1, sp, sn + 1, m - 1);
    }
  }
  return memo[isGood][cw][sp][sn] = e.n;
}
int main() {
  memset(memo, -1, sizeof(memo));
  int n, m;
  cin >> n >> m;
  vector<int> a(n), w(n);
  for (int &t : a) cin >> t;
  ModInt<998244353> ws;
  for (int &t : w) {
    cin >> t;
    ws += t;
  }
  for (int i = 0; i < n; i++) {
    if (a[i])
      sumP += w[i];
    else
      sumN += w[i];
  }
  for (int i = 0; i < n; i++) {
    cout << dp(a[i], w[i], 0, 0, m) << endl;
  }
}
