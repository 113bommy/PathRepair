#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vll = vector<ll>;
using vs = vector<string>;
constexpr int N = 300001, MOD = 1000000007, S = 7;
ll mod_pow(ll a, ll b) {
  if (!b) return 1;
  return ((mod_pow(((a * a) % MOD), b / 2) * (b % 2 ? a : 1)) % MOD);
}
ll mod_inv(ll a) { return mod_pow(a, MOD - 2); }
int cnt[N], c[N], f[N];
int main() {
  for (auto i = (0); i < (N); i++) c[i] = i;
  int n;
  scanf("%d", &n);
  for (auto i = (0); i < (n); i++) {
    int x;
    scanf("%d", &x);
    cnt[x]++;
  }
  for (auto k = (1); k < (N); k++)
    for (int m = 2 * k; m < N; m += k) cnt[k] += cnt[m];
  int ans = -1;
  for (auto p = (1); p < (S + 1); p++) {
    for (int k = N - 1; k; k--) {
      f[k] = c[cnt[k]];
      for (int m = 2 * k; m < N; m += k) f[k] = ((f[k] - f[m] + MOD) % MOD);
    }
    if (f[1]) {
      ans = p;
      break;
    }
    int q = mod_inv(p + 1);
    for (auto k = (1); k < (N); k++)
      c[k] = ((c[k] * (((ll)(k - p) * q) % MOD)) % MOD);
  }
  printf("%d\n", ans);
  return 0;
}
