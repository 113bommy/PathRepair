#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 333;
const long long linf = 1e18 + inf;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int mul(int x, int y) { return (long long)x * y % mod; }
int n;
vector<int> v[N];
int dp[N][2][2], dp1[2][2], dp2[2][2], dpOdd[2][2], helpOdd[2][2], dpEven[2][2],
    helpEven[2][2];
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    v[x].push_back(i);
  }
  for (int x = n; x >= 1; x--) {
    dp[x][0][0] = dp[x][1][1] = 1;
    memset(dp1, 0, sizeof(dp1));
    for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end();
         it++) {
      int u = *it;
      memset(dp2, 0, sizeof(dp2));
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          int c = !b;
          for (int d = 0; d < 2; d++) {
            dp2[a][d] = add(dp2[a][d], mul(dp1[a][b], dp[u][c][d]));
          }
        }
      }
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          dp[x][a][b] = add(dp[x][a][b], dp2[!a][b]);
          dp1[a][b] = add(dp1[a][b], dp2[a][b]);
          dp1[a][b] = add(dp1[a][b], dp[u][a][b]);
        }
      }
    }
    memset(dp1, 0, sizeof(dp1));
    reverse(v[x].begin(), v[x].end());
    for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end();
         it++) {
      int u = *it;
      memset(dp2, 0, sizeof(dp2));
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          int c = !b;
          for (int d = 0; d < 2; d++) {
            dp2[a][d] = add(dp2[a][d], mul(dp1[a][b], dp[u][c][d]));
          }
        }
      }
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          dp1[a][b] = add(dp1[a][b], dp2[a][b]);
          dp1[a][b] = add(dp1[a][b], dp[u][a][b]);
        }
      }
    }
    for (int a = 0; a < 2; a++) {
      for (int b = 0; b < 2; b++) {
        dp[x][a][b] = add(dp[x][a][b], dp1[!a][b]);
      }
    }
    memset(dpOdd, 0, sizeof(dpOdd));
    memset(dpEven, 0, sizeof(dpEven));
    reverse(v[x].begin(), v[x].end());
    for (__typeof((v[x]).begin()) it = (v[x]).begin(); it != (v[x]).end();
         it++) {
      int u = *it;
      memset(helpOdd, 0, sizeof(helpOdd));
      memset(helpEven, 0, sizeof(helpEven));
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          helpOdd[a][b] = add(helpOdd[a][b], mul(dpEven[a][b], dp[u][a][b]));
          helpEven[a][b] = add(helpEven[a][b], mul(dpOdd[a][b], dp[u][!b][!a]));
        }
      }
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          if (a == b) {
            dp[x][a][a] = add(dp[x][a][a], mod - helpEven[!a][a]);
            dp[x][a][a] = add(dp[x][a][a], mod - helpOdd[!a][a]);
          }
          if (a != b) {
            dp[x][a][b] = add(dp[x][a][b], mod - helpOdd[!a][!a]);
          }
          dpOdd[a][b] = add(dpOdd[a][b], dp[u][a][b]);
          dpOdd[a][b] = add(dpOdd[a][b], helpOdd[a][b]);
          dpEven[a][b] = add(dpEven[a][b], helpEven[a][b]);
        }
      }
    }
  }
  printf("%d\n", add(dp[1][0][0], dp[1][0][1]));
  return 0;
}
