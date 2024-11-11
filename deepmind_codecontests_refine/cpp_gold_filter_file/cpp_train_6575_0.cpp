#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long cur = 0;
  vector<long long> v;
  for (long long i = n - 1; i >= 0; --i) {
    cur += a[i];
    if (i) v.push_back(cur);
  }
  sort(v.rbegin(), v.rend());
  for (long long i = 0; i < k - 1; ++i) {
    cur += v[i];
  }
  cout << cur;
  return 0;
}
