#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 3;
const int MOD = (int)998244353;
int add(int a, int b) {
  int c = a + b;
  if (c >= MOD) c -= MOD;
  if (c < 0) c += MOD;
  return c;
}
int mul(int a, int b) {
  int c = 1LL * a * b % MOD;
  return c;
}
int pwr(int a, int b) {
  if (!b) return 1;
  int res = pwr(a, b >> 1);
  res = mul(res, res);
  if (b & 1) res = mul(res, a);
  return res;
}
int inv(int p) { return pwr(p, MOD - 2); }
int fact[MAXN], invfact[MAXN], n;
int C(int n, int k) {
  int ans = fact[n];
  ans = mul(ans, invfact[k]);
  ans = mul(ans, invfact[n - k]);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  long long h, w;
  cin >> h >> w;
  cout << pwr(2, h + w);
  return 0;
}
