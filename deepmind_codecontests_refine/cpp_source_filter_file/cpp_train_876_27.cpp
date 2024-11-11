#include <bits/stdc++.h>
using namespace std;
const int MN = 101234, MM = 20123;
int a[MN], b[MM], dp[10 * MN], gp[10 * MN], l[MN], r[MN];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(b, b + m);
  for (int i = 1; i < n; i++)
    if (a[i - 1] + 1 == a[i])
      l[i] = l[i - 1];
    else
      l[i] = i;
  r[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--)
    if (a[i + 1] - 1 == a[i])
      r[i] = r[i + 1];
    else
      r[i] = i;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++)
      if (b[j] <= a[i]) cnt++;
    if (i == l[i])
      dp[i] = (i ? gp[i - 1] : 0);
    else
      dp[i] = dp[i - 1];
    for (int j = 0; j < cnt; j++)
      if (i - (a[i] - b[j]) >= 0) {
        if (!l[i - (a[i] - b[j])])
          dp[i] = max(dp[i], cnt - j);
        else
          dp[i] = max(dp[i], gp[i - (a[i] - b[j]) - 1] + cnt - j);
      }
    if (i) gp[i] = max(gp[i], gp[i - 1]);
    gp[i] = max(gp[i], dp[i]);
    for (int j = cnt; j < m; j++)
      if (i + (b[j] - a[i]) < n)
        gp[i + (b[j] - a[i])] = max(gp[i + (b[j] - a[i])], dp[i] + j - cnt + 1);
  }
  cout << gp[n - 1] << endl;
}
