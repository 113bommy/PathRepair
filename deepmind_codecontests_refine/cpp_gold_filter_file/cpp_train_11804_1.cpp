#include <bits/stdc++.h>
using namespace std;
int nr[55][55], nd[55][55], n, m, a[55][55];
bool check() {
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] > 0)
        for (int k = i; k <= n; k++)
          for (int t = 1; t <= m; t++)
            if (a[k][t] > 0) {
              int p1, q1, p2, q2;
              p1 = min(i, k);
              q1 = min(j, t);
              p2 = max(i, k);
              q2 = max(j, t);
              int xx = q2 - q1 + 1, yy = p2 - p1 + 1;
              if (t < j) {
                if ((nr[i][t] < xx || nd[i][t] < yy) &&
                    (nr[k][t] < xx || nd[i][j] < yy))
                  return true;
              } else {
                if ((nr[i][j] < xx || nd[i][t] < yy) &&
                    (nr[k][j] < xx || nd[i][j] < yy)) {
                  return true;
                }
              }
            }
  return false;
}
int main() {
  char st[55];
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf(" %s", st);
    for (int j = 1; j <= m; j++)
      if (st[j - 1] == 'B')
        a[i][j] = 1;
      else
        a[i][j] = 0;
  }
  memset(nr, 0, sizeof(nr));
  memset(nd, 0, sizeof(nd));
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      if (a[i][j] == 1)
        nr[i][j] = nr[i][j + 1] + 1;
      else
        nr[i][j] = 0;
  for (int j = 1; j <= m; j++)
    for (int i = n; i >= 1; i--)
      if (a[i][j] == 1)
        nd[i][j] = nd[i + 1][j] + 1;
      else
        nd[i][j] = 0;
  bool ans = check();
  if (ans)
    puts("NO");
  else
    puts("YES");
  return 0;
}
