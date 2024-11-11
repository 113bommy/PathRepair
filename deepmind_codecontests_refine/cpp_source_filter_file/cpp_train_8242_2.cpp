#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, mod = 1e9 + 7, mod1 = 998242353, mod2 = 1e9 + 9,
                inf = 1e9 + 7;
const long long infll = 1e18 + 7;
long long n, m, k;
vector<long long> row[N], col[N];
void cango(long long x, long long y, long long dx, long long dy,
           long long &desx, long long &desy, long long lx, long long rx,
           long long ly, long long ry) {
  if (dx == 0) {
    desx = x;
    if (dy == 1) {
      auto k = lower_bound(row[x].begin(), row[x].end(), y + 1);
      if (k == row[x].end()) {
        desy = m;
      } else {
        desy = row[x][k - row[x].begin()] - 1;
      }
      if (desy > ry) desy = ry;
    } else {
      auto k = lower_bound(row[x].begin(), row[x].end(), y);
      k--;
      if (k == (--row[x].begin())) {
        desy = 1;
      } else {
        desy = row[x][k - row[x].begin()] + 1;
      }
      if (desy < ly) desy = ly;
    }
  } else {
    desy = y;
    if (dx == 1) {
      auto k = lower_bound(col[y].begin(), col[y].end(), x + 1);
      if (k == col[y].end()) {
        desx = n;
      } else {
        desx = col[y][k - col[y].begin()] - 1;
      }
      if (desx > rx) desx = rx;
    } else {
      auto k = lower_bound(col[y].begin(), col[y].end(), x);
      k--;
      if (k == (--col[y].begin())) {
        desx = 1;
      } else {
        desx = col[y][k - col[y].begin()] + 1;
      }
      if (desx < lx) desx = lx;
    }
  }
}
void cnv(long long &dx, long long &dy) {
  if (dx == 0 && dy == 1) {
    dx = 1;
    dy = 0;
  } else if (dx == 1 && dy == 0) {
    dx = 0;
    dy = -1;
  } else if (dx == 0 && dy == -1) {
    dx = -1;
    dy = 0;
  } else {
    dx = 0;
    dy = 1;
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (long long i = 1; i <= k; i++) {
    long long x, y;
    cin >> x >> y;
    row[x].push_back(y);
    col[y].push_back(x);
  }
  for (long long i = 1; i <= n; i++) {
    sort(row[i].begin(), row[i].end());
  }
  for (long long j = 1; j <= m; j++) {
    sort(col[j].begin(), col[j].end());
  }
  long long ans = 1;
  long long dx = 0, dy = 1;
  long long xx = 1, yy = 1, nx = 1, ny = m, lx = 1, rx = n, ly = 1, ry = m;
  do {
    cango(xx, yy, dx, dy, nx, ny, lx, rx, ly, ry);
    if (nx == xx && ny == yy) break;
    ans += abs(nx - xx) + abs(ny - yy);
    if (dx == 0 && dy == 1) {
      lx = xx + 1;
    }
    if (dx == 0 && dy == -1) {
      rx = xx - 1;
    }
    if (dx == 1 && dy == 0) {
      ry = yy - 1;
    }
    if (dx == -1 && dy == 0) {
      ly = yy + 1;
    }
    xx = nx;
    yy = ny;
    cnv(dx, dy);
  } while (1);
  if (n * m - ans == k) return cout << "Yes", 0;
  ;
  cout << "No";
}
