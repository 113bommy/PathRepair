#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 500005;
ll n;
ll phi[10005][105];
int ptr, pr[N], pi[N];
bool npr[N];
ll calc_phi(ll a, ll b) {
  if (!b) return a;
  if (pr[b] >= a) return 1;
  if (a <= 10000 && b <= 100) return phi[a][b];
  return calc_phi(a, b - 1) - calc_phi(a / pr[b], b - 1);
}
ll calc_pi(ll x) {
  if (x < N) return pi[x];
  int y = int(cbrt(x)) + 1, n = pi[y];
  ll ret = calc_phi(x, n) + n - 1;
  for (int i = n; pr[i] * 1ll * pr[i] <= x; i++)
    ret -= calc_pi(x / pr[i]) - calc_pi(pr[i]) + 1;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  for (int i = 2; i < N; i++) {
    pi[i] = pi[i - 1];
    if (!npr[i]) pr[++ptr] = i, ++pi[i];
    for (int j = 1; j <= ptr && i * pr[j] < N; j++) {
      npr[i * pr[j]] = 1;
      if (i % pr[j] == 0) break;
    }
  }
  for (int i = 1; i <= 10000; i++) {
    phi[i][0] = i;
    for (int j = 1; j <= 100; j++)
      phi[i][j] = phi[i][j - 1] - phi[i / pr[j]][j - 1];
  }
  cin >> n;
  ll ans = calc_pi(cbrt(n));
  for (int i = 1; i <= ptr && pr[i] * 1ll * pr[i] < n; i++)
    ans += calc_pi(n / pr[i]) - calc_pi(pr[i]);
  cout << ans << endl;
  return 0;
}
