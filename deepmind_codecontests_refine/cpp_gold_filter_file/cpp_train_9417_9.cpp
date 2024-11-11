#include <bits/stdc++.h>
using namespace std;
int n, a[1000007], res;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) continue;
    int k = a[n] / a[i] + 1;
    for (int j = 1; j <= k; j++) {
      int x = lower_bound(a + i + 1, a + n + 1, a[i] * j) - a - 1;
      res = max(res, a[x] % a[i]);
    }
  }
  cout << res;
}
