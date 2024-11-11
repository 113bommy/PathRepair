#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  if (n < 5) {
    cout << n * (n - 1) / 2;
    return 0;
  }
  int x = 5;
  int ans = 0;
  while (10LL * x <= n * 1LL) x *= 10;
  int p10 = 2 * x;
  for (int i = 1; i <= 5 && x <= n; i++) {
    int r = min(x + p10 - 1, n);
    ans += (r - x + 1) * i;
    x += p10;
  }
  cout << ans - (n + 1) / p10 << endl;
}
