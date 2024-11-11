#include <bits/stdc++.h>
const int maxn = 505;
int dp[maxn][maxn], f[maxn][maxn], p[maxn][maxn];
char src[maxn];
void print(int l, int k, bool &x) {
  if (l == 0) return;
  if (k == 0) {
    for (int i = 1, j = l; i <= j; i++, j--) src[j] = src[i];
    for (int i = 1; i <= l; i++) printf("%c", src[i]);
    x = true;
    return;
  }
  print(p[l][k], k - 1, x);
  if (x) printf("+");
  for (int i = p[l][k] + 1, j = l; i <= j; i++, j--) src[j] = src[i];
  for (int i = p[l][k] + 1; i <= l; i++) printf("%c", src[i]);
  x = true;
}
int main() {
  int K;
  memset(dp, 0x3f, sizeof(dp));
  scanf("%s", src + 1);
  scanf("%d", &K);
  K--;
  int len = strlen(src + 1);
  for (int i = 1; i <= len; i++) {
    for (int j = i + 1; j <= len; j++) {
      f[i][j] = 0;
      for (int x = i, y = j; x <= y; x++, y--) f[i][j] += (src[x] != src[y]);
    }
  }
  for (int i = 1; i <= len; i++) dp[i][0] = f[1][i];
  for (int k = 0; k < K; k++) {
    for (int i = 1; i < len; i++) {
      for (int j = i + 1; j <= len; j++) {
        if (dp[j][k + 1] > dp[i][k] + f[i + 1][j]) {
          dp[j][k + 1] = dp[i][k] + f[i + 1][j];
          p[j][k + 1] = i;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= K; i++) {
    if (dp[len][ans] > dp[len][i]) ans = i;
  }
  printf("%d\n", dp[len][ans]);
  bool t = false;
  print(len, ans, t);
  printf("\n");
  return 0;
}
