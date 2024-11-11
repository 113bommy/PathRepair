#include <bits/stdc++.h>
using namespace std;
const int N = 5000, INF = 1000000000;
int n, a[N], ps[N], dp[N][N], tag[N + 1][N], best[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ps[i] = (i == 0 ? 0 : ps[i - 1]) + a[i];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) tag[i][j] = -1;
  fill(best, best + n, -1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++) {
      best[j] = max(best[j], tag[i][j]);
      if (j == 0)
        dp[i][j] = ps[i];
      else if (best[j - 1] >= 0)
        dp[i][j] = ps[i] - ps[best[j - 1]];
      else
        dp[i][j] = INF;
      int nxt = lower_bound(ps + i + 1, ps + n, ps[i] + dp[i][j]) - ps;
      tag[nxt][0] = max(tag[nxt][0], i);
    }
  for (int i = n - 1; i >= 0; i--)
    if (dp[n - 1][i] < INF) {
      printf("%d\n", n - 1 - i);
      break;
    }
}
