#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long cur = 1e18;
    long long ans = 0;
    for (int i = 0; i < n - k; i++) {
      long long dist = (a[i + k] - a[i] + 1) / 2;
      if (dist < cur) {
        cur = dist;
        ans = (a[i] + a[i + k]) / 2;
      }
    }
    cout << ans << "\n";
  }
}
