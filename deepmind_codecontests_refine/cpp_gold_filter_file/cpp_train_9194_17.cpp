#include <bits/stdc++.h>
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = (long long)2e18;
const double INFD = 1e30;
const double EPS = 1e-9;
const double PI = std::acos(-1);
const int MOD = 1e9 + 7;
template <typename T>
inline T read() {
  T X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
const int MAXN = 105;
const int MAXV = (1 << 17) + 5;
int n, m, k;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};
int dr2[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dc2[8] = {1, 0, -1, 1, 0, -1, 1, -1};
int CASE = 1;
int dp[MAXN][2505];
int pref[MAXN];
char S[MAXN];
void update(int& a, int v) {
  a += v;
  a %= MOD;
}
void solve() {
  scanf("%s", S + 1);
  n = strlen(S + 1);
  if (n == 1) {
    printf("0\n");
    return;
  }
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + S[i] - 'a';
  }
  int ans = dp[n][pref[n]];
  update(ans, -1);
  printf("%d\n", (ans % MOD + MOD) % MOD);
}
int main() {
  n = 100;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 2500; j >= std::max(2500 - 25, 0); j--)
      update(sum, dp[i - 1][j]);
    for (int j = 2500; j >= 0; j--) {
      update(dp[i][j], sum);
      if (j >= 26) update(sum, dp[i - 1][j - 26]);
      update(sum, -dp[i - 1][j]);
    }
  }
  int T = read<int>();
  while (T--) {
    solve();
  }
  return 0;
}
