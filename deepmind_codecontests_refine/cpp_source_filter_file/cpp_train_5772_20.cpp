#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
long long _gcd(long long a, long long b) {
  if (b == 0) return a;
  _gcd(b, a % b);
}
int main() {
  int n, m, k, a[20500][10], res[20500] = {0}, b[20500][10] = {0};
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  for (int i = 0; i < k; ++i) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    b[0][r]++;
    b[l][r]--;
    b[l + 1][r]++;
    b[20500][r]--;
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < n; ++j) b[j][i] += b[j - 1][i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (a[i][j] == 1) res[i] += b[i][j];
  }
  for (int i = 0; i < n; ++i) cout << res[i] << " ";
}
