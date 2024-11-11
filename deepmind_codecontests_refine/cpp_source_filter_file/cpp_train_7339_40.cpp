#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const int LINF = numeric_limits<int>::max();
const double EPS = 1e-9;
const int MAXN = 1e5 + 5;
void solve() {
  int n = 8;
  int mAW = INF;
  int mBB = INF;
  char f[n][n];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) cin >> f[i][j];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (f[i][j] == '.') continue;
      if (f[i][j] == 'W') {
        bool free = true;
        for (int k = i - 1; k >= 0; --k)
          if (f[k][j] != '.') free = false;
        if (free) mAW = min(mAW, i);
      } else {
        bool free = true;
        for (int k = i + 1; k < 8; ++k)
          if (f[k][j] != '.') free = false;
        if (free) mBB = min(mBB, 8 - i);
      }
    }
  }
  if (mAW <= mBB)
    cout << 'A';
  else
    cout << 'B';
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
