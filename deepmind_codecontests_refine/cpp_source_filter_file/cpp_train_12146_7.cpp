#include <bits/stdc++.h>
using namespace std;
long long dx[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
long long dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};
void solve() {
  long long n, m;
  cin >> n >> m;
  char a[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> a[i][j];
  }
  bool f = 1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        for (long long k = 0; k < 8; k++) {
          long long x = i + dx[k];
          long long y = j + dy[k];
          if (i < 0 || i >= n || j < 0 || j >= m) continue;
          if (a[x][y] == '*') {
            cout << "NO";
            return;
          }
        }
      } else if (a[i][j] >= '1' && a[i][j] <= '8') {
        long long cnt = 0;
        for (long long k = 0; k < 8; k++) {
          long long x = i + dx[k];
          long long y = j + dy[k];
          if (i < 0 || i >= n || j < 0 || j >= m) continue;
          if (a[x][y] == '*') cnt++;
        }
        if (cnt != a[i][j] - '0') {
          cout << "NO";
          return;
        }
      }
    }
  }
  cout << "YES";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
