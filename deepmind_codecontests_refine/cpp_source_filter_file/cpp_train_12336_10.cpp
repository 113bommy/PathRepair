#include <bits/stdc++.h>
int dp[1000][1000];
int pre[1000][1000];
char s1[1000], s2[1000];
int cal(int i, int j);
void print(int i, int j);
int main() {
  int i, j, k, l, test, t = 1;
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  k = strlen(s1 + 1);
  l = strlen(s2 + 1);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", cal(k, l));
  print(k, l);
  return 0;
}
void print(int i, int j) {
  if (i == 0 && j == 0) return;
  if (s1[i] == s2[j]) {
    print(i - 1, j - 1);
  } else if (pre[i][j] == 2) {
    printf("INSERT %d %c\n", i + 1, s2[j]);
    print(i, j - 1);
  } else if (pre[i][j] == 1) {
    printf("DELETE %d\n", i);
    print(i - 1, j);
  } else {
    printf("REPLACE %d %c\n", i, s2[j]);
    print(i - 1, j - 1);
  }
}
int cal(int i, int j) {
  if (i == 0 && j == 0) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  if (i == 0) {
    pre[i][j] = 2;
    return dp[i][j] = cal(i, j - 1) + 1;
  }
  if (j == 0) {
    pre[i][j] = 1;
    return dp[i][j] = cal(i - 1, j) + 1;
  }
  if (s1[i] == s2[j]) {
    pre[i][j] = 0;
    return dp[i][j] = cal(i - 1, j - 1);
  }
  int ret = 0, ret1;
  ret = cal(i - 1, j) + 1;
  pre[i][j] = 1;
  ret1 = cal(i, j - 1) + 1;
  if (ret1 < ret) {
    ret = ret1;
    pre[i][j] = 2;
  }
  ret1 = cal(i - 1, j - 1) + 1;
  if (ret1 < ret) {
    ret = ret1;
    pre[i][j] = 0;
  }
  return dp[i][j] = ret;
}
