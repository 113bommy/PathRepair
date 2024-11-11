#include <bits/stdc++.h>
using namespace std;
int dp[500][100005];
int n, q;
int a[100005], b[100005];
int c[100005][2];
int main() {
  while (scanf("%d%d", &n, &q) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      b[i] = a[i];
    }
    int cnt = -1;
    sort(b + 1, b + 1 + n);
    b[0] = -1;
    memset(c, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      if (b[i] != b[i - 1]) cnt++;
      c[cnt][0] = b[i];
      c[cnt][1]++;
    }
    vector<int> v;
    for (int i = 0; i <= cnt; i++) {
      if (c[i][1] >= c[i][0]) v.push_back(c[i][1]);
    }
    for (int i = 0; i < v.size(); i++) {
      dp[i][0] = 0;
      for (int j = 1; j <= n; j++) {
        if (a[j] == v[i])
          dp[i][j] = dp[i][j - 1] + 1;
        else
          dp[i][j] = dp[i][j - 1];
      }
    }
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      int ans = 0;
      for (int i = 0; i < v.size(); i++)
        ans += (dp[i][r] - dp[i][l - 1]) == v[i];
      printf("%d\n", ans);
    }
  }
  return 0;
}
