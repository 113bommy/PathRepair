#include <bits/stdc++.h>
using namespace std;
int n, a[37][37], f1[37], f2[37];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
  for (int i = 1; i <= n; ++i) {
    f1[i] = 0;
    for (int j = 1; j <= n; ++j) f1[i] += a[i][j];
  }
  for (int i = 1; i <= n; ++i) {
    f2[i] = 0;
    for (int j = 1; j <= n; ++j) f2[i] += a[j][i];
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (f1[i] < f2[j]) ans++;
  cout << ans;
  return 0;
}
