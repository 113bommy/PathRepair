#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-9;
const int inf = 1e9;
int a[555][55], b[555][555];
int main() {
  int n, m, cnt0 = 0, cnt1 = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> b[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        if (i == n - 1 || j == m - 1) {
          cout << "NO";
          return 0;
        }
        a[i][j] ^= 1;
        a[i + 1][j] ^= 1;
        a[i][j + 1] ^= 1;
        a[i + 1][j + 1] ^= 1;
      }
    }
  }
  cout << "YES";
}
