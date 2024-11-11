#include <bits/stdc++.h>
using namespace std;
int t, tt, ii, xx, yy, x, y, ans, n, i, h, j, k, b, a, minn, maxx, p;
int g[1000000], fix[1000000], F[1000000];
pair<int, int> d[1000000];
int main() {
  scanf("%d %d", &n, &h);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    d[i] = make_pair(a, i);
  }
  sort(d + 1, d + n + 1);
  reverse(d + 1, d + n + 1);
  if (n == 2) {
    cout << 0 << endl;
    cout << 1 << " " << 2 << " " << endl;
    return 0;
  }
  if (n == 3) {
    ans = 1000000000;
    for (i = 1; i <= 2; i++)
      for (j = 1; j <= 2; j++)
        for (k = 1; k <= 2; k++) {
          fix[1] = i;
          fix[2] = j;
          fix[3] = k;
          minn = 1000000000;
          maxx = -1000000000;
          for (a = 1; a <= 3; a++)
            for (b = a + 1; b <= 3; b++)
              if (fix[a] == fix[b]) {
                p = d[a].first + d[b].first;
                minn = min(minn, p);
                maxx = max(maxx, p);
              } else {
                p = d[a].first + d[b].first + h;
                minn = min(minn, p);
                maxx = max(maxx, p);
              }
          if (ans > maxx - minn) {
            ans = maxx - minn;
            g[1] = i;
            g[2] = j;
            g[3] = k;
          }
        }
    cout << ans << endl;
    for (i = 1; i <= 3; i++) F[d[i].second] = g[i];
    for (i = 1; i <= 3; i++) cout << F[i] << " ";
    cout << endl;
    return 0;
  }
  ans = 1000000000;
  if (n <= 5) {
    for (i = 1; i <= 2; i++)
      for (j = 1; j <= 2; j++)
        for (k = 1; k <= 2; k++)
          for (a = 1; a <= 2; a++) {
            fix[1] = i;
            fix[2] = j;
            fix[3] = k;
            fix[4] = a;
            minn = 1000000000;
            maxx = -1000000000;
            for (x = 1; x <= 4; x++)
              for (y = x + 1; y <= 4; y++)
                if (fix[x] == fix[y]) {
                  if (x >= 3)
                    xx = x - 3 + n - 1;
                  else
                    xx = x;
                  if (y >= 3)
                    yy = y - 3 + n - 1;
                  else
                    yy = y;
                  p = d[xx].first + d[yy].first;
                  minn = min(minn, p);
                  maxx = max(maxx, p);
                } else {
                  if (x >= 3)
                    xx = x - 3 + n - 1;
                  else
                    xx = x;
                  if (y >= 3)
                    yy = y - 3 + n - 1;
                  else
                    yy = y;
                  p = d[xx].first + d[yy].first + h;
                  minn = min(minn, p);
                  maxx = max(maxx, p);
                }
            if (ans > maxx - minn) {
              ans = maxx - minn;
              for (ii = 1; ii <= n; ii++) F[ii] = 1;
              F[d[1].second] = fix[1];
              F[d[2].second] = fix[2];
              F[d[n - 1].second] = fix[3];
              F[d[n].second] = fix[4];
            }
          }
  } else
    for (i = 1; i <= 2; i++)
      for (j = 1; j <= 2; j++)
        for (t = 1; t <= 2; t++)
          for (k = 1; k <= 2; k++)
            for (a = 1; a <= 2; a++)
              for (tt = 1; tt <= 2; tt++) {
                fix[1] = i;
                fix[2] = j;
                fix[3] = t;
                fix[4] = k;
                fix[5] = a;
                fix[6] = tt;
                minn = 1000000000;
                maxx = -1000000000;
                for (x = 1; x <= 6; x++)
                  for (y = x + 1; y <= 6; y++)
                    if (fix[x] == fix[y]) {
                      if (x >= 4)
                        xx = x - 5 + n - 1;
                      else
                        xx = x;
                      if (y >= 4)
                        yy = y - 5 + n - 1;
                      else
                        yy = y;
                      p = d[xx].first + d[yy].first;
                      minn = min(minn, p);
                      maxx = max(maxx, p);
                    } else {
                      if (x >= 4)
                        xx = x - 5 + n - 1;
                      else
                        xx = x;
                      if (y >= 4)
                        yy = y - 5 + n - 1;
                      else
                        yy = y;
                      p = d[xx].first + d[yy].first + h;
                      minn = min(minn, p);
                      maxx = max(maxx, p);
                    }
                if (ans > maxx - minn) {
                  ans = maxx - minn;
                  for (ii = 1; ii <= n; ii++) F[ii] = 1;
                  F[d[1].second] = fix[1];
                  F[d[2].second] = fix[2];
                  F[d[3].second] = fix[3];
                  F[d[n - 2].second] = fix[4];
                  F[d[n - 1].second] = fix[5];
                  F[d[n].second] = fix[6];
                }
              }
  cout << ans << endl;
  for (i = 1; i <= n; i++) cout << F[i] << " ";
  cout << endl;
  return 0;
}
