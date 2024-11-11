#include <bits/stdc++.h>
using namespace std;
int a[10003], n, m, i, ans = 0, x, y, z;
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y >> z;
    a[x] -= z;
    a[y] += z;
  }
  for (i = 1; i <= n; i++)
    if (a[i] < 0) ans += a[i];
  cout << -ans;
}
