#include <bits/stdc++.h>
using namespace std;
int t, n, dp[150005][5], fr[150005][5];
bool de[150004][5];
char x[150005];
void go(int i, int fj, int tj, bool dd) {
  if (dp[i][fj] + dd < dp[i + 1][tj]) {
    dp[i + 1][tj] = dp[i][fj] + dd;
    fr[i + 1][tj] = fj;
    de[i + 1][tj] = dd;
  }
}
int main() {
  scanf("%d", &t);
  for (int i = 1; i < 5; i++) dp[0][i] = INT_MAX / 2;
  while (t--) {
    scanf("%s", x);
    n = strlen(x);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) dp[i + 1][j] = INT_MAX / 2;
      for (int j = 0; j < 5; j++) go(i, j, j, 1);
      if (x[i] == 'o') {
        go(i, 0, 1, 0);
        go(i, 1, 1, 0);
        go(i, 2, 1, 0);
        go(i, 3, 1, 0);
      } else if (x[i] == 'n') {
        go(i, 0, 0, 0);
        go(i, 1, 2, 0);
        go(i, 2, 0, 0);
        go(i, 3, 0, 0);
        go(i, 4, 0, 0);
      } else if (x[i] == 'e') {
        go(i, 0, 0, 0);
        go(i, 1, 0, 0);
        go(i, 3, 0, 0);
        go(i, 4, 0, 0);
      } else if (x[i] == 't') {
        go(i, 0, 3, 0);
        go(i, 1, 3, 0);
        go(i, 2, 3, 0);
        go(i, 3, 3, 0);
        go(i, 4, 3, 0);
      } else if (x[i] == 'w') {
        go(i, 0, 0, 0);
        go(i, 1, 0, 0);
        go(i, 2, 0, 0);
        go(i, 3, 4, 0);
        go(i, 4, 0, 0);
      } else {
        go(i, 0, 0, 0);
        go(i, 1, 0, 0);
        go(i, 2, 0, 0);
        go(i, 3, 0, 0);
        go(i, 4, 0, 0);
      }
    }
    for (int i = n + 1; i <= n; i++) {
      for (int j = 0; j < 5; j++) {
        printf("[%d%d]", fr[i][j], de[i][j]);
        if (dp[i][j] == INT_MAX / 2)
          printf("_ ");
        else
          printf("%d ", dp[i][j]);
      }
      if (i != n) printf("%c", x[i]);
      puts("");
    }
    int at = 0;
    for (int i = 1; i < 5; i++)
      if (dp[n][i] < dp[n][at]) at = i;
    printf("%d\n", dp[n][at]);
    stack<int> ans;
    for (int i = n; i; i--) {
      if (de[i][at]) ans.push(i - 1);
      at = fr[i][at];
    }
    if (ans.empty())
      puts("");
    else {
      printf("%d", ans.top());
      ans.pop();
      while (!ans.empty()) {
        printf(" %d", ans.top());
        ans.pop();
      }
      puts("");
    }
  }
}
