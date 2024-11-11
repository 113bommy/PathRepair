#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1111;
int dp[MAX_N][MAX_N];
char S[MAX_N];
char T[MAX_N];
int n, m;
pair<int, int> tr[MAX_N][MAX_N];
void update(int i, int j, int x, int y, int val) {
  if (dp[i][j] > val) {
    dp[i][j] = val;
    tr[i][j] = make_pair(x, y);
  }
}
int main() {
  while (scanf("%s %s", S + 1, T + 1) != EOF) {
    n = strlen(S + 1);
    m = strlen(T + 1);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0 && j == 0)
          dp[i][j] = 0;
        else {
          dp[i][j] = MAX_N;
          if (i > 0) update(i, j, i - 1, j, dp[i - 1][j] + 1);
          if (j > 0) update(i, j, i, j - 1, dp[i][j - 1] + 1);
          if (i > 0 && j > 0)
            update(i, j, i - 1, j - 1, dp[i - 1][j - 1] + (S[i] != T[j]));
        }
      }
    }
    int i = n, j = m;
    printf("%d\n", dp[n][m]);
    while (j > 0 || i > 0) {
      int u = tr[i][j].first;
      int v = tr[i][j].second;
      if (u < i && v < j) {
        if (S[i] != T[j]) {
          printf("REPLACE %d %c\n", i, T[j]);
        }
      } else if (u < i) {
        printf("DELETE %d\n", i);
      } else if (v < j) {
        printf("INSERT %d %c\n", i + 1, T[j]);
      } else {
      }
      i = u;
      j = v;
    }
  }
  return 0;
}
