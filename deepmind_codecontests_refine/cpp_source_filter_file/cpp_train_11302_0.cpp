#include <bits/stdc++.h>
using namespace std;
long long kx, ky, n;
int direction(long long x, long long y) {
  if (y == ky) {
    if (x > kx) {
      return 1;
    } else {
      return 5;
    }
  }
  if (x == kx) {
    if (y > ky) {
      return 3;
    } else {
      return 7;
    }
  }
  long long dy = y - ky;
  long long dx = x - kx;
  double diff = dy / (double)dx;
  diff = 1.0 - abs(diff);
  if (diff == 0) {
    if (x > kx and y > ky) {
      return 2;
    }
    if (x > kx) {
      return 7;
    }
    if (y > ky) {
      return 4;
    } else {
      return 6;
    }
  }
  return 0;
}
long long dist(long long x, long long y) {
  return (kx - x) * (kx - x) + (ky - y) * (ky - y);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> kx >> ky;
  char c[n];
  long long x[n], y[n];
  long long d[9];
  memset(d, -1, sizeof d);
  for (long long i = 0; i < n; ++i) {
    cin >> c[i] >> x[i] >> y[i];
    long long dir = direction(x[i], y[i]);
    if (dir > 0) {
      if (d[dir] == -1) {
        d[dir] = dist(x[i], y[i]);
      } else {
        d[dir] = min(d[dir], dist(x[i], y[i]));
      }
    }
  }
  for (long long i = 0; i < n; ++i) {
    int dir = direction(x[i], y[i]);
    long long dis = dist(x[i], y[i]);
    if (c[i] == 'R') {
      if (dir == 1 or dir == 3 or dir == 5 or dir == 7) {
        if (dis == d[dir]) {
          cout << "YES\n";
          return 0;
        }
      }
    }
    if (c[i] == 'B') {
      if (dir == 2 or dir == 4 or dir == 6 or dir == 8) {
        if (dis == d[dir]) {
          cout << "YES\n";
          return 0;
        }
      }
    }
    if (c[i] == 'Q') {
      if (dis == d[dir]) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
