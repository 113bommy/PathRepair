#include <bits/stdc++.h>
using namespace std;
vector<int> e[100010];
int a[100010], dp[100010];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int m = n;
  while (m && (n - m + 1) * (n - m + 2) / 2 < k * 3) m--;
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x <= m)
      ans += 3;
    else
      e[y].push_back(x);
  }
  for (int i = 0; i <= n; i++) dp[i] = 1000000;
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    sort(e[i].begin(), e[i].end());
    int cnt = 0;
    for (vector<int>::iterator p = e[i].begin(); p != e[i].end(); p++)
      a[++cnt] = *p;
    int mi = tmp, last = cnt;
    tmp += cnt * 3;
    for (int j = n; j > m && j >= i; j--) {
      while (last && a[last] >= j) last--;
      mi = min(mi, dp[j - i]);
      dp[j - i] =
          min(mi + (n - j + 1) * (n - j + 2) / 2 + 2, dp[j - i]) + last * 3;
    }
    tmp = min(tmp, dp[n - i]);
  }
  printf("%d\n", ans + tmp);
  return 0;
}
