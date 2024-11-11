#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  vector<long long> a;
  for (long long i = 1; i <= sqrt(1e10); i++) {
    a.push_back(i * i);
  }
  while (t--) {
    long long x;
    cin >> x;
    auto pos = upper_bound(a.begin(), a.end(), x);
    if (pos == a.end()) {
      cout << "-1\n";
      continue;
    }
    bool ok = 0;
    for (long long i = pos - a.begin(); i < a.size(); i++) {
      long long n = sqrt(a[i]);
      long long l = 1, r = n + 1;
      while (r - l > 1) {
        long long m = (l + r) >> 1;
        if (n * n - (n / m) * (n / m) <= x) {
          l = m;
        } else {
          r = m;
        }
      }
      if (n * n - (n / l) * (n / l) == x) {
        cout << n << " " << l << "\n";
        ok = 1;
        break;
      }
    }
    if (!ok) {
      cout << "-1\n";
    }
  }
}
