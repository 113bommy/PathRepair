#include <bits/stdc++.h>
using namespace std;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long NLINF = 0xf7f7f7f7f7f7f7f7;
const int INF = 0x3f3f3f3f, NINF = 0xf7f7f7f7;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int N = 1e5 + 10;
int n, h[N][2];
long long dp[N][2];
long long f(int i, int flg) {
  if (i > n) return 0LL;
  if (dp[i][flg] != -1) return dp[i][flg];
  return dp[i][flg] = max(f(i + 1, flg), f(i + 1, !flg) + h[i][flg]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i][0]);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i][1]);
  memset(dp, -1, sizeof dp);
  printf("%d\n", max(f(1, 1), f(1, 0)));
}
