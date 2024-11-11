#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 7;
int n, a[N][N], ans[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
  for (int i = 1; i <= n; ++i) {
    int res = 0;
    for (int j = i + 1; j <= n; ++j) res |= a[i][j];
    for (int j = 1; j < i; ++j)
      if ((res & ans[j]) != a[i][j]) res |= ans[j];
    ans[i] = res;
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
  return 0;
}
