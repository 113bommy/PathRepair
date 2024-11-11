#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 33;
const int MOD = static_cast<int>(1e9 + 7);
const int REV2 = (MOD + 1) >> 1;
int n, K;
int a[MAXN];
int dp[MAXN][MAXN][2];
int qpw[MAXN];
void init();
void input();
void work();
int add(int x, int y) {
  x += y;
  return (x < MOD) ? x : (x - MOD);
}
void addv(int &x, int y) {
  x += y;
  (x < MOD) ? x : (x -= MOD);
}
int sub(int x, int y) {
  x -= y;
  return (x >= 0) ? x : (x + MOD);
}
int main() {
  init();
  input();
  work();
}
void init() {
  ios::sync_with_stdio(false);
  qpw[0] = 1;
  for (int i = 1; i < MAXN; ++i) qpw[i] = add(qpw[i - 1], qpw[i - 1]);
}
void input() { scanf("%d", &K); }
void work() {
  if (!K) {
    printf("0\n");
    return;
  }
  n = -1;
  while (K) a[++n] = K & 1, K >>= 1;
  dp[n + 1][0][1] = 1;
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= n + 1; ++j) {
      addv(dp[i][j + 1][0], dp[i + 1][j][0]);
      if (a[i]) addv(dp[i][j + 1][1], dp[i + 1][j][1]);
      addv(dp[i][j][0], dp[i + 1][j][0] * static_cast<long long>(qpw[j]) % MOD);
      if (a[i]) {
        addv(dp[i][j][0], dp[i + 1][j][1] *
                              static_cast<long long>(j ? qpw[j - 1] : 1) % MOD);
        addv(dp[i][j][1], dp[i + 1][j][1] *
                              static_cast<long long>(j ? qpw[j - 1] : 0) % MOD);
      } else
        addv(dp[i][j][1], dp[i + 1][j][1] *
                              static_cast<long long>(j ? qpw[j - 1] : 0) % MOD);
    }
  }
  int ans = 0;
  for (int i = 0; i <= n + 1; ++i) addv(ans, add(dp[0][i][0], dp[0][i][1]));
  cout << ans << endl;
}
