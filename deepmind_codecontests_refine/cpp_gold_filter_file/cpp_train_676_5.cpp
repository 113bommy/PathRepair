#include <bits/stdc++.h>
using namespace std;
string s;
char pc[128][128][128];
bool foo(int ib, int jb, int tb, int ie, int je, int te) {
  if (ie - ib == 2 || je - jb == 2 || te - tb == 2) {
    return false;
  }
  if (ie == ib) return pc[ie][jb][te] || pc[ie][je][tb];
  if (je == jb) return pc[ib][je][te] || pc[ie][je][tb];
  if (te == tb) return pc[ie][jb][te] || pc[ib][je][te];
  assert(0 > 0);
  return false;
}
int main() {
  int n, m, k;
  scanf("%d%d%d\n", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> (pc[i][j] + 1);
      for (int t = 1; t <= k; t++) pc[i][j][t] -= '0';
    }
  int di[] = {0, 0, 1};
  int dj[] = {0, 1, 0};
  int dt[] = {1, 0, 0};
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int t = 1; t <= k; t++) {
        if (pc[i][j][t] == (char)0) continue;
        bool f = 0;
        for (int t1 = 0; (t1 < 3) && !f; t1++) {
          if ((i - di[t1] < 1) || (j - dj[t1] < 1) || (t - dt[t1] < 1))
            continue;
          if (!pc[i - di[t1]][j - dj[t1]][t - dt[t1]]) continue;
          for (int t2 = 0; t2 < 3; t2++) {
            if ((i + di[t2] > n) || (j + dj[t2] > m) || (t + dt[t2] > k))
              continue;
            if (!pc[i + di[t2]][j + dj[t2]][t + dt[t2]]) continue;
            pc[i][j][t] = (char)0;
            if (!foo(i - di[t1], j - dj[t1], t - dt[t1], i + di[t2], j + dj[t2],
                     t + dt[t2]))
              f = 1;
            pc[i][j][t] = (char)1;
          }
        }
        if (f) ans++;
      }
  printf("%d\n", ans);
  return 0;
}
