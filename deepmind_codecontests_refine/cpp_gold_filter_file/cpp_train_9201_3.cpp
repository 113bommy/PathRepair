#include <bits/stdc++.h>
using namespace std;
int p[1000][1000], used[1000][1000];
queue<pair<int, int> > q;
int main() {
  int n, t, k, l, x, y, i;
  scanf("%d%d", &n, &t);
  q.push(make_pair(500, 500));
  p[500][500] = n;
  used[500][500] = 1;
  while (q.size()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    k = p[x][y] / 4;
    p[x][y] %= 4;
    p[x + 1][y] += k;
    if (!used[x + 1][y] && p[x + 1][y] >= 4)
      used[x + 1][y] = 1, q.push(make_pair(x + 1, y));
    p[x - 1][y] += k;
    if (!used[x - 1][y] && p[x - 1][y] >= 4)
      used[x - 1][y] = 1, q.push(make_pair(x - 1, y));
    p[x][y + 1] += k;
    if (!used[x][y + 1] && p[x][y + 1] >= 4)
      used[x][y + 1] = 1, q.push(make_pair(x, y + 1));
    p[x][y - 1] += k;
    if (!used[x][y - 1] && p[x][y - 1] >= 4)
      used[x][y - 1] = 1, q.push(make_pair(x, y - 1));
    used[x][y] = 0;
  }
  for (i = 1; i <= t; i++) {
    scanf("%d%d", &x, &y);
    if (abs(x) > 400 || abs(y) > 400)
      cout << 0 << endl;
    else
      cout << p[500 + x][500 + y] << endl;
  }
  return 0;
}
