#include <bits/stdc++.h>
using namespace std;
int n, q, c, mp[11][110][110];
int X[100010], Y[100010], s[100010];
int main() {
  scanf("%d%d%d", &n, &q, &c);
  for (int i = 1; i <= n; i++)
    scanf("%d%d%d", &X[i], &Y[i], &s[i]), mp[s[i]][X[i]][Y[i]] = 1;
  for (int t = 0; t <= c; t++) {
    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= 100; j++)
        mp[t][i][j] += mp[t][i - 1][j] + mp[t][i][j - 1] - mp[t][i - 1][j - 1];
    }
  }
  while (q--) {
    int ans = 0;
    int ti, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &ti, &x1, &y1, &x2, &y2);
    for (int t = 0; t <= c; t++) {
      int tmp = 0;
      tmp = mp[t][x2][y2] - mp[t][x1 - 1][y2] - mp[t][x2][y1 - 1] +
            mp[t][x1 - 1][y1 - 1];
      ans += (t + ti) % (c + 1) * tmp;
    }
    printf("%d\n", ans);
  }
  return 0;
}
