#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n;
  cin >> n;
  long long int a[n][n];
  map<long long int, long long int> sum;
  map<long long int, long long int> dif;
  long long int ans[n][n][2];
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  long long int s, d;
  long long int b = 0, w = 0, x, y;
  long long int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < n; ++j) {
      s = i + j;
      x = i;
      y = j;
      d = j - i;
      if (!dif[d]) {
        dif[d] += a[x][y];
        while (x >= 0 && x < n - 1 && y >= 0 && y < n - 1) {
          x++;
          y++;
          dif[d] += a[x][y];
        }
      }
      x = i;
      y = j;
      if (!sum[s]) {
        sum[s] += a[x][y];
        while (x >= 0 && x < n - 1 && y > 0 && y < n) {
          x++;
          y--;
          sum[s] += a[x][y];
        }
      }
      if (s & 1) {
        ans[i][j][0] = dif[d] + sum[s] - a[i][j];
        if (b < ans[i][j][0]) {
          b = ans[i][j][0];
          x1 = i;
          y1 = j;
        }
      } else {
        ans[i][j][1] = dif[d] + sum[s] - a[i][j];
        if (w < ans[i][j][1]) {
          w = ans[i][j][1];
          x2 = i;
          y2 = j;
        }
      }
    }
  }
  cout << b + w << endl;
  cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1;
  return 0;
}
