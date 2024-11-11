#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int total, n = 100, i, j, k, s, ct;
  cin >> total;
  s = 0;
  vector<vector<bool>> conn(n, vector<bool>(n, false));
  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      ct = 0;
      for (k = 0; k < n; k++) {
        if ((i != k) && (j != k) && conn[i][k] && conn[k][j]) ct++;
      }
      if (s + ct <= total) {
        s += ct;
        conn[i][j] = true;
        conn[j][i] = true;
      }
    }
  }
  cout << n << "\n";
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (conn[i][j])
        cout << "1";
      else
        cout << "0";
    }
    cout << "\n";
  }
  return 0;
}
