#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int x = 1, y, z, m, t = 0;
  cin >> n >> k;
  int a[n + 1][n + 1];
  int v = n * n, w = n - k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < k; j++) {
      a[i][j] = x;
      if (j < k - 1) x++;
    }
    x = x + k - 2;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = n; j >= k; j--) {
      a[i][j] = v;
      v--;
    }
  }
  for (int i = 1; i <= n; i++) t = t + a[i][k];
  cout << t << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
}
