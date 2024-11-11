#include <bits/stdc++.h>
using namespace std;
const long long M = 2e5 + 5;
long long t[M];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, c = 0;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> t[i];
    if (t[i] < 0) c++;
  }
  if (c > k)
    cout << -1 << '\n';
  else {
    k -= c;
    vector<long long> v;
    long long i = 1, ns = 0, len;
    while (i <= n && t[i] >= 0) i++;
    while (i <= n) {
      if (i <= n && t[i] < 0) {
        ns++;
        while (i <= n && t[i] < 0) i++;
      } else if (i <= n && t[i] >= 0) {
        len = 0;
        while (i <= n && t[i] >= 0) i++, len++;
        if (i <= n) v.push_back(len);
      }
    }
    sort(v.begin(), v.end());
    i = 0;
    ns *= 2;
    while (k && i < v.size()) {
      if (k >= v[i]) k -= v[i], ns -= 2;
      i++;
    }
    i = n, len = 0;
    while (t[i] >= 0) i--, len++;
    if (len && k >= len) ns--;
    cout << ns << '\n';
  }
  return 0;
}
