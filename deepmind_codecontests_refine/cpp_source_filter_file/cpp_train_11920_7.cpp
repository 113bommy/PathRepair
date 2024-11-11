#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    v.push_back(k);
  }
  if (is_sorted(v.begin(), v.end())) {
    cout << 0 << " " << 0;
    return 0;
  }
  long long firstchange = 0;
  long long lastchange = 0;
  for (long long i = 0; i < v.size(); i++) {
    if (i + 1 != v[i]) {
      if (firstchange == 0) {
        firstchange = i;
      }
      lastchange = i;
    }
  }
  reverse(v.begin() + firstchange, v.begin() + lastchange + 1);
  if (is_sorted(v.begin(), v.end())) {
    cout << firstchange + 1 << " " << lastchange + 1;
  } else {
    cout << 0 << " " << 0 << '\n';
  }
  return 0;
}
