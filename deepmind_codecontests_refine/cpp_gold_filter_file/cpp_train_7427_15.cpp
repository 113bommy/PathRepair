#include <bits/stdc++.h>
using namespace std;
const int MX = 2001;
int n, m, k, ax, ay, w[MX][MX];
bool u[MX][MX];
bool check(int x, int y, int k) {
  int l = max(1, x - k), r = min(n, x + k);
  for (int i = l, t; i <= r; i++) {
    t = k - abs(i - x);
    if (y - t > 0 && !u[i][y - t]) {
      ax = i, ay = y - t;
      return 1;
    }
    if (y + t <= m && !u[i][y + t]) {
      ax = i, ay = y + t;
      return 1;
    }
  }
  return 0;
}
void solve(int x, int y) {
  for (int i = -2; i <= 3; i++) {
    for (int j = -2; j <= 3; j++) {
      if (x + i < 1 || x + i > n || y + j < 1 || y + j > m) continue;
      w[x][y] = max(w[x][y], w[x + i][y + j] - abs(i) - abs(j));
    }
  }
  while (!check(x, y, w[x][y])) w[x][y]++;
  printf("%d %d\n", ax, ay);
  u[ax][ay] = 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1, x, y; i <= k; i++) {
    scanf("%d%d", &x, &y);
    solve(x, y);
  }
  return 0;
}
