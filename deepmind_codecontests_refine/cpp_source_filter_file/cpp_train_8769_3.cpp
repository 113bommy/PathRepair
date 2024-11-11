#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, x;
  long long ans = -1;
  while (tc--) {
    cin >> n >> x;
    vector<long long> a(2 * n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      a[i + n] = a[i];
    }
    n *= 2;
    vector<long long> b = {0}, c = {0};
    for (long long i = 0; i < n; i++) {
      b.push_back(b.back() + a[i]);
    }
    for (long long i = 0; i < n; i++) {
      c.push_back(c.back() + ((a[i] + 1) * a[i]) / 2);
    }
    for (long long i = 0; i < n; i++) {
      if (c[i + 1] >= x) {
        long long z = upper_bound(c.begin(), c.end(), c[i + 1] - x) - c.begin();
        long long cnt = c[i + 1] - c[z];
        long long days = b[i + 1] - b[z];
        long long too = x - days;
        cnt += ((a[z - 1] * (a[z - 1] + 1)) / 2);
        cnt -= (((a[z - 1] - too) * (a[z - 1] + 1 - too)) / 2);
        ans = max(ans, cnt);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
