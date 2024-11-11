#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, x, y, p, ans = 0, tot = 0, sum = 0;
  long long a[1000000];
  cin >> m >> n;
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> y;
    tot += y;
    while (sum < tot) sum += a[p++];
    if (sum == tot) {
      sum = 0;
      tot = 0;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
