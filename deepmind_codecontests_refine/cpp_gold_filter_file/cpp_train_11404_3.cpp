#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  int a[100][100] = {};
  int all = ((1 + n) * n) / 2;
  a[1][1] = 1024 * t;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= i; j++) {
      if (a[i][j] > 1024) {
        a[i + 1][j] += (a[i][j] - 1024) / 2;
        a[i + 1][j + 1] += (a[i][j] - 1024) / 2;
        a[i][j] = 1024;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (a[i][j] == 1024) ans++;
    }
  }
  cout << min(all, ans);
  return 0;
}
