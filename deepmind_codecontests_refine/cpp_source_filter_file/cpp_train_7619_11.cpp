#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int a[N][N];
int main() {
  int n, m;
  cin >> n >> m;
  bool flag = false;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      sum += a[i][j];
    }
  }
  for (int i = n; i >= 1 && !flag; i--) {
    for (int j = m; j >= 1; j--) {
      if (!a[i][j]) {
        a[i][j] = min(a[i + 1][j], a[i][j + 1]) - 1, sum += a[i][j];
      } else {
        if ((i < n && a[i][j] >= a[i + 1][j]) &&
            (j < m && a[i][j] >= a[i][j + 1])) {
          flag = true;
          break;
        }
      }
    }
  }
  if (!flag)
    cout << sum << endl;
  else
    cout << "-1" << endl;
  return 0;
}
