#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long ans = 0;
    long long a[55];
    long long b[55];
    long long ma = 9999999999;
    long long mb = 9999999999;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] < ma) ma = a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      if (b[i] < mb) mb = b[i];
    }
    for (int i = 1; i <= n; i++) {
      ans += max(b[i] - mb, a[i] - ma);
    }
    cout << ans << endl;
  }
  return 0;
}
