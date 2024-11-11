#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long sum = 0;
  int null = 0;
  int **arr = new int *[n + 1];
  int left = 0;
  for (int i = 1; i <= n; i++) {
    arr[i] = new int[m + 1];
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      if (arr[i][j]) {
        if (left && !arr[i][j - 1]) {
          sum += (null * 2);
          null = 0;
        }
        if (j == 1)
          left = 1;
        else {
          left = 1;
          sum += null;
          null = 0;
        }
      } else
        null++;
      if (j == m && null && left) {
        sum += null;
        null = 0;
        left = 0;
      } else if (j == m && !left || j == m && left) {
        null = 0;
        left = 0;
      }
    }
  }
  if (n > 1) {
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (arr[j][i]) {
          if (left && !arr[j - 1][i]) {
            sum += (null * 2);
            null = 0;
          }
          if (j == 1)
            left = 1;
          else {
            left = 1;
            sum += null;
            null = 0;
          }
        } else
          null++;
        if (j == n && null && left) {
          sum += null;
          null = 0;
          left = 0;
        } else if (j == n && !left || j == n && left) {
          null = 0;
          left = 0;
        }
      }
    }
  }
  cout << sum;
  return 0;
}
