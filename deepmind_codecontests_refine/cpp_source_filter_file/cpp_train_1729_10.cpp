#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
const long long arr = 4 * 1e5;
const long long md = 1e9 + 7;
long long a[arr];
signed main() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    k += a[i];
  }
  set<long long> setik;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j * j <= a[i]; j++) {
      setik.insert(j);
      setik.insert(a[i] / j + (a[i] % j != 0));
    }
  }
  vector<long long> vec;
  for (auto i : setik) {
    vec.push_back(i);
  }
  vec.push_back(1e18);
  long long ans = 0;
  for (long long i = 0; i < vec.size() - 1; i++) {
    long long l = vec[i];
    long long r = vec[i + 1] - 1;
    long long sum = 0;
    for (long long j = 1; j <= n; j++) sum += a[j] / r + (a[j] % r != 0);
    long long d = k / sum;
    d = min(d, r);
    if (d < l) continue;
    ans = max(ans, d);
  }
  cout << ans;
}
