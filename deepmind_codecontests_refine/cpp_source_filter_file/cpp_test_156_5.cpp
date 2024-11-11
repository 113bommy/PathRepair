#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    long long a[n], i;
    long long sum = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a, a + n);
    long long c = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == a[0]) c++;
    }
    long long ans = 1e12;
    if (n == 1) {
      if (a[0] > k)
        ans = a[0] - k;
      else
        ans = 0;
      cout << ans << "\n";
      continue;
    }
    if (sum <= k) {
      cout << 0 << "\n";
      continue;
    }
    long long pre[n];
    pre[0] = a[0];
    for (i = 1; i < n; i++) {
      pre[i] = pre[i - 1] + a[i];
    }
    for (i = 0; i < n - 1; i++) {
      sum = pre[n - i - 1] - pre[0];
      long long d = k - sum;
      d = floor((double)d / (i + 1));
      if (d > a[0]) {
        ans = min(ans, i);
        continue;
      }
      long long move = a[0] - d;
      move += i;
      ans = min(ans, move);
    }
    cout << ans << "\n";
  }
  return 0;
}
