#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200005;
const int mod = 1e9 + 7;
ll fexp(ll b, ll e = mod - 2) {
  ll ans = 1;
  while (e) {
    if (e & 1) ans = ans * b % mod;
    b = b * b % mod;
    e /= 2;
  }
  return ans;
}
ll fat[N], ifat[N];
ll C(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fat[n] * ifat[k] % mod * ifat[n - k] % mod;
}
int n;
ll T, t[N], p[N];
ll val = 1;
ll L = 0, R = 0;
ll vn = 0;
void addN() {
  val = (2 * val + C(vn, L - 1) - C(vn, R) + mod) % mod;
  vn++;
}
void fix(ll nR) {
  while (R < nR) {
    R++;
    val += C(vn, R);
    if (val >= mod) val -= mod;
  }
  while (R > nR) {
    val -= C(vn, R);
    if (val < 0) val += mod;
    R--;
  }
}
int main() {
  fat[0] = ifat[0] = 1;
  for (int i = 1; i < N; i++) {
    fat[i] = i * fat[i - 1] % mod;
    ifat[i] = fexp(fat[i]);
  }
  scanf("%d %lld", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%lld", t + i);
  partial_sum(t, t + n + 1, p);
  t[n + 1] = 2 * T;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    addN();
    ll mxAdd = T - p[i];
    if (mxAdd < 0) break;
    if (mxAdd > i) mxAdd = i;
    fix(mxAdd);
    ans = (ans + val * fexp(fexp(2, i))) % mod;
  }
  printf("%lld\n", ans);
}
