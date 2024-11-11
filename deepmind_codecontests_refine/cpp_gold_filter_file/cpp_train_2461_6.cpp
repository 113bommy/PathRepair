#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 702;
const int mod = 1e9 + 7;
int dn, d[N], one[N];
void INIT() {
  for (int i = 0; i < dn; i++) one[i + 1] = (10ll * one[i] + 1) % mod;
}
int f[N][N][2];
int dp(int t, int w, int p, int ava) {
  if (!~w) return one[p];
  if (~f[w][p][ava]) return f[w][p][ava];
  int up = ava ? 9 : d[w], res = 0;
  for (int i = 0; i <= up; i++) {
    if (i >= t)
      (res += dp(t, w - 1, p + 1, ava || i < up)) %= mod;
    else
      (res += dp(t, w - 1, p, ava || i < up)) %= mod;
  }
  return f[w][p][ava] = res;
}
int p[11];
int DP() {
  int res = 0;
  for (int t = 1; t <= 9; t++) {
    memset(f, -1, sizeof f);
    for (int i = 1; i < dn; i++)
      for (int j = 1; j <= 9; j++) {
        if (j >= t)
          (p[t] += dp(t, i - 2, 1, true)) %= mod;
        else
          (p[t] += dp(t, i - 2, 0, true)) %= mod;
      }
    for (int j = 1; j <= d[dn - 1]; j++) {
      if (j >= t)
        (p[t] += dp(t, dn - 2, 1, j < d[dn - 1])) %= mod;
      else
        (p[t] += dp(t, dn - 2, 0, j < d[dn - 1])) %= mod;
    }
  }
  for (int t = 1; t <= 9; t++)
    (res += 1ll * (p[t] - p[t + 1] + mod) % mod * t % mod) %= mod;
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  string n;
  cin >> n, dn = int((n).size());
  for (int i = 0; i < dn; i++) d[i] = n[dn - i - 1] - '0';
  INIT(), cout << DP() << '\n';
  return 0;
}
