#include <bits/stdc++.h>
using namespace std;
const int MAXN = 31000;
int N, D;
int cnt[MAXN];
const int offset = 300;
int dp[MAXN][2 * offset];
int solve(int pos, int delta) {
  if (pos > 100) return 0;
  int &ret = dp[pos][delta + offset];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = -1; i <= 1; ++i) {
    if (pos == 0 && i != 0) continue;
    int L = D + delta + i;
    if (L > 0) ret = max(ret, cnt[pos] + solve(pos + L, delta + i));
  }
  return ret;
}
int main(void) {
  scanf("%d%d", &N, &D);
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    ++cnt[x];
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(0, 0));
  return 0;
}
