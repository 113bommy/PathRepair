#include <bits/stdc++.h>
using namespace std;
int n, s, l, a[100005], Min[100005][21], Max[100005][21], dp[100005], cnt;
int ask(int l, int r) {
  int pos = 0;
  while (l + (1 << pos + 1) <= r) pos++;
  return max(Max[l][pos], Max[r - (1 << pos) + 1][pos]) -
         min(Min[l][pos], Min[r - (1 << pos) + 1][pos]);
}
int main() {
  scanf("%d%d%d", &n, &s, &l);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    Min[i][0] = Max[i][0] = a[i];
  }
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) {
      if (i + (1 << j) - 1 <= n)
        Min[i][j] = min(Min[i][j - 1], Min[i + (1 << j - 1)][j - 1]);
      if (i + (1 << j) - 1 <= n)
        Max[i][j] = max(Max[i][j - 1], Max[i + (1 << j - 1)][j - 1]);
    }
  for (int i = 1; i <= n; i++) dp[i] = 1e9;
  for (int i = l; i <= n; i++) {
    while (i - cnt >= l && (ask(cnt + 1, i) > s || dp[cnt] == 1e9)) cnt++;
    if (i - cnt >= l) dp[i] = min(dp[i], dp[cnt] + 1);
  }
  if (dp[n] == 1e9)
    puts("-1");
  else
    printf("%d", dp[n]);
}
