#include <bits/stdc++.h>
using namespace std;
int A[30][30];
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n, m, i, j, k, x, y, z, a, b, c;
  cin >> n >> m;
  x = 0;
  for (i = 1; i <= n; ++i) {
    c = 0;
    for (j = 1; j <= m; ++j) {
      cin >> A[i][j];
      if (A[i][j] != j) c++;
    }
    if (c > 4) {
      cout << -1 << endl;
      return 0;
    }
    x += (c < 3);
  }
  if (x == n) {
    cout << "YES" << endl;
    return 0;
  }
  for (i = 1; i <= m; ++i) {
    for (j = i + 1; j <= m; ++j) {
      for (k = 1; k <= n; ++k) {
        swap(A[k][i], A[k][j]);
      }
      x = 0;
      for (a = 1; a <= n; ++a) {
        y = 0;
        for (b = 1; b <= m; ++b) {
          y += (A[a][b] != b);
        }
        x += (y <= 2);
      }
      if (x == n) {
        cout << "YES" << endl;
        return 0;
      }
      for (k = 1; k <= n; ++k) {
        swap(A[k][i], A[k][j]);
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
