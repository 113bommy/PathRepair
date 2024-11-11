#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
vector<int> by;
int a[100005], b[100005];
int n, m;
int N = 16;
int p[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int c[100];
int dp[105][66000], path[105][66000], val[105][66000];
int U;
void ii() {
  for (int i = 1; i <= 60; i++) {
    c[i] = 0;
    for (int j = 0; j < N; j++) c[i] = (c[i] << 1) + (i % p[j] == 0);
  }
}
int main() {
  ii();
  U = (1 << 16) - 1;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= U; j++) dp[i][j] = INF;
    for (int j = 0; j <= U; j++) dp[0][j] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= U; j++)
        for (int k = 1; k <= 60; k++) {
          int s = c[k];
          if ((s ^ j) != (s | j)) continue;
          if (dp[i][j] + abs(k - a[i + 1]) < dp[i + 1][j | s]) {
            dp[i + 1][j | s] = dp[i][j] + abs(k - a[i + 1]);
            path[i + 1][j | s] = j;
            val[i + 1][j | s] = k;
          }
        }
    int s, t = -1;
    for (int i = 0; i <= U; i++)
      if (t == -1 || dp[n][i] < dp[n][t]) t = i;
    by.clear();
    s = n;
    while (s > 0) {
      by.push_back(val[s][t]);
      t = path[s--][t];
    }
    for (int i = (int)by.size() - 1; i >= 0; i--)
      printf("%d%c", by[i], i ? ' ' : '\n');
  }
  return 0;
}
