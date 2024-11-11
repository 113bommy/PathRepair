#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 7;
const int INF = 0x3f3f3f3f;
int n, m;
int a[maxn], b[maxn], dp[maxn];
bool check() {
  for (int i = 1; i <= m + 1; i++) {
    if (b[i] < b[i - 1]) return false;
  }
  return true;
}
int DP(int l, int r) {
  int cnt = 1;
  dp[cnt] = a[l];
  for (int i = l + 1; i <= r; i++) {
    int pos = upper_bound(dp + 1, dp + 1 + cnt, a[i]) - dp;
    if (pos != 1) {
      if (pos == cnt + 1) {
        dp[++cnt] = a[i];
      } else {
        dp[pos] = a[i];
      }
    }
  }
  int pos = upper_bound(dp + 1, dp + 1 + cnt, a[r]) - dp - 1;
  return (r - l + 1) - pos;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] -= i;
  }
  a[0] = -INF;
  a[n + 1] = INF;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  b[0] = 0;
  b[m + 1] = n + 1;
  if (check()) {
    printf("-1\n");
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= m + 1; i++) {
    ans += DP(b[i - 1], b[i]);
  }
  printf("%d\n", ans);
  return 0;
}
