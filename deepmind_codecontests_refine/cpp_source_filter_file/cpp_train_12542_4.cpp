#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  long long pf = 0, ps = 2;
  long long ans = 0;
  for (; ps + 1 < n;) {
    long long a = v[pf], b = v[pf + 1], c = v[ps], d = v[ps + 1];
    if (a != b && a - b == 1) {
      --a;
    } else if (a != b && a - b > 1) {
      if (pf + 1 == ps) {
        ++ps;
      }
      ++pf;
      continue;
    }
    if (c != d && c - d == 1) {
      --c;
    } else if (c != d && c - d > 1) {
      ++ps;
      continue;
    }
    ans += a * c;
    pf = ps + 2;
    ps = pf + 2;
  }
  cout << ans << endl;
}
