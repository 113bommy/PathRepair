#include <bits/stdc++.h>
using namespace std;
const int inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 405, MAX = 400;
int n, mod, ans[N], dp[N][N], fac[N], f[N];
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int mul(int x, int y) { return 1ll * x * y % mod; }
void rem(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
void proc() {
  cin >> n;
  cout << ans[n] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t >> mod;
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
  dp[0][0] = 1;
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < i + 1; j++)
      if (dp[i][j]) {
        for (int k = 1; k < MAX - i + 1; k++)
          add(dp[i + k][j + 1], mul(dp[i][j], fac[k]));
      }
  for (int i = 1; i < MAX + 1; i++) {
    ans[i] = fac[i];
    for (int j = 3; j < i; j++) rem(ans[i], mul(dp[i][j], ans[j]));
    int lol = 0;
    for (int j = 1; j < i; j++) {
      int tmp1 = fac[j], tmp2 = fac[i - j];
      rem(tmp1, f[j]);
      add(lol, mul(tmp1, tmp2));
    }
    f[i] = lol;
    rem(ans[i], 2 * lol);
  }
  ans[2] = 2;
  while (t--) proc();
  return 0;
}
