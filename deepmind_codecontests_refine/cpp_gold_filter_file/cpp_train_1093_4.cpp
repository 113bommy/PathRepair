#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long s[n];
  for (long long i = 0; i < (n); i++) cin >> s[i];
  long long maxi = INT_MIN;
  long long p = n % k;
  long long r = k - p;
  vector<long long> v;
  if (n != 2 * k) {
    for (long long i = 0, j = n - r - 1; i <= j; ++i, --j) {
      v.push_back(s[i] + s[j]);
    }
    if (!v.empty()) maxi = *max_element(v.begin(), v.end());
    maxi = max(maxi, s[n - 1]);
    cout << maxi;
  } else {
    for (long long i = 0, j = n - 1; i <= j; ++i, --j) {
      v.push_back(s[i] + s[j]);
    }
    maxi = *max_element(v.begin(), v.end());
    cout << maxi;
  }
  return 0;
}
