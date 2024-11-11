#include <bits/stdc++.h>
using namespace std;
long long x[155][155];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, c, d, m, i, j, k;
  cin >> n;
  if (n == 1) {
    cout << "1\n0 1\n0\n1";
    return 0;
  }
  x[1][0] = 1;
  x[2][1] = 1;
  x[2][0] = 0;
  for (i = 3; i <= n + 2; i++) {
    for (j = i - 1; j >= 1; j--) {
      x[i][j] = x[i - 1][j - 1];
    }
    for (j = i - 3; j >= 0; j--) {
      x[i][j] += x[i - 2][j];
    }
    k = 0;
    for (j = i - 3; j >= 0; j--) {
      if (x[i][j] > 1 || x[i][j] < -1) {
        k = 1;
        break;
      }
    }
    if (k == 1) {
      for (j = i - 3; j >= 0; j--) {
        x[i][j] -= 2 * x[i - 2][j];
      }
    }
  }
  cout << n << "\n";
  for (i = 0; i <= n; i++) {
    cout << x[n + 1][i] << " ";
  }
  cout << "\n";
  cout << n - 1 << "\n";
  for (i = 0; i <= n - 1; i++) {
    cout << x[n][i] << " ";
  }
  return 0;
}
