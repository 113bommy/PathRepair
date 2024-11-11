#include <bits/stdc++.h>
using namespace std;
int n, m, l, mn, ret, cnt, id;
int p[20], f[20], nx[500025][20], dp[35000][110], b[500025];
char prob[20][15], s[15];
int Count(int S, int k) {
  int r = 0;
  for (int i = (k + 1); i < (n); i++)
    if (S & (1 << i)) r++;
  return r;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%s", prob[i]);
  scanf("%d", &m);
  for (int itr = (0); itr < (m); itr++) {
    scanf("%d", &l);
    for (int j = (0); j < (l); j++) {
      scanf("%s", s);
      b[j] = -1;
      for (int k = (0); k < (n); k++) {
        if (!strcmp(s, prob[k])) b[j] = k;
      }
    }
    for (int k = (0); k < (n); k++) nx[l][k] = (1 << 30);
    for (int j = (l)-1; j >= (0); j--) {
      for (int k = (0); k < (n); k++) nx[j][k] = nx[j + 1][k];
      if (b[j] != -1) nx[j][b[j]] = j;
    }
    memset(dp, 63, sizeof(dp));
    dp[0][0] = -1;
    for (int i = (0); i < ((1 << n)); i++)
      for (int j = (0); j < (110); j++)
        if (dp[i][j] < l) {
          for (int k = (0); k < (n); k++)
            if (!((1 << k) & i)) {
              int ti = i + (1 << k), tj = j + Count(i, k);
              dp[ti][tj] = min(dp[ti][tj], nx[dp[i][j] + 1][k]);
            }
        }
    for (int i = (0); i < (110); i++)
      if (dp[(1 << n) - 1][i] < l && ret < n * (n - 1) / 2 - i + 1) {
        ret = n * (n - 1) / 2 - i + 1, id = itr + 1;
      }
  }
  if (!ret)
    puts("Brand new problem!");
  else {
    printf("%d\n", id);
    printf("[:");
    while (ret--) printf("|");
    printf(":]\n");
  }
  return 0;
}
