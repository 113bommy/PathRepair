#include <bits/stdc++.h>
using namespace std;
char s[5100];
int memo[5010][5010];
int v[5010][5010];
int n;
int main() {
  scanf("%s", s);
  n = strlen(s);
  memset(v, 0, sizeof(v));
  memset(memo, 0, sizeof(memo));
  for (int i = 1; i <= n; i++) {
    memo[i][i] = 1;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      memo[i][j] = 0;
      if (s[i - 1] != s[j - 1]) continue;
      if (i + 1 > j - 1) {
        memo[i][j] = 1;
        continue;
      }
      if (memo[i + 1][j - 1]) {
        memo[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
      if (memo[i][j]) {
        v[i][j]++;
      }
    }
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < (q); i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    int res = v[b][b] - v[b][a - 1] - v[a - 1][b] + v[a - 1][a - 1];
    printf("%d\n", res);
  }
  return 0;
}
