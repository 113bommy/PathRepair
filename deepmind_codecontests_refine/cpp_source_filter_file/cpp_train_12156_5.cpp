#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  char arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '*') continue;
      int counter = 0;
      for (int k = i - 1; k <= i + 1; k++) {
        if (k < 0 || k > n) continue;
        for (int kk = j - 1; kk <= j + 1; kk++) {
          if (kk < 0 || kk > m) continue;
          if (arr[k][kk] == '*') counter++;
        }
      }
      if (arr[i][j] == '.') {
        if (counter != 0) {
          cout << "NO";
          return 0;
        }
      } else if (arr[i][j] == '1' || arr[i][j] == '8' || arr[i][j] == '2' ||
                 arr[i][j] == '3' || arr[i][j] == '4' || arr[i][j] == '5' ||
                 arr[i][j] == '6' || arr[i][j] == '7') {
        if (counter != arr[i][j] - '0') {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
  return 0;
}
