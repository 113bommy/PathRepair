#include <bits/stdc++.h>
using namespace std;
const int N = 105000;
int n, m;
int nx, ny;
int dx, dy;
char dir[5];
bool up[N], down[N], leftt[N], rightt[N];
int cc = 0;
long long ans = 1;
void add() {
  if (nx == 1) {
    if (!up[ny]) {
      cc++;
      up[ny] = 1;
    }
  }
  if (nx == n) {
    if (!down[ny]) {
      cc++;
      down[ny] = 1;
    }
  }
  if (ny == 1) {
    if (!leftt[nx]) {
      cc++;
      leftt[nx] = 1;
    }
  }
  if (ny == m) {
    if (!rightt[nx]) {
      cc++;
      rightt[nx] = 1;
    }
  }
}
void Do() {
  int needx = max((1 - nx) / dx, (n - nx) / dx);
  int needy = max((1 - ny) / dy, (m - ny) / dy);
  int need = min(needx, needy);
  nx += dx * need;
  ny += dy * need;
  if (needx == need) dx = -dx;
  if (needy == need) dy = -dy;
  ans += need;
  add();
}
int main() {
  int i;
  scanf("%d%d%d%d%s", &n, &m, &nx, &ny, dir);
  int key = n / 2 + m / 2;
  key <<= 1;
  if (n & 1) {
    if ((nx + ny) % 2 == 0) key++;
    if ((nx + ny) % 2 == (1 + m) % 2) key++;
  }
  if (m & 1) {
    if ((nx + ny) % 2 == 0) key++;
    if ((nx + ny) % 2 == (1 + n) % 2) key++;
  }
  int maxz = (n + m) * 5;
  if (dir[0] == 'U')
    dx = -1;
  else
    dx = 1;
  if (dir[1] == 'L')
    dy = -1;
  else
    dy = 1;
  add();
  for (i = 1; i <= maxz; i++) {
    Do();
    if (cc == key) {
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
