#include <bits/stdc++.h>
using namespace std;
const int MAX_K = 205;
const int MOD = 1000000007;
long long fpow(long long a, long long b) {
  long long r = 1;
  for (; b; b /= 2, a = (a * a) % MOD)
    if (b & 1) r = (r * a) % MOD;
  return r;
}
const int INV2 = fpow(2, MOD - 2);
const int INV5 = fpow(5, MOD - 2);
struct ExtInt {
  int a, b;
  ExtInt operator*=(ExtInt o) {
    tie(a, b) = make_pair((a * 1LL * o.a + 5LL * b * o.b) % MOD,
                          (a * 1LL * o.b + b * 1LL * o.a) % MOD);
    return *this;
  }
  ExtInt pow(long long p) {
    ExtInt a = *this, r = {1, 0};
    for (; p; p /= 2, a *= a)
      if (p & 1) r *= a;
    return r;
  }
  friend ExtInt operator+(ExtInt a, ExtInt b) {
    return {(a.a + b.a) % MOD, (a.b + b.b) % MOD};
  }
  void neg() {
    a = MOD - a;
    b = MOD - b;
  }
  friend ExtInt operator/(ExtInt a, ExtInt b) {
    ExtInt bt = b, tp = a;
    bt.b = MOD - b.b;
    tp *= bt;
    bt *= b;
    tp *= {(int)fpow(bt.a, MOD - 2), 0};
    return tp;
  }
};
ExtInt phi = {INV2, INV2}, psi = {INV2, (int)(((-1 + MOD) * 1LL * INV2) % MOD)};
int K;
int stir[MAX_K][MAX_K], c[MAX_K], bnk[MAX_K][MAX_K];
void init_c() {
  stir[0][0] = 1;
  for (int n = 1; n <= K; n++)
    for (int k = 1; k <= K; k++)
      stir[n][k] = (stir[n - 1][k - 1] + (n - 1) * 1LL * stir[n - 1][k]) % MOD;
  long long fac = 1;
  for (int i = 1; i <= K; i++) fac = (fac * i) % MOD;
  fac = fpow(fac, MOD - 2);
  for (int i = 0; i <= K; i++) {
    int h = stir[K][i];
    if ((K - i) & 1) h = MOD - h;
    c[i] = (h * fac) % MOD;
  }
}
ExtInt h(long long r, ExtInt b) {
  if (b.a == 1 && b.b == 0) return {int((r + 1) % MOD), 0};
  ExtInt tp = b.pow(2);
  tp.neg();
  tp = tp + b.pow(r + 3);
  ExtInt bt = {MOD - 1, 0};
  bt = bt + b;
  return tp / bt;
}
long long g(long long r, int m) {
  ExtInt ans = {0, 0};
  for (int k = 0; k <= m; k++) {
    int x = bnk[m][k];
    if ((m - k) & 1) x = MOD - x;
    ExtInt ex = {x, 0};
    ExtInt base = phi.pow(k);
    base *= psi.pow(m - k);
    ex *= h(r, base);
    ans = ans + ex;
  }
  ans *= ((ExtInt){0, INV5}).pow(m);
  return ans.a;
}
long long f(long long r) {
  long long ans = 0;
  for (int i = 0; i <= K; i++) ans = (ans + g(r, i) * c[i]) % MOD;
  return ans;
}
int main() {
  long long l, r;
  scanf("%d %lld %lld", &K, &l, &r);
  for (int n = 0; n <= K; n++) {
    bnk[n][0] = 1;
    for (int k = 1; k <= n; k++)
      bnk[n][k] = (bnk[n - 1][k] + bnk[n - 1][k - 1]) % MOD;
  }
  init_c();
  printf("%lld\n", (f(r) - f(l - 1) + MOD) % MOD);
  return 0;
}
