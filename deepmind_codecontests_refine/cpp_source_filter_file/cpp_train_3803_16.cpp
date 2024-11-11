#include <bits/stdc++.h>
using namespace std;
const int minf = -1e9 - 100;
int a[100][100];
int d[10000][4];
int main() {
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) a[i][j] = minf;
  for (int i = 0; i < q; i++) {
    cin >> d[i][0] >> d[i][1];
    if (d[i][0] == 3) {
      cin >> d[i][2] >> d[i][3];
    }
  }
  for (int i = q - 1; i >= 0; i--) {
    if (d[i][0] == 3) {
      a[d[i][1] - 1][d[i][2] - 1] = d[i][3];
    } else if (d[i][0] == 1) {
      int l = 0, r = m - 1;
      while (l < r) {
        swap(a[d[i][1] - 1][l], a[d[i][1] - 1][r]);
        l++;
        r--;
      }
      l = 1, r = m - 1;
      while (l < r) {
        swap(a[d[i][1] - 1][l], a[d[i][1] - 1][r]);
        l++;
        r--;
      }
    } else {
      int l = 0, r = n - 1;
      while (l < r) {
        swap(a[l][d[i][1] - 1], a[r][d[i][1] - 1]);
        l++;
        r--;
      }
      l = 1, r = n - 1;
      while (l < r) {
        swap(a[l][d[i][1] - 1], a[r][d[i][1] - 1]);
        l++;
        r--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != minf)
        cout << a[i][j] << ' ';
      else
        cout << 0;
    }
    cout << '\n';
  }
  return 0;
}
