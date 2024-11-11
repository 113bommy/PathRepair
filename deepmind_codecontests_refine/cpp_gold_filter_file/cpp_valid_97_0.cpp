#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long dx[] = {0, 0, -1, 1};
long long dy[] = {1, -1, 0, 0};
long long grid[505][505];
char ogrid[505][505];
long long n, m;
bool valid(long long x, long long y) {
  return ((x > 0) && (x <= n) && (y > 0) && (y <= m));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cin >> ogrid[i][j];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (ogrid[i][j] == 'X') {
        long long unmarked = 0;
        for (long long d = 0; d < 4; d++) {
          long long ni = i + dx[d], nj = j + dy[d];
          if (valid(ni, nj)) {
            if (ogrid[ni][nj] == '.') unmarked++;
          }
        }
        if (unmarked & 1) {
          cout << "NO\n";
          return 0;
        }
      }
    }
  }
  cout << "YES\n";
  long long cur = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (ogrid[i][j] == 'X') {
        if (ogrid[i - 1][j] == 'X') cur ^= 1;
        continue;
      }
      if ((i + cur) & 1)
        grid[i][j] = 1;
      else
        grid[i][j] = 4;
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (ogrid[i][j] == 'X') {
        for (long long d = 0; d < 4; d++) {
          long long ni = i + dx[d], nj = j + dy[d];
          if ((valid(ni, nj)) && (ogrid[ni][nj] == '.'))
            grid[i][j] += grid[ni][nj];
        }
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) cout << grid[i][j] << " ";
    cout << "\n";
  }
}
