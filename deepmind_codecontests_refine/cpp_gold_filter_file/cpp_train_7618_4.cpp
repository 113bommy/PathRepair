#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int m, n;
  unsigned long long int sum = 0;
  cin >> m >> n;
  unsigned long long int a[505][505];
  for (unsigned long long int i = 1; i <= m; i++) {
    for (unsigned long long int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (unsigned long long int i = m; i >= 1; i--)
    for (unsigned long long int j = n; j >= 1; j--) {
      if (a[i][j] == 0) a[i][j] = min(a[i][j + 1], a[i + 1][j]) - 1;
      if (a[i][j] <= a[i - 1][j] || a[i][j] <= a[i][j - 1]) {
        cout << -1;
        return 0;
      }
      sum += a[i][j];
    }
  cout << sum << endl;
}
