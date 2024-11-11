#include <bits/stdc++.h>
using namespace std;
int n, m, s, dx, dy;
long long ans;
map<pair<int, int>, int> h;
char a[5];
void work(int x, int y) {
  int nx, ny, t;
  if (dx == -1)
    t = x - 1;
  else
    t = n - x;
  if (dy == -1)
    t = min(t, y - 1);
  else
    t = min(t, m - y);
  ans += t;
  x += dx * t;
  y += dy * t;
  h[make_pair(x, y)]++;
  t = h[make_pair(x, y)];
  if (t == 1)
    s--;
  else if (t >= 3) {
    printf("%d\n", -1);
    return;
  }
  if (s == 0) {
    printf("%I64d\n", ans + 1);
    return;
  }
  if (x == 1 || x == n) dx *= -1;
  if (y == 1 || y == m) dy *= -1;
  work(x, y);
}
void check(int x, int y, int k) {
  if ((x + y) % 2 == k % 2 && h.find(make_pair(x, y)) == h.end()) {
    h[make_pair(x, y)] = 1;
    s++;
  }
}
int main() {
  int i, j, x, y;
  scanf("%d%d", &n, &m);
  scanf("%d%d%s", &x, &y, a + 1);
  for (i = 1; i <= n; i++) {
    check(i, 1, x + y);
    check(i, m, x + y);
  }
  for (j = 1; j <= m; j++) {
    check(1, j, x + y);
    check(n, j, x + y);
  }
  h.clear();
  if (a[1] == 'D')
    dx = 1;
  else
    dx = -1;
  if (a[2] == 'R')
    dy = 1;
  else
    dy = -1;
  if ((x == 1 && dx == -1) || (x == n && dx == 1)) dx *= -1;
  if ((y == 1 && dy == -1) || (y == m && dy == 1)) dy *= -1;
  h[make_pair(x, y)] = 1;
  s--;
  work(x, y);
  return 0;
}
