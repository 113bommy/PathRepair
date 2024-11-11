#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, n, k, t, l, r, x, m, y;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x >> y;
    char arr[n][m];
    l = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> arr[i][j];
    if ((2 * x) < y) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (arr[i][j] == '.') l += x;
        }
      }
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (arr[i][j] == '.') {
            if (j != m - 1 && arr[i][j + 1] == '.') {
              l += y;
              j++;
            } else
              l += x;
          }
        }
      }
    }
    cout << l << endl;
  }
}
