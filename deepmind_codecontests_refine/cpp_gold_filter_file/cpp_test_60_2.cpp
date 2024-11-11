#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    map<long long, long long> mp;
    long long total = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]] += 1;
      total += a[i];
    }
    double mean = total / (double)n;
    mean = mean * 2.0;
    double flr = floor(mean);
    if (mean - flr > 0.0) {
      cout << "0" << endl;
      continue;
    }
    long long tar = mean;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long b = a[i];
      mp[a[i]] -= 1;
      long long c = tar - b;
      ans += mp[c];
    }
    cout << ans << endl;
  }
}
