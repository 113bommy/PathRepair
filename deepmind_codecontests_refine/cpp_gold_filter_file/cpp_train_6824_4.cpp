#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const long long INF = 1e16;
string temp;
string str[2][maxn];
long long cost[maxn];
long long dp[2][2];
int main() {
  int n;
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d", cost + i);
  }
  for (i = 0; i < n; i++) {
    cin >> str[0][i];
    temp = str[0][i];
    reverse(temp.begin(), temp.end());
    str[1][i] = temp;
  }
  dp[0][0] = 0;
  dp[1][0] = cost[0];
  bool mark = false;
  for (i = 1; i < n; i++) {
    dp[0][1] = dp[1][1] = INF;
    if (str[0][i] >= str[0][i - 1] && dp[0][0] != -1) {
      mark = true;
      dp[0][1] = dp[0][0];
    }
    if (str[0][i] >= str[1][i - 1] && dp[1][0] != -1) {
      mark = true;
      dp[0][1] = min(dp[0][1], dp[1][0]);
    }
    if (!mark) {
      dp[0][1] = -1;
    }
    mark = false;
    if (str[1][i] >= str[0][i - 1] && dp[0][0] != -1) {
      mark = true;
      dp[1][1] = dp[0][0] + cost[i];
    }
    if (str[1][i] >= str[1][i - 1] && dp[1][0] != -1) {
      mark = true;
      dp[1][1] = min(dp[1][1], dp[1][0] + cost[i]);
    }
    if (!mark) {
      dp[1][1] = -1;
    }
    dp[1][0] = dp[1][1];
    dp[0][0] = dp[0][1];
  }
  if (dp[0][0] == -1 && dp[1][0] == -1) {
    printf("-1\n");
  } else if (dp[0][0] == -1) {
    printf("%I64d\n", dp[1][0]);
  } else if (dp[1][0] == -1) {
    printf("%I64d\n", dp[0][0]);
  } else {
    printf("%I64d\n", min(dp[1][0], dp[0][0]));
  }
  return 0;
}
