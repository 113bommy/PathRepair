#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, count_zero = 0, count_max = 0;
  cin >> n >> m;
  int data[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> data[i][j];
      count_max += data[i][j];
      if (data[i][j] == 0) {
        count_zero++;
      }
    }
  }
  for (int i = n - 2; i >= 1; i--) {
    for (int j = m - 2; j >= 1; j--) {
      int h_d = data[i][j + 1] - data[i][j - 1],
          v_d = data[i + 1][j] - data[i - 1][j];
      if (data[i][j] == 0 && h_d > 1 && v_d > 1) {
        data[i][j] = min(data[i + 1][j] - 1, data[i][j + 1] - 1);
        count_max += data[i][j];
      } else if (h_d <= 1 || v_d <= 1) {
        cout << "-1";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (data[i][j] <= data[i][j - 1]) {
        cout << "-1";
        return 0;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (data[j][i] <= data[j - 1][i]) {
        cout << "-1";
        return 0;
      }
    }
  }
  cout << count_max;
  return 0;
}
