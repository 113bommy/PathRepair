#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      int sum1 = 0, sum2 = 0;
      for (int k = 1; k <= n; ++k) sum1 += a[k][j];
      for (int k = 1; k <= n; ++k) sum2 += a[i][k];
      if (sum1 < sum2) ans++;
    }
  cout << ans;
}
