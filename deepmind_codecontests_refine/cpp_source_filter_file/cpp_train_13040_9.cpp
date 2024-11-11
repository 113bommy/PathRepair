#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, min1 = 100000, min2 = 100000;
    cin >> n;
    long long int a[n + 5], b[n + 5];
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n; i++) cin >> b[i];
    for (i = 0; i < n; i++) {
      min1 = min(min1, a[i]);
      min2 = min(min2, b[i]);
    }
    long long int s1, s2;
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
      s1 = a[i] - min1;
      s2 = b[i] - min2;
      ans += max(s1, s2);
    }
    cout << ans << endl;
  }
  return 0;
}
