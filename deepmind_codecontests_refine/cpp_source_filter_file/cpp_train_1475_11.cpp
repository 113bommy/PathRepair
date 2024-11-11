#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17;
const long long p = 1e9 + 7;
const long long N = 2e5 + 10;
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  set<long long> s;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s.insert(x);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    auto it = s.upper_bound(i - 1);
    if (it == s.end()) break;
    ans++;
    s.erase(it);
    if (s.empty()) break;
  }
  cout << ans;
}
