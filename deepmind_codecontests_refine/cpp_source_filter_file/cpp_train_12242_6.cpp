#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 600000;
char s[N + 100], t[N + 100];
long long jc[N + 100], inv[N + 100], ans = 0, res = 0, mi[N + 100];
int vis[N + 100], mu[N + 100], pri[N + 100], n, ls, lt, a[2], b[2], c[2],
    tot = 0;
int gcd(int x, int y) { return (!y) ? x : gcd(y, x % y); }
long long ksm(long long x, int y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return res;
}
void ycl() {
  long long i, j;
  jc[0] = 1;
  for (i = 1; i <= N; i++) jc[i] = (jc[i - 1] * i) % mod;
  inv[N] = ksm(jc[N], mod - 2);
  for (i = N - 1; i; i--) inv[i] = (inv[i + 1] * (i + 1)) % mod;
  inv[0] = 1;
  mi[0] = 1;
  for (i = 1; i <= N; i++) mi[i] = (mi[i - 1] * (long long)2) % mod;
  mu[1] = 1;
  for (i = 2; i <= n; i++) {
    if (!vis[i]) {
      pri[++tot] = i;
      mu[i] = -1;
    }
    for (j = 1; ((i * pri[j] <= n) && (j <= tot)); j++) {
      vis[i * pri[j]] = 1;
      if (i % pri[j] == 0) {
        mu[i * pri[j]] = 0;
        break;
      }
      mu[i * pri[j]] = -mu[i];
    }
  }
  for (i = 1; i <= n; i++) {
    long long nw = 0;
    for (j = 1; j <= n / i; j++)
      nw = (nw +
            ((long long)mu[j] * (long long)(n / i / j) *
             (long long)(n / i / j)) %
                mod +
            mod) %
           mod;
    res = (res + ksm(2, i) * nw) % mod;
  }
}
long long C(int x, int y) {
  if ((x < y) || (x < 0)) return 0;
  return ((jc[x] * inv[y]) % mod * inv[x - y]) % mod;
}
int main() {
  int i, j, k, cnt = 0, da, db, d, l1, l2;
  bool fl;
  scanf("%s", s + 1);
  ls = strlen(s + 1);
  scanf("%s", t + 1);
  lt = strlen(t + 1);
  scanf("%d", &n);
  res = 0;
  ycl();
  for (i = 1; i <= ls; i++)
    if (s[i] == 'A')
      a[0]++;
    else if (s[i] == 'B')
      b[0]++;
    else
      c[0]++;
  for (i = 1; i <= lt; i++)
    if (t[i] == 'A')
      a[1]++;
    else if (t[i] == 'B')
      b[1]++;
    else
      c[1]++;
  if (ls == lt) {
    ans = (C(c[1] + c[0], c[0] + a[0] - a[1]) * res) % mod;
    fl = 1;
    cnt = 0;
    for (i = 1; i <= ls; i++)
      if ((s[i] != '?') && (t[i] != '?') && (s[i] != t[i])) {
        fl = 0;
        break;
      } else if ((s[i] == '?') && (t[i] == '?'))
        cnt++;
    if (fl) {
      ans = (ans - ((long long)mi[cnt] * res) % mod + mod) % mod;
      ans = (ans + ((long long)mi[cnt] * (mi[n + 1] - 2 + mod)) % mod *
                       (mi[n + 1] - 2 + mod)) %
            mod;
    }
  }
  for (i = a[0] - a[1] - c[1]; i <= a[0] - a[1] + c[0]; i++)
    if (i != 0) {
      da = i;
      db = lt - ls + da;
      if ((long long)da * (long long)db <= 0) continue;
      l1 = a[0];
      l2 = a[1];
      l2 += da;
      res = C(c[1] + c[0], c[0] + l1 - l2);
      if ((da < 0) && (db < 0)) da = -da, db = -db;
      d = gcd(da, db);
      da /= d;
      db /= d;
      if (db >= da)
        ans = (ans + (mi[n / db + 1] - 2 + mod) * res) % mod;
      else
        ans = (ans + (mi[n / da + 1] - 2 + mod) * res) % mod;
    }
  cout << ans << endl;
  return 0;
}
