#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[k][2];
  int b[k][2];
  int max_row = 0;
  int max_col = 0;
  for (int i = 0; i < k; ++i) {
    cin >> a[i][0] >> a[i][1];
    max_row = max(max_row, a[i][0]);
    max_col = max(max_col, a[i][1]);
  }
  for (int i = 0; i < k; ++i) {
    cin >> b[i][0] >> b[i][1];
    max_row = max(max_row, b[i][0]);
    max_col = max(max_col, b[i][1]);
  }
  max_row = n;
  max_col = m;
  cout << m * n + n + m - 3 << endl;
  for (int i = 0; i < n - 1; ++i) {
    cout << "U";
  }
  for (int i = 0; i < m - 1; ++i) {
    cout << "L";
  }
  int cnt = 0;
  for (int i = 0; i < max_col - 1; ++i) {
    cout << "R";
  }
  for (int i = 1; i < max_row; ++i) {
    cout << "D";
    for (int j = 1; j < max_col; ++j) {
      if (cnt & 1) {
        cout << "R";
      } else {
        cout << "L";
      }
    }
    cnt++;
  }
}
