#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const long long dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1},
                dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const long long kdx[8] = {-2, -1, 1, 2, 2, 1, -1, -2},
                kdy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void solve() {
  long long n, m;
  cin >> n >> m;
  char a[n][m];
  long long cnt = 0;
  for (long long i = 0; i <= n - 1; ++i) {
    for (long long j = 0; j <= m - 1; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'B') cnt++;
    }
  }
  long long minx = LLONG_MAX, miny = LLONG_MAX, maxx = -1, maxy = -1;
  for (long long i = 0; i <= n - 1; ++i) {
    for (long long j = 0; j <= m - 1; ++j) {
      if (a[i][j] == 'B') {
        minx = min(minx, i);
        maxx = max(maxx, i);
        miny = min(miny, j);
        maxy = max(maxy, j);
      }
    }
  }
  if (cnt == 0) {
    cout << 1 << "\n";
    return;
  }
  cerr << maxx << ' ' << maxy << ' ' << minx << ' ' << miny << "\n";
  if (minx == -1 || maxx == -1 || miny == -1 || maxy == -1) {
    cout << -1 << "\n";
    return;
  }
  long long len = max(maxx - minx + 1, maxy - miny + 1);
  if (len > m || len > n) {
    cout << -1 << "\n";
    return;
  }
  cout << len * len - cnt << "\n";
}
int32_t main() {
  clock_t start = clock();
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (long long i = 1; i <= t; ++i) {
    solve();
  }
  double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
  cerr << duration << 's' << "\n";
  return 0;
}
