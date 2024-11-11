#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << "-1\n";
  } else {
    for (int lay = 1; lay <= n; lay++) {
      int mat[n][n];
      int v = (lay & 1), l = 0, r = n - 1;
      for (int i = 0; i < n / 2; i++, v ^= 1) {
        for (int j = l; j <= r; j++) {
          mat[l][j] = mat[r][j] = mat[j][l] = mat[j][r] = v;
        }
        l++;
        r--;
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (mat[i][j] ? 'b' : 'w') << " ";
        cout << '\n';
      }
      cout << "\n";
    }
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  cerr << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";
  return 0;
}
