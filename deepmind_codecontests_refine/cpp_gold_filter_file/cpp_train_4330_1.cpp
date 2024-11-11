#include <bits/stdc++.h>
using namespace std;
char A[1010], B[1010][1010];
int n, m, len[1010], cost[10], dp[1010][1010];
int val[1010], ml[1010];
pair<int, int> lab[1010];
const int N = 1005;
int main() {
  scanf("%s", A);
  m = strlen(A);
  reverse(A, A + m);
  for (int i = m; i <= N; i++) A[i] = '0';
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", B[i]);
    len[i] = strlen(B[i]);
    reverse(B[i], B[i] + len[i]);
    for (int j = len[i]; j <= N; j++) B[i][j] = '0';
  }
  memset(dp, -0x3f, sizeof(dp));
  for (int i = 0; i <= 9; i++) scanf("%d", &cost[i]);
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) lab[i] = make_pair(0, i);
  for (int i = 0; i < N; i++) {
    int l = 0, r = 9;
    if (i == m - 1) l = 1;
    if (A[i] != '?') l = r = A[i] - '0';
    for (int j = 0; j < n; j++) {
      val[j] = B[lab[j].second][i] - '0';
      ml[j] = max(m, len[lab[j].second]);
    }
    for (int k = l; k <= r; k++) {
      int c2 = 0, d2 = 0;
      for (int j = 0; j < n; j++) {
        c2 += ((val[j] + k) >= 10);
        if ((val[j] + k) || (i < ml[j])) d2 += cost[(val[j] + k) % 10];
      }
      for (int j = 0; j <= n; j++) {
        dp[i + 1][c2] = max(dp[i + 1][c2], dp[i][j] + d2);
        if (j >= n) continue;
        c2 -= (val[j] + k >= 10);
        c2 += (val[j] + k + 1 >= 10);
        if ((val[j] + k) || (i < ml[j])) d2 -= cost[(val[j] + k) % 10];
        d2 += cost[(val[j] + k + 1) % 10];
      }
    }
    for (int j = 0; j < n; j++) lab[j].first = val[j] * (n + 1) + n - j;
    sort(lab, lab + n);
    reverse(lab, lab + n);
  }
  printf("%d\n", dp[N][0]);
}
