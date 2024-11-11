#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long c = 2000000007;
  long long a[3][3], b[3][3];
  for (long long i = 0; i < 3; ++i) {
    for (long long j = 0; j < 3; ++j) {
      a[i][j] = c;
      b[i][j] = c + 1;
    }
  }
  long long xt, yt, n;
  cin >> n >> xt >> yt;
  for (long long i = 0; i < n; ++i) {
    char c;
    long long x, y;
    cin >> c >> x >> y;
    x -= xt;
    y -= yt;
    long long tx = x / max(abs(x), (long long)1) + 1,
              ty = y / max(abs(y), (long long)1) + 1, le = max(abs(x), abs(y));
    if (abs(x) == abs(y)) {
      if (c == 'B' || c == 'Q') {
        a[tx][ty] = min(le, a[tx][ty]);
      }
      b[tx][ty] = min(le, b[tx][ty]);
    }
    if (x == 0 || y == 0) {
      if (c == 'B' || c == 'Q') {
        a[tx][ty] = min(le, a[tx][ty]);
      }
      b[tx][ty] = min(le, b[tx][ty]);
    }
  }
  for (long long i = 0; i < 3; ++i) {
    for (long long j = 0; j < 3; ++j) {
      if (a[i][j] == b[i][j]) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
