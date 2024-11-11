#include <bits/stdc++.h>
using namespace std;
const int N = 300005, P = 1000000007;
int n, a[N];
using ll = long long;
ll qpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return ret;
}
int pr[N], ptr, g[N], id[N];
bool npr[N];
ll fac[N], ifac[N], C[N];
int cnt[N][20];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i < N; i++) {
    if (!npr[i]) pr[++ptr] = i, g[i] = i, id[i] = ptr;
    for (int j = 1; j <= ptr && i * pr[j] <= n; j++) {
      npr[i * pr[j]] = 1;
      g[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
  ifac[n] = qpow(fac[n], P - 2);
  for (int i = n; i > 0; --i) ifac[i - 1] = ifac[i] * i % P;
  for (int i = 0; i <= n; i++) C[i] = fac[n] * ifac[i] % P * ifac[n - i] % P;
  for (int i = 1; i <= n; i++) C[i] = (C[i - 1] + C[i]) % P;
  for (int i = 1; i <= n; i++) C[i] = (C[i - 1] + C[i]) % P;
  for (int i = 1; i <= n; i++) {
    while (a[i] > 1) {
      int c = 0, v = g[a[i]];
      while (a[i] % v == 0) ++c, a[i] /= v;
      ++cnt[id[v]][c];
    }
  }
  ll ans = 0, sum = qpow(2, n - 1);
  for (int i = 1; i <= ptr; i++) {
    int cur = n;
    for (int j = 1; j < 20; j++) cur -= cnt[i][j];
    for (int j = 1; j < 20; j++) {
      if (!cnt[i][j]) continue;
      int l = cur, r = cur + cnt[i][j] - 1;
      cur += cnt[i][j];
      ll val = (C[r] - (l ? C[l - 1] : 0) + P) % P;
      val = (val - sum * cnt[i][j] % P + P) % P;
      ans = (ans + val * j) % P;
    }
  }
  cout << ans << endl;
  return 0;
}
