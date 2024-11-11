#include <bits/stdc++.h>
using namespace std;
const int N = 15e4 + 9, M = 309;
const long long inf = 1e60;
int n, m, d;
int a[M], b[M], t[M];
long long dp[2][N];
inline long long LLabs(long long x) { return x > 0 ? x : -x; }
int q[N];
int main() {
  scanf("%d%d%d", &n, &m, &d);
  long long sb = 0;
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &a[i], &b[i], &t[i]), sb += b[i];
  for (int j = 1; j <= n; ++j) dp[1][j] = LLabs(a[1] - j);
  for (int k = 2; k <= m; ++k) {
    int i = k & 1;
    int tail = 0, head = 0, c = 1;
    for (int j = 1; j <= n; ++j) {
      long long dd = (t[k] - t[k - 1]) * d;
      int L = max(1LL, j - dd), R = min(n * 1LL, j + dd);
      for (; c <= R; c++) {
        while (head != tail && dp[i ^ 1][q[tail - 1]] >= dp[i ^ 1][c]) tail--;
        q[tail++] = c;
      }
      while (head != tail && q[head] < L) head++;
      dp[i][j] = dp[i ^ 1][q[head]] + LLabs(j - a[k]);
    }
  }
  long long mi = inf;
  for (int j = 1; j <= n; ++j) mi = min(mi, dp[m & 1][j]);
  cout << (sb - mi) << endl;
  return 0;
}
