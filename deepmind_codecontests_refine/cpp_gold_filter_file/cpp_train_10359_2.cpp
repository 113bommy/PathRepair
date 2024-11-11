#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vi = vector<int>;
mt19937 mrand(time(0));
ll get(ll r) { return ((ll)mrand() * mrand() % r + r) % r; }
ll get(ll l, ll r) { return get(r - l + 1) + l; }
const int N = 1e7 + 100, P = 1e9 + 7;
int n, pri[N], tot, pw2[500100], ans, c[N], lim, mu[N], s[N];
void init(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!pri[i]) pri[++tot] = i, mu[i] = -1;
    for (int j = 1; j <= tot && pri[j] * i <= n; j++) {
      pri[pri[j] * i] = 1;
      if (i % pri[j] == 0) {
        mu[i * pri[j]] = 0;
        break;
      }
      mu[i * pri[j]] = -mu[i];
    }
  }
}
signed main() {
  scanf("%d", &n);
  for (int i = 1, a; i <= n; i++) scanf("%d", &a), c[a]++, lim = max(lim, a);
  init(lim);
  for (int i = 1; i <= tot; i++)
    for (int j = lim / pri[i]; j; j--) c[j] += c[j * pri[i]];
  for (int i = 1; i <= lim; i++) mu[i] = mu[i] * c[i];
  for (int i = 1; i <= tot; i++)
    for (int j = 1; j * pri[i] <= lim; j++) (mu[j * pri[i]] += mu[j]) %= P;
  pw2[0] = 1;
  for (int i = 1; i <= 5e5; i++) pw2[i] = pw2[i - 1] * 2 % P;
  for (int i = 1; i <= lim; i++) s[i] = pw2[c[i]] - 1;
  for (int i = tot; i; i--)
    for (int j = 1; j * pri[i] <= lim; j++) (s[j] -= s[j * pri[i]]) %= P;
  for (int i = 2; i <= lim; i++) (ans += 1ll * s[i] * mu[i] % P) %= P;
  (ans += P) %= P;
  printf("%d\n", ans);
  fprintf(stderr, "time=%.4f\n", (db)clock() / CLOCKS_PER_SEC);
  return 0;
}
