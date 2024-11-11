#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
int32_t main() {
  long long n, c;
  cin >> n >> c;
  if (n == 1) {
    cout << "1"
         << "\n";
    return 0;
  }
  long long a[n], i, ans = 0;
  for (i = 0; i < n; i++) cin >> a[i];
  vector<long long> v;
  for (i = 0; i < n - 1; i++) v.push_back(a[i + 1] - a[i]);
  for (i = 0; i < v.size(); i++) {
    if (v[i] <= c)
      ans = ans + 1;
    else
      ans = 0;
  }
  cout << ans + 1 << "\n";
  return 0;
}
