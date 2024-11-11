#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
int mul(int a, int b) { return (long long)a * b % MOD; }
int qpow(int a, int p) {
  int ans = 1;
  while (p) {
    if (p & 1) ans = mul(ans, a);
    a = mul(a, a);
    p >>= 1;
  }
  return ans;
}
int inv(int a) { return qpow(a, MOD - 2); }
int divv(int a, int b) { return mul(a, inv(b)); }
const int MAXN = 2009;
int fact[MAXN], invFact[MAXN], pow2[MAXN], N, k, l;
int nCk(int a, int b) { return mul(fact[a], mul(invFact[a - b], invFact[b])); }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for (int i = 1; i <= MAXN - 1; ++i) fact[i] = mul(fact[i - 1], i);
  invFact[MAXN - 1] = inv(fact[MAXN - 1]);
  for (int i = MAXN - 1; i >= 1; --i) invFact[i - 1] = mul(invFact[i], i);
  pow2[0] = 1;
  for (int i = 1; i <= MAXN - 1; ++i) pow2[i] = mul(pow2[i - 1], 2);
  cin >> N >> k >> l;
  int ans = 0;
  for (int i = 0; i <= 2 * N; ++i)
    for (int j = i; j >= k; j -= 2) {
      if (i + j > 2 * N) continue;
      int x = 1;
      x = mul(x, nCk(i, j));
      x = mul(x, nCk(2 * N - i, j));
      x = mul(x, fact[i - j]);
      x = mul(x, fact[2 * N - j - i]);
      x = mul(x, fact[j]);
      x = mul(x, pow2[j]);
      x = mul(x, invFact[(i - j) / 2]);
      x = mul(x, invFact[(2 * N - j - i) / 2]);
      ans = add(ans, x);
    }
  ans = mul(ans, fact[N]);
  ans = divv(ans, fact[2 * N]);
  ans = divv(ans, 2 * N + 1);
  ans = mul(ans, l % MOD);
  cout << ans << endl;
  return 0;
}
