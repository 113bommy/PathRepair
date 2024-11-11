#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 7;
int n, ans, a[MAXN], l[MAXN], r[MAXN], dp[MAXN][MAXN], d[MAXN][MAXN], num[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    l[i] = l[i - 1];
    if (a[i] == 1) l[i]++;
  }
  for (int i = n; i >= 1; i--) {
    r[i] = r[i + 1];
    if (a[i] == 2) r[i]++;
  }
  for (int i = 1; i <= n; i++) {
    d[i][++d[i][0]] = a[i];
    num[i] = 1;
    if (a[i] == 2) num[i]++;
    ans = max(ans, l[i - 1] + 1 + r[i + 1]);
    for (int j = i + 1; j <= n; j++) {
      if (a[j] <= d[i][d[i][0]])
        d[i][++d[i][0]] = a[j];
      else
        d[i][num[i]] = a[j];
      if (a[j] == 2) num[i]++;
      ans = max(ans, l[i - 1] + d[i][0] + r[j + 1]);
    }
  }
  cout << ans << endl;
  return 0;
}
