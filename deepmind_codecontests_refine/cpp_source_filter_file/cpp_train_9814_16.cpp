#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j;
  cin >> n;
  int N = 5000, a[N], b[N], f[2][N];
  for (i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
  sort(b, b + n);
  k = unique(b, b + n) - b;
  f[0][0] = abs(a[0] - b[0]);
  for (j = 1; j < k; j++) f[0][j] = min(abs(a[0] - b[j]), f[0][j - 1]);
  for (i = 1; i < n; i++) {
    f[1][0] = abs(a[i] - b[0]) + f[0][0];
    for (j = 1; j < k; j++)
      f[1][j] = min(f[1][j - 1], f[0][j] + abs(a[i] - b[j]));
    for (j = 0; j < k; j++) f[0][j] = f[1][j];
  }
  cout << f[1][k - 1];
}
