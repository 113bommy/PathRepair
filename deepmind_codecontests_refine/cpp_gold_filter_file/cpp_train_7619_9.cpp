#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  long long int sum = 0;
  int check = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      sum += a[i][j];
      if (a[i][j] <= a[i][j - 1] && j != 0 && a[i][j] != 0) check = 1;
      if (a[i][j] <= a[i - 1][j] && i != 0 && a[i][j] != 0) check = 1;
    }
  }
  if (check == 1)
    cout << "-1" << endl;
  else {
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (a[i][j] == 0) {
          int k = abs(a[i][j - 1] - a[i][j + 1]);
          int l = abs(a[i - 1][j] - a[i + 1][j]);
          int p = min(a[i][j + 1], a[i + 1][j]);
          p -= 1;
          if (p > a[i][j - 1] && p > a[i - 1][j]) {
            sum += p;
            a[i][j] = p;
          } else {
            cout << "-1" << endl;
            return 0;
          }
        }
      }
    }
    cout << sum << endl;
  }
}
