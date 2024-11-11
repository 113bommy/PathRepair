#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
const int inf = 1 << 29;
int dp[1 << 20], n, m;
int da[maxn][maxn];
int bit[maxn][maxn], co[maxn][maxn];
char s[maxn][maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", *(s + i));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &da[i][j]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ma = -1;
      for (int k = 0; k < n; k++) {
        if (s[k][j] == s[i][j]) {
          ma = max(ma, da[k][j]);
          co[i][j] += da[k][j];
          bit[i][j] ^= (1 << k);
        }
      }
      co[i][j] -= ma;
    }
  }
  for (int i = 1; i < (1 << n); i++) dp[i] = inf;
  for (int i = 0; i < ((1 << n) - 1); i++) {
    int low = -1;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        low = j;
        break;
      }
    }
    for (int j = 0; j < m; j++) {
      dp[i ^ (1 << low)] = min(dp[i ^ (1 << low)], dp[i] + da[low][j]);
      dp[i ^ bit[low][j]] = min(dp[i ^ bit[low][j]], dp[i] + co[low][j]);
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
}
