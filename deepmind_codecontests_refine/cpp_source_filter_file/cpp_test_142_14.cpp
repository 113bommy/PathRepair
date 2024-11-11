#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    cin >> m >> n;
    int p[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> p[i][j];
      }
    }
    int l = 1, r = 1e9;
    while (l < r) {
      int mid = (l + r) / 2;
      int colum[n];
      int sum = 0;
      memset(colum, 0, sizeof(colum));
      bool buy_two = false;
      for (int i = 0; i < m; i++) {
        int tmp_sum = 0;
        int tmp_sum2 = 0;
        for (int j = 0; j < n; j++) {
          if (p[i][j] >= mid && colum[j] == 0) {
            colum[j] = 1;
            tmp_sum += 1;
          }
          if (p[i][j] >= mid) {
            tmp_sum2 += 1;
          }
          if (tmp_sum2 > 1) buy_two = true;
        }
        sum += tmp_sum;
      }
      if (sum >= n && buy_two) {
        l = mid;
      } else
        r = mid;
      if (l + 1 == r) {
        cout << l << endl;
        break;
      }
    }
  }
  return 0;
}
