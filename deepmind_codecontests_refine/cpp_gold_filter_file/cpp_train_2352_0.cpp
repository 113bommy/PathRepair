#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n], res = INT_MAX;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] <= k && a[i] != 0) {
      res = min(abs(i - m), res);
    }
  }
  cout << res * 10;
  return 0;
}
