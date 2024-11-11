#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    long long a[2][m];
    bool b[2][m];
    long long c[2][m];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        b[i][j] = 0;
      }
    }
    if (m == 1) {
      cout << 0;
    } else {
      c[0][m - 1] = a[0][m - 1];
      for (int i = m - 2; i >= 1; i--) {
        c[0][i] = a[0][i];
        c[0][i] += c[0][i + 1];
      }
      long long maxx = c[0][1];
      c[1][0] = a[1][0];
      for (int i = 1; i < m - 1; i++) {
        c[1][i] = a[1][i];
        c[1][i] += c[1][i - 1];
      }
      if (c[1][m - 2] < maxx) {
        maxx = c[1][m - 2];
      }
      long long u;
      for (int i = 1; i <= m - 2; i++) {
        u = max(c[0][i + 1], c[1][i - 1]);
        if (u < maxx) {
          maxx = u;
        }
      }
      cout << maxx << endl;
    }
  }
}
