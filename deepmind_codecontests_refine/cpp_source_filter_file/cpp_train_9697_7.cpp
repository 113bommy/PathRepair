#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7, MOD = 998244353;
int a[MAXN] = {}, pos[MAXN], n, k, res = 1, m, f[MAXN][2];
int pw(int cs, int sm) {
  if (sm == 0) return 1;
  int hpw = pw(cs, sm >> 1);
  hpw = 1LL * hpw * hpw % MOD;
  if (sm & 1) hpw = 1LL * cs * hpw % MOD;
  return hpw;
}
void add(int &a, const int &b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int mul(int a, int b) { return 1LL * a * b % MOD; }
void upd() {
  if (a[pos[m] + 2] == 0) {
    if (pos[1] > 2)
      res = mul(res, pw(k - 1, m));
    else
      res = mul(res, mul(k, pw(k - 1, m - 1)));
    return;
  }
  f[1][0] = k - 1, f[1][1] = 1;
  if (pos[1] > 2) {
    if (a[pos[1] - 2] == a[pos[m] + 2])
      f[1][1] = 0;
    else
      f[1][0] = k - 2;
  }
  for (int i = 2; i <= m; ++i) {
    f[i][0] = 0;
    add(f[i][0], 1LL * (k - 2) * f[i - 1][0] % MOD);
    add(f[i][0], 1LL * (k - 1) * f[i - 1][1] % MOD);
    f[i][1] = f[i][0];
  }
  res = mul(res, f[m][0]);
}
void calc(int sta) {
  m = 0;
  for (int i = sta; i <= n; i += 2)
    if (a[i] > 0) {
      if (a[i] == a[i + 2]) cout << 0, exit(0);
      if (m == 0) continue;
      upd();
      m = 0;
    } else
      pos[++m] = i;
  if (m > 0) upd();
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  calc(1);
  calc(2);
  cout << res;
  return 0;
}
