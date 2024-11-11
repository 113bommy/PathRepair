#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  char snake[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i % 2 == 0) {
        snake[i][j] = '#';
      } else {
        snake[i][j] = '.';
      }
    }
  }
  long long counter = 0, j = m - 1;
  for (long long i = 0; i < n; i++) {
    if (i % 2 != 0) {
      counter++;
      if (counter % 2 != 0) {
        snake[i][j] = '#';
        j = 0;
      } else if (counter % 2 == 0) {
        snake[i][j] = '#';
        j = m - 1;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cout << snake[i][j];
    }
    cout << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long testcases = 1;
  while (testcases--) {
    solve();
  }
  return 0;
}
