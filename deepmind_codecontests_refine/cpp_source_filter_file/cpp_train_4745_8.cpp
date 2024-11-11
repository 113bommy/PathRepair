#include <bits/stdc++.h>
using namespace std;
long long pwr(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long c = pwr(a, (b >> 1));
  c *= c;
  if (b & 1) {
    c *= a;
  }
  return c;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, l, r;
  cin >> n >> l >> r;
  if (n > 30) {
    cout << 0 << "\n";
    return 0;
  }
  if (n == 1) {
    cout << r - l + 1 << "\n";
    return 0;
  }
  if (n == 2) {
    cout << (r - l + 1) * (r - l) << "\n";
    return 0;
  }
  long long maxi = 0;
  vector<long long> v;
  while (pwr(maxi + 1, n - 1) < r) {
    maxi++;
    v.push_back(pwr(maxi, n - 1));
  }
  int* f = new int[r + 1];
  fill(f, f + r + 1, 0);
  for (int i = 0; i < v.size(); i++) {
    for (int j = v[i]; j <= r; j += v[i]) {
      f[j] = max(f[j], i);
    }
  }
  long long ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int fi = (l % v[i] == 0 ? l / v[i] : l / v[i] + 1) * v[i];
    for (int j = fi; j <= r; j += v[i]) {
      if (f[j] != i) {
        continue;
      }
      auto it1 = lower_bound(v.begin(), v.end(), l / (j / v[i]));
      if (it1 == v.end()) {
        continue;
      }
      if (*it1 * (j / v[i]) < l) {
        it1++;
      }
      auto it2 = upper_bound(v.begin(), v.end(), r / (j / v[i]));
      if (it2 != v.end() && *it2 * (j / v[i]) <= r) {
        it2++;
      }
      ans += it2 - it1 - 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
