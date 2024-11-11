#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3c3c3c3c;
const long long LINF = 1ll * INF * INF * 2;
const int N = 3000;
int n, m;
int x[N][N];
int dp[30][4100];
int cur[4100];
void rotate(int idx) {
  int t = x[idx][0];
  for (int i = 0; i < n - 1; i++) x[idx][i] = x[idx][i + 1];
  x[idx][n - 1] = t;
}
int sum(int idx, int b) {
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (b & 1) ret += x[idx][i];
    b /= 2;
  }
  return ret;
}
void proc() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", x[j] + i);
    }
  int B = 1 << n;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j < B; j++) dp[i][j] = 0;
  for (int i = 0; i < m; i++) {
    for (int k = 0; k < B; k++) cur[k] = 0;
    for (int j = 0; j < n; j++) {
      rotate(i);
      for (int k = 0; k < B; k++) cur[k] = max(cur[k], sum(i, k));
    }
    for (int k = 0; k < B; k++) {
      for (int t = 0; t < B; t++) {
        if (k & (~t)) continue;
        dp[i + 1][t & (~k)] = max(dp[i + 1][t & (~k)], dp[i][t] + cur[k]);
      }
    }
  }
  printf("%d\n", dp[m][0]);
}
int main(void) {
  int tc;
  scanf("%d", &tc);
  while (tc--) proc();
}
