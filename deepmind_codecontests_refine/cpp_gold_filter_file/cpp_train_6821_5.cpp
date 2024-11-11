#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
int r[N][2];
int c[N][2];
int main() {
  ios::sync_with_stdio(0);
  int m, n, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) {
    int x, pro, col;
    cin >> x >> pro >> col;
    if (x == 1) {
      r[pro][0] = col;
      r[pro][1] = i;
    } else {
      c[pro][0] = col;
      c[pro][1] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (r[i][1] > c[j][1]) {
        cout << r[i][0] << " ";
      } else {
        cout << c[j][0] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
