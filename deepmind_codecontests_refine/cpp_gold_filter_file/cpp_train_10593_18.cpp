#include <bits/stdc++.h>
using namespace std;
int x[3][5], y[3][5], xx, yy, p, q, p1, q1, t;
bool flag, a[205][205], b1[205][205], b2[205][205];
int main() {
  for (int i = 0; i < 4; i++) cin >> x[1][i] >> y[1][i];
  for (int i = 0; i < 4; i++) cin >> x[2][i] >> y[2][i];
  p = min(x[1][0], x[1][2]);
  q = max(x[1][0], x[1][2]);
  p1 = min(y[1][0], y[1][2]);
  q1 = max(y[1][0], y[1][2]);
  for (int i = p; i <= q; i++)
    for (int j = p1; j <= q1; j++) b1[i + 100][j + 100] = 1;
  for (int i = 0; i < 4; i++)
    if (b1[x[2][i] + 100][y[2][i] + 100]) flag = 1;
  p = min(x[2][0], x[2][2]);
  q = max(x[2][0], x[2][2]);
  p1 = min(y[2][0], y[2][2]);
  q1 = max(y[2][0], y[2][2]);
  p1 = (p1 + q1) / 2;
  t = -1;
  for (int i = p; i <= (q + p) / 2; i++) {
    t++;
    for (int j = p1 - t; j <= p1 + t; j++) b2[i + 100][j + 100] = 1;
  }
  for (int i = (q + p) / 2 + 1; i <= q; i++) {
    t--;
    for (int j = p1 - t; j <= p1 + t; j++) b2[i + 100][j + 100] = 1;
  }
  for (int i = 0; i < 4; i++)
    if (b2[x[1][i] + 100][y[1][i] + 100]) flag = 1;
  for (int i = 0; i < 4; i++) {
    if (x[1][(i + 1) % 4] == x[1][i]) {
      p = min(y[1][i], y[1][(i + 1) % 4]);
      q = max(y[1][i], y[1][(i + 1) % 4]);
      for (yy = p; yy <= q; yy++) a[x[1][i] + 100][yy + 100] = 1;
    }
    if (y[1][(i + 1) % 4] == y[1][i]) {
      p = min(x[1][i], x[1][(i + 1) % 4]);
      q = max(x[1][i], x[1][(i + 1) % 4]);
      for (xx = p; xx <= q; xx++) a[xx + 100][y[1][i] + 100] = 1;
    }
  }
  for (int i = 0; i < 4; i++) {
    p = min(x[2][i], x[2][(i + 1) % 4]);
    q = max(x[2][i], x[2][(i + 1) % 4]);
    for (xx = p; xx <= q; xx++) {
      yy = y[2][i] + (y[2][(i + 1) % 4] - y[2][i]) * (xx - x[2][i]) /
                         (x[2][(i + 1) % 4] - x[2][i]);
      if (a[xx + 100][yy + 100]) flag = 1;
    }
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
}
