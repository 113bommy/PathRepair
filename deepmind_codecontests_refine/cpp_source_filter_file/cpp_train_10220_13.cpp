#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, mn = 9999999999, mx = 0;
    cin >> n >> k;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      mn = min(x, mn);
      mx = max(x, mx);
      v.push_back(x);
    }
    long long big = mn + k;
    long long dif = abs(mx - big);
    if (dif <= k) {
      cout << dif << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
