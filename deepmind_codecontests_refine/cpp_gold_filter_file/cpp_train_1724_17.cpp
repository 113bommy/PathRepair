#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, MAXN = 256, inv2 = MOD + 1 >> 1,
                inv5 = 400000003;
inline long long fpow(long long a, long long x) {
  long long ans = 1;
  for (a %= MOD; x; x >>= 1, a = a * a % MOD)
    if (x & 1) ans = ans * a % MOD;
  return ans;
}
inline long long inv(long long a) { return fpow(a, MOD - 2); }
pair<long long, long long> operator+(const pair<long long, long long> &a,
                                     const pair<long long, long long> &b) {
  return pair<long long, long long>((a.first + b.first) % MOD,
                                    (a.second + b.second) % MOD);
}
pair<long long, long long> operator-(const pair<long long, long long> &a,
                                     const pair<long long, long long> &b) {
  return pair<long long, long long>((a.first - b.first + MOD) % MOD,
                                    (a.second - b.second + MOD) % MOD);
}
pair<long long, long long> operator*(const pair<long long, long long> &a,
                                     const pair<long long, long long> &b) {
  return pair<long long, long long>(
      (a.first * b.first % MOD + a.second * b.second % MOD * 5ll % MOD) % MOD,
      (a.first * b.second % MOD + a.second * b.first % MOD) % MOD);
}
pair<long long, long long> operator*(const pair<long long, long long> &a,
                                     const long long &b) {
  return pair<long long, long long>(a.first * b % MOD, a.second * b % MOD);
}
pair<long long, long long> operator~(const pair<long long, long long> &p) {
  return pair<long long, long long>(p.first, MOD - p.second) *
         inv((p.first * p.first % MOD - p.second * p.second % MOD * 5ll % MOD +
              MOD) %
             MOD);
}
pair<long long, long long> operator/(const pair<long long, long long> &a,
                                     const pair<long long, long long> &b) {
  return a * (~b);
}
inline pair<long long, long long> fpow(pair<long long, long long> a,
                                       long long x) {
  pair<long long, long long> ans(1, 0);
  for (; x; x >>= 1, a = a * a)
    if (x & 1) ans = ans * a;
  return ans;
}
long long K, L, R, S1[MAXN][MAXN], C[MAXN][MAXN], Frac[MAXN];
inline void pre() {
  C[0][0] = Frac[0] = 1;
  for (int i = 1; i <= 200; ++i) {
    Frac[i] = Frac[i - 1] * i % MOD;
    S1[i][i] = C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++j)
      S1[i][j] = (S1[i - 1][j - 1] + (i - 1ll) * S1[i - 1][j] % MOD) % MOD,
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
}
inline pair<long long, long long> sumq(pair<long long, long long> a,
                                       long long l, long long r) {
  static pair<long long, long long> one = pair<long long, long long>(1, 0);
  if (a == one) return pair<long long, long long>((r - l + 1) % MOD, 0);
  return (fpow(a, r + 1) - fpow(a, l)) / (a - one);
}
int main() {
  pre();
  cin >> K >> L >> R;
  long long ans = 0;
  L += 2;
  R += 2;
  pair<long long, long long> a(0ll, inv5), b(0ll, -inv5), x(inv2, inv2),
      y(inv2, -inv2);
  for (int i = 0; i <= K; ++i) {
    long long res = 0;
    for (int j = 0; j <= i; ++j)
      res += (sumq(fpow(x, j) * fpow(y, i - j), L, R) * fpow(a, j) *
              fpow(b, i - j))
                 .first *
             C[i][j] % MOD;
    ans = (ans + MOD + res % MOD * S1[K][i] * fpow(-1, K - i) % MOD) % MOD;
  }
  ans = ans % MOD * inv(Frac[K]) % MOD + MOD;
  cout << ans % MOD;
  return 0;
}
