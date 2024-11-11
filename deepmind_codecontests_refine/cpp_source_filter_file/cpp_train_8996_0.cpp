#include <bits/stdc++.h>
using namespace std;
int st[100000], h[100000], dp[17][100000];
long long x[100000], y[100000];
int dfs(int n) {
  if (~h[n]) return h[n];
  if (dp[0][n] == -1) return h[n] = 0;
  return h[n] = dfs(dp[0][n]) + 1;
}
int LCA(int a, int b) {
  if (h[a] < h[b]) swap(a, b);
  int d = h[a] - h[b], c = 0;
  while (d) {
    if (d & 1) a = dp[c][a];
    d >>= 1;
    c++;
  }
  if (a == b) return a;
  int v = 17;
  while (v--) {
    if (dp[v][a] != dp[v][b]) {
      a = dp[v][a], b = dp[v][b];
    }
  }
  return dp[0][a];
}
int main() {
  int N, M, a, b;
  while (scanf("%d", &N) != EOF) {
    for (int i = int(0); i < int(N); i++) {
      scanf("%lld %lld", x + i, y + i);
    }
    int sc = 0;
    for (int i = N - 1; i >= 0; i--) {
      while (sc > 2 &&
             y[st[sc - 2]] * (x[st[sc - 1]] - x[st[sc - 2]]) +
                     (y[st[sc - 2]] - y[st[sc - 1]]) * (x[st[sc - 2]] - x[i]) >
                 (x[st[sc - 1]] - x[st[sc - 2]]) * y[i]) {
        sc--;
      }
      st[sc++] = i;
      if (i == N - 1)
        dp[0][i] = -1;
      else
        dp[0][i] = st[sc - 2];
    }
    memset(h, -1, sizeof(h));
    for (int i = int(0); i < int(N); i++) dfs(i);
    for (int i = int(1); i < int(17); i++) {
      for (int j = int(0); j < int(N); j++) {
        dp[i][j] = dp[i - 1][j];
        if (dp[i][j] >= 0) dp[i][j] = dp[i - 1][dp[i][j]];
      }
    }
    scanf("%d", &M);
    for (int i = int(0); i < int(M); i++) {
      scanf("%d %d", &a, &b);
      a--, b--;
      printf("%d%c", LCA(a, b) + 1, " \n"[i == M - 1]);
    }
  }
  return 0;
}
