#include <bits/stdc++.h>
using namespace std;
const long long inf = ~0ull / 4;
const long long maxn = 210000;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  string s, t;
  cin >> s >> t;
  long long sz = s.length();
  long long tz = t.length();
  if (s == t)
    cout << -1;
  else
    cout << max(sz, tz);
  return 0;
}
