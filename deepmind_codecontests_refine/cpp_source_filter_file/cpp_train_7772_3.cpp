#include <bits/stdc++.h>
using namespace std;
int n;
int people[2005];
int want[2005];
int sum;
int dp[2005][10][10][10][10];
int findDistance(int a, int b) { return abs(a - b); }
int dfs(int i, int level, int a, int b, int c) {
  if (dp[i][level][a][b][c] != -1) {
    return dp[i][level][a][b][c];
  }
  int ret = 1000000;
  if (i > n) {
    if (a == 0 && b == 0 && c == 0) {
      return 0;
    }
    if (a != 0) {
      ret = min(ret, dfs(i, a, 0, b, c) + findDistance(a, level) + 1);
    }
    if (b != 0) {
      ret = min(ret, dfs(i, b, a, 0, c) + findDistance(b, level) + 1);
    }
    if (c != 0) {
      ret = min(ret, dfs(i, c, a, b, 0) + findDistance(c, level) + 1);
    }
    return dp[i][level][a][b][c] = ret;
  }
  if (a != 0) {
    ret = min(ret, dfs(i, a, 0, b, c) + findDistance(a, level) + 1);
  }
  if (b != 0) {
    ret = min(ret, dfs(i, b, a, 0, c) + findDistance(b, level) + 1);
  }
  if (c != 0) {
    ret = min(ret, dfs(i, c, a, b, 0) + findDistance(c, level) + 1);
  }
  if (a && b && c) {
    ret = min(ret, findDistance(level, people[i]) + 1 +
                       findDistance(want[i], people[i]) + 1 +
                       dfs(i + 1, want[i], a, b, c));
    ret = min(ret, findDistance(level, people[i]) + 1 +
                       findDistance(people[i], a) + 1 +
                       dfs(i + 1, a, want[i], b, c));
    ret = min(ret, findDistance(level, people[i]) + 1 +
                       findDistance(people[i], b) + 1 +
                       dfs(i + 1, a, a, want[i], c));
    ret = min(ret, findDistance(level, people[i]) + 1 +
                       findDistance(people[i], c) + 1 +
                       dfs(i + 1, a, a, b, want[i]));
  } else {
    if (a == 0) {
      ret = min(ret, findDistance(level, people[i]) + 1 +
                         dfs(i + 1, people[i], want[i], b, c));
    } else if (b == 0) {
      ret = min(ret, findDistance(level, people[i]) + 1 +
                         dfs(i + 1, people[i], a, want[i], c));
    } else if (c == 0) {
      ret = min(ret, findDistance(level, people[i]) + 1 +
                         dfs(i + 1, people[i], a, b, want[i]));
    }
  }
  return dp[i][level][a][b][c] = ret;
}
int main(void) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> people[i] >> want[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(1, 1, 0, 0, 0) << endl;
  return 0;
}
