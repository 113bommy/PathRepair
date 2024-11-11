#include <bits/stdc++.h>
using namespace std;
long long f[5001][5001];
int a[5001], n, m, k;
int main() {
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = a[i - 1] + x;
  }
  for (int i = 0; i <= n; i++) {
    f[i][0] = 0;
  }
  for (int i = k; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = max(f[i - 1][j], f[i - k][j - 1] + a[i] - a[i - k]);
    }
  }
  cout << f[n][m];
}
