#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int UNDEF = -1;
const long long INF = 1e18;
template <typename T>
inline bool chkmax(T &aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T &aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
const int mn = 1e6 + 4;
const int MAXFACT = mn;
int fact[MAXFACT + 1], invfact[MAXFACT + 1];
int mod_pow(int a, int n) {
  const int mod = MOD;
  int ret = 1;
  int p = a % mod;
  while (n) {
    if (n & 1) ret = (ret * (long long)p) % mod;
    p = (p * (long long)p) % mod;
    n >>= 1;
  }
  return ret;
}
inline int mod_inv(int a) { return mod_pow(a, MOD - 2); }
inline int add(int a, int b) {
  int res = a + b;
  if (res >= MOD) res -= MOD;
  return res;
}
inline int mul(int a, int b) { return (a * (long long)b) % MOD; }
int fast_max(vector<int> a, int k) {
  int n = a.size();
  int ans = 0;
  int offset = 0;
  for (int i = 0; i < n; ++i)
    if (ans < a[i]) {
      ans = a[i];
      offset = 0;
    } else {
      offset = offset + 1;
      if (offset == k) return ans;
    }
  return ans;
}
bool isgood(vector<int> a, int k) {
  int n = a.size();
  int ans = 0;
  int offset = 0;
  for (int i = 0; i < n; ++i)
    if (ans < a[i]) {
      ans = a[i];
      offset = 0;
    } else {
      offset = offset + 1;
      if (offset == k) return false;
    }
  return true;
}
int bf(int n, int k) {
  vector<int> v;
  for (int x = 1; x <= n; x++) v.push_back(x);
  int ans = 0;
  do {
    if (isgood(v, k)) ans++;
  } while (next_permutation(v.begin(), v.end()));
  return ans;
}
int g0[mn];
int g1[mn];
int g[mn];
int makeg(int lim, int k) {
  for (int n = 0; n <= lim; n++) {
    int gn;
    if (n == 0)
      gn = 1;
    else {
      int sum0 = 0;
      int sum1 = (n - k - 1 >= 0) ? g1[n - k - 1] : 0;
      int sum2 = add(sum0, sum1);
      int sum3 = 1 + (MOD - sum2);
      gn = mul(fact[n], sum3);
    }
    g[n] = gn;
    if (n >= 1)
      g0[n] =
          add(n > 0 ? g0[n - 1] : 0, mul(gn, mod_inv(mul(n + k, fact[n - 1]))));
    g1[n] =
        add(n > 0 ? g1[n - 1] : 0, mul(gn, mod_inv(mul(n + k + 1, fact[n]))));
  }
  return g[lim];
}
void init() {
  int got = 1;
  for (int x = 0; x <= MAXFACT; x++) {
    fact[x] = got;
    got = mul(got, x + 1);
  }
  got = mod_pow(got, MOD - 2);
  for (int x = MAXFACT; x >= 0; x--) {
    got = mul(got, x + 1);
    invfact[x] = got;
  }
}
int binom(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return mul(fact[n], mul(invfact[k], invfact[n - k]));
}
int solve(int n, int k) {
  makeg(n, k);
  int final = 0;
  for (int x = 0; x <= n - (x + k + 1); x++) {
    int ans = mul(mul(binom(n - 1, x + k + 1), binom(x + k, x)), g[x]);
    int ans2 = mul(ans, mul(fact[k], fact[n - (x + k + 1)]));
    final += ans2;
    if (final >= MOD) final -= MOD;
  }
  return final;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  init();
  int n, k;
  scanf("%d%d", &n, &k);
  int ans = solve(n, k);
  printf("%d\n", ans);
}
