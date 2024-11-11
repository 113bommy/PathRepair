#include <bits/stdc++.h>
using namespace std;
char a[2000][2000];
char used[2000][2000];
int n, ans1, ans2, xx1, x2, yy1, y2;
const int INF = 1000 * 1000 * 100;
void dd(int x, int y) {
  if (x < 0 || y < 0 || x >= n || y >= n || used[x][y]) return;
  xx1 = min(xx1, x);
  x2 = max(x2, x);
  yy1 = min(yy1, y);
  y2 = max(y2, y);
  used[x][y] = 1;
  if (a[x][y + 1] == '1') dd(x, y + 1);
  if (a[x + 1][y] == '1') dd(x + 1, y);
  if (a[x][y - 1] == '1') dd(x, y - 1);
  if (a[x - 1][y] == '1') dd(x - 1, y);
}
int main(void) {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!used[i][j] && a[i][j] == '1') {
        xx1 = INF;
        x2 = -INF;
        yy1 = INF;
        y2 = -INF;
        dd(i, j);
        if (a[xx1][yy1] == '1')
          ans1++;
        else
          ans2++;
      }
  cout << ans1 << " " << ans2;
  return 0;
}
