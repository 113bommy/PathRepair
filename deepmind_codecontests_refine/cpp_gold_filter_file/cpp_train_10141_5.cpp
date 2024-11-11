#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
int dp[maxn][2];
char s[maxn];
bool inq[maxn][2];
inline void gao(int i, int p) {
  int a = dp[p][0], b = dp[p][1];
  int c = 0;
  if (a != b)
    c = a < b;
  else if (inq[p][0] == 0)
    c = 0;
  else if (inq[p][1] == 0)
    c = 1;
  dp[i][0] = dp[p][c];
  inq[i][0] = inq[p][c];
}
int main() {
  while (~scanf("%s", s)) {
    int i, j, p, q, n = strlen(s);
    for (i = 1; i < n; i++)
      if (s[i] != s[i - 1]) break;
    if (i == n) {
      printf("1\n");
      continue;
    }
    dp[i][0] = inq[i][0] = 0;
    dp[i][1] = inq[i][1] = 1;
    for (i = ((i + 1) % n), j = 1; j < n; i = ((i + 1) % n), j++) {
      p = ((i - 1 + n) % n);
      gao(i, p);
      if (s[i] != s[p]) {
        dp[i][1] = dp[p][0] + 1;
        inq[i][1] = inq[p][0];
      } else {
        dp[i][1] = dp[p][1];
        inq[i][1] = inq[p][1];
      }
    }
    printf("%d\n", max(dp[i - 1][0], dp[i - 1][1] - inq[i - 1][1]));
  }
  return 0;
}
