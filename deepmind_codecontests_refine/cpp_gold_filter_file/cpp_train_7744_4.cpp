#include <bits/stdc++.h>
using namespace std;
const int N = 4010;
const int K = 810;
const int INF = 1e9;
int mat[N][N];
int pre[N][N];
int t[N];
int dp[N][K];
int cost[N][N];
void go(int from, int to, int k, int mn, int mx) {
  if (to < from) return;
  int avg = (from + to) / 2;
  int best = INF;
  int opt = -1;
  for (int i = mn; i < min(mx + 1, avg); i++) {
    int cur = dp[i][k - 1] + cost[i + 1][avg];
    if (cur < best) {
      best = cur;
      opt = i;
    }
  }
  dp[avg][k] = best;
  go(from, avg - 1, k, mn, opt);
  go(avg + 1, to, k, opt, mx);
}
int main() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < K; j++) dp[i][j] = INF;
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char c;
      while (c = getchar(), (c < '0' || c > '9'))
        ;
      mat[i][j] = c - '0';
    }
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++) {
      pre[i][j] =
          mat[i - 1][j - 1] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
    }
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++) {
      cost[i][j] =
          pre[j][j] - pre[i - 1][j] - pre[j][i - 1] + pre[i - 1][i - 1];
    }
  dp[0][0] = 0;
  for (int ck = 1; ck < k + 1; ck++) go(ck, n, ck, 0, n);
  cout << (dp[n][k] / 2) << endl;
  return 0;
}
