#include <bits/stdc++.h>
using namespace std;
const int x = 998244353;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n], b[k], c[n], d[n];
    int ans = 1;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      c[i] = 0;
      d[a[i]] = i;
    }
    for (int i = 0; i < k; i++) {
      cin >> b[i];
      c[d[b[i]]] = i + 1;
    }
    if (c[1] > c[0] && c[0] != 0) ans *= 0;
    for (int i = 1; i < n - 1; i++) {
      if (c[i] == 0) continue;
      if (c[i - 1] > c[i] && c[i + 1] > c[i]) {
        ans *= 0;
        continue;
      }
      if (c[i] > c[i + 1] && c[i] > c[i - 1]) {
        ans *= 2;
        ans %= x;
      }
    }
    if (c[n - 1] < c[n - 2] && c[n - 1] != 0) ans *= 0;
    cout << ans << endl;
  }
  return 0;
}
