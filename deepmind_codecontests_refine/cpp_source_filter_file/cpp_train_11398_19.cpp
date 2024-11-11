#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
long long Mod, E[maxn], dp[maxn][110], f[maxn], H[maxn], EK[maxn];
int n, k;
vector<int> nd[maxn];
void init() {
  E[0] = 1 % Mod, EK[0] = 1;
  for (int i = 1; i <= n; i++)
    E[i] = E[i - 1] * 10 % Mod, EK[i] = EK[i - 1] * 10 % k;
  for (int i = 0; i <= maxn - 1; i++) nd[i].clear();
  for (int i = 1; i <= n - 1; i++)
    for (int j = 0; j <= k - 1; j++)
      if (j * EK[i] % k == 0) nd[i].push_back(j);
}
long long GetH(int L) {
  int tmp = 9;
  long long ret = 0;
  for (int i = 1; i <= L; i++) {
    ret = (ret * 10 + tmp / k) % Mod;
    tmp %= k;
    tmp = tmp * 10 + 9;
  }
  return ret % Mod;
}
long long fast_add(long long x, long long K) {
  long long ans = 0;
  while (K > 0) {
    if (K & 1) ans = (ans + x) % Mod;
    K >>= 1;
    x = (x + x) % Mod;
  }
  return ans;
}
void DP() {
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= 9; i++) dp[1][i % k]++;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j <= k - 1; j++) {
      for (int y = 0; y <= 9; y++)
        dp[i][(j * 10 + y) % k] =
            (dp[i][(j * 10 + y) % k] + dp[i - 1][j]) % Mod;
    }
}
void Solve() {
  long long ans = 0;
  memset(f, 0, sizeof(f));
  long long tmpH = 0;
  f[1] = 9 / k;
  for (int i = 2; i <= n; i++) {
    tmpH = (H[i] - H[i - 1] + Mod) % Mod;
    long long S = 0;
    for (int j = 1; j <= i - 1; j++)
      for (int jj = 0; jj <= nd[j].size() - 1; jj++)
        S = (S + f[j] * dp[i - j][nd[j][jj]]);
    f[i] = ((tmpH - S) % Mod + Mod) % Mod;
  }
  for (int i = 1; i <= n - 1; i++)
    ans = (ans + f[i] * 9 * E[n - i - 1] % Mod) % Mod;
  ans = (ans + f[n]) % Mod;
  cout << ans << endl;
}
int main() {
  clock_t st, ed;
  cin >> n >> k >> Mod;
  st = clock();
  if (n == 1) {
    cout << 9 / k % Mod << endl;
    return 0;
  }
  init();
  for (int i = 1; i <= n; i++) H[i] = GetH(i);
  DP();
  Solve();
  return 0;
}
