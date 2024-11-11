#include <bits/stdc++.h>
using namespace std;
long double pi = 3.14159265359;
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 3];
    for (long long i = (long long)(1); i <= (long long)(n); i++) cin >> a[i];
    long long j = 0;
    while (j <= n && a[j] == 0) j++;
    long long cur = 0;
    vector<long long> v;
    for (long long i = (long long)(j + 1); i <= (long long)(n); i++) {
      if (a[i] == 0)
        cur++;
      else if (cur > 0) {
        v.push_back(cur);
        cur = 0;
      }
    }
    if (v.size() == 0) {
      cout << 0 << "\n";
      continue;
    } else if (v.size() == 1) {
      cout << v[0] << "\n";
      continue;
    } else {
      long long mn = accumulate(v.begin(), v.end(), 0);
      for (long long i = (long long)(1); i <= (long long)(v.size() - 1); i++) {
        long long s1 = 0, s2 = 0;
        for (long long k = (long long)(0); k <= (long long)(i - 1); k++)
          s1 += v[k];
        for (long long k = (long long)(v.size() - 1); k >= (long long)(i); k--)
          s2 += v[k];
        mn = min(mn, s1 + s2);
      }
      cout << mn << "\n";
    }
  }
}
