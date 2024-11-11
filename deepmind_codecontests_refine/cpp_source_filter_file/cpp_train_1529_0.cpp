#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int A[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        A[i][j] = 1;
      } else {
        A[i][j] = 0;
      }
    }
  }
  int B[n][m];
  for (int i = 0; i < m; i++) {
    B[0][i] = A[0][i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      B[i][j] = B[i - 1][j] + A[i][j];
    }
  }
  int flag = 0;
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < m; j++) {
      if (B[i][j] - A[i][j] > 0) {
        count++;
      }
    }
    if (count == m) {
      flag = 1;
      break;
    }
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
