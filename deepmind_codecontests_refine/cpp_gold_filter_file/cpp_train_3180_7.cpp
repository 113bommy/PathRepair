#include <bits/stdc++.h>
using namespace std;
int di[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
int mark[1010][1010][8];
int dist[1010][1010][8];
int pre[1010][1010][8][4];
char s[1010][1010];
long long p[4][10000];
double dp[2010][2010];
void go(int i, int j, int d) {
  if (mark[i][j][d]) return;
  mark[i][j][d] = 1;
  go(i + di[d], j + dj[d], d);
  if (s[i - 1][j - 1] == '0')
    dist[i][j][d] = 0;
  else
    dist[i][j][d] = 1 + dist[i + di[d]][j + dj[d]][d];
  for (int k = 0; k < 4; ++k) pre[i][j][d][k] = pre[i + di[d]][j + dj[d]][d][k];
  pre[i][j][d][s[i - 1][j - 1] - '0']++;
}
int main() {
  int n, i, j, k, d;
  bool f = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%s", &s[i]);
    for (j = 0; j < n; ++j)
      if (s[i][j] != '0') f = 1;
  }
  if (!f) return 0 * printf("0\n");
  for (i = 0; i < 1010; ++i)
    for (j = 0; j < 1010; ++j)
      for (d = 0; d < 8; ++d) {
        mark[i][j][d] = dist[i][j][d] = 0;
        for (k = 0; k < 4; ++k) pre[i][j][d][k] = 0;
      }
  for (i = 0; i <= n + 1; ++i)
    for (d = 0; d < 8; ++d)
      mark[0][i][d] = mark[n + 1][i][d] = mark[i][0][d] = mark[i][n + 1][d] = 1;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      for (d = 0; d < 8; ++d) go(i, j, d);
  for (i = 2; i <= 3; ++i) {
    p[i][0] = 1;
    for (j = 1; j < 10000; ++j) p[i][j] = (p[i][j - 1] * i) % 1000000007;
  }
  dp[0][0] = 0;
  for (i = 1; i <= 2000; ++i) dp[0][i] = dp[0][i - 1] + log10(3.0);
  for (i = 1; i <= 2000; ++i)
    for (j = 0; j <= 2000; ++j) dp[i][j] = dp[i - 1][j] + log10(2.0);
  int chi, chj;
  pair<double, pair<int, int> > maxx = make_pair(0.0, make_pair(0, 0));
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      for (int st = 0; st <= 1; ++st) {
        int minn = 10000;
        for (d = st; d < 8; d += 2) minn = min(minn, dist[i][j][d]);
        int cnt[4];
        cnt[2] = cnt[3] = 0;
        for (d = st; d < 8; d += 2)
          for (k = 2; k <= 3; ++k)
            cnt[k] += (pre[i][j][d][k] -
                       pre[i + di[d] * minn][j + dj[d] * minn][d][k]);
        if (s[i - 1][j - 1] == '2') cnt[2] -= 3;
        if (s[i - 1][j - 1] == '3') cnt[3] -= 3;
        maxx =
            max(maxx, make_pair(dp[cnt[2]][cnt[3]], make_pair(cnt[2], cnt[3])));
      }
  printf("%lld\n",
         (p[2][maxx.second.first] * p[3][maxx.second.second]) % 1000000007);
}
