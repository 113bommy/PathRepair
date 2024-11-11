#include <bits/stdc++.h>
using namespace std;
int n, k, e, d, ex, ey;
long long x[6666], y[6666], zx[6666], zy[6666], ans = 0, xx, yy;
bool w[6555][6555], u[6555][6555];
pair<long long, int> q[6666];
char o;
void rec(int x, int y) {
  if (x < 0 || y < 0 || x > e + 4 || y > e + 4 || w[x][y] || u[x][y]) return;
  u[x][y] = 1;
  rec(x - 1, y);
  rec(x + 1, y);
  rec(x, y - 1);
  rec(x, y + 1);
}
int main() {
  cin >> n;
  x[0] = y[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> o >> d;
    x[i + 1] = x[i];
    y[i + 1] = y[i];
    if (o == 'R') x[i + 1] += d;
    if (o == 'L') x[i + 1] -= d;
    if (o == 'U') y[i + 1] += d;
    if (o == 'D') y[i + 1] -= d;
  }
  k = 0;
  for (int i = 0; i <= n; i++) {
    q[k++] = make_pair(x[i], i);
    q[k++] = make_pair(x[i] - 1, -1);
    q[k++] = make_pair(x[i] + 1, -1);
  }
  sort(q, q + k);
  e = 2;
  for (int i = 0; i < k; i++) {
    if (!i || q[i - 1].first != q[i].first) e++;
    zx[e] = q[i].first;
    if (q[i].second != -1) x[q[i].second] = e;
  }
  ex = e;
  k = 0;
  for (int i = 0; i <= n; i++) {
    q[k++] = make_pair(y[i], i);
    q[k++] = make_pair(y[i] - 1, -1);
    q[k++] = make_pair(y[i] + 1, -1);
  }
  sort(q, q + k);
  e = 2;
  for (int i = 0; i < k; i++) {
    if (!i || q[i - 1].first != q[i].first) e++;
    zy[e] = q[i].first;
    if (q[i].second != -1) y[q[i].second] = e;
  }
  ey = e;
  w[x[0]][y[0]] = 1;
  for (int i = 0; i < n; i++) {
    xx = x[i];
    yy = y[i];
    while (xx != x[i + 1] || yy != y[i + 1]) {
      if (xx < x[i + 1]) xx++;
      if (xx > x[i + 1]) xx--;
      if (yy < y[i + 1]) yy++;
      if (yy > y[i + 1]) yy--;
      w[xx][yy] = 1;
    }
  }
  rec(0, 0);
  for (int i = 0; i <= ex; i++)
    for (int j = 0; j <= ey; j++)
      if (!u[i][j]) {
        ans += (zx[i] - zx[i - 1]) * 1ll * (zy[j] - zy[j - 1]);
      }
  cout << (ans) << endl;
  return 0;
}
