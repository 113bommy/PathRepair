#include <bits/stdc++.h>
using namespace std;
map<int, int> mmp;
int A[200010], B[200010], C[200010];
long long dp[200010][2];
int x1[200010], x2[200010], y[200010], y2[200010];
long long mi(long long a, long long b) {
  if (a < b) return a;
  return b;
}
int main() {
  int i, m, n, a, b, c;
  for (i = 1; i <= 200005; i++) {
    x1[i] = y[i] = 2e9;
    x2[i] = y2[i] = 0;
  }
  scanf("%d", &n);
  m = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &A[i], &B[i]);
    c = max(A[i], B[i]);
    C[++m] = c;
  }
  sort(C + 1, C + 1 + m);
  int k = 1;
  mmp[C[1]] = k++;
  for (i = 2; i <= m; i++)
    if (C[i] != C[i - 1]) mmp[C[i]] = k++;
  for (i = 1; i <= n; i++) {
    int c = mmp[max(A[i], B[i])];
    if (A[i] > x2[c]) x2[c] = A[i];
    if (A[i] < x1[c]) x1[c] = A[i];
    if (B[i] > y2[c]) y2[c] = B[i];
    if (B[i] < y[c]) y[c] = B[i];
  }
  for (i = 1; i < k; i++) {
    long long d = x2[i] - x1[i] + y2[i] - y[i];
    dp[i][0] =
        mi(abs(x2[i] - x2[i - 1]) + abs(y[i] - y[i - 1]) + dp[i - 1][1],
           abs(x2[i] - x1[i - 1]) + abs(y[i] - y2[i - 1]) + dp[i - 1][0]) +
        d;
    dp[i][1] =
        mi(abs(x1[i] - x2[i - 1]) + abs(y2[i] - y[i - 1]) + dp[i - 1][1],
           abs(x1[i] - x1[i - 1]) + abs(y2[i] - y2[i - 1]) + dp[i - 1][0]) +
        d;
  }
  long long ans = mi(dp[k - 1][1], dp[k - 1][0]);
  printf("%lld\n", ans);
  return 0;
}
