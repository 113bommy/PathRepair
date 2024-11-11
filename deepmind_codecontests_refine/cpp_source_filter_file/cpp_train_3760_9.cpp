#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int inf = INT_MAX;
const long long inff = 1e18;
const int mod = 1e9 + 7;
string s, t;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  cout << 0 << ' ' << 0 << endl;
  cout << flush;
  cin >> s;
  if (n == 1) {
    cout << 0 << ' ' << 1000000000 << ' ' << 1000000000 << ' ' << 0 << endl;
    cout << flush;
    return 0;
  }
  cout << 1000000000 << ' ' << 1000000000 << endl;
  cout << flush;
  cin >> t;
  if (n == 2) {
    if (s == t)
      cout << 1 << ' ' << 0 << ' ' << 1000000000 << ' ' << 1000000000 - 1
           << endl;
    else
      cout << 0 << ' ' << 1000000000 << ' ' << 1000000000 << ' ' << 0 << endl;
    cout << flush;
    return 0;
  }
  if (s != t) {
    int l = 1, r = 1000000000 - 1;
    for (int i = 1; i <= n - 2; i++) {
      int m = (l + r) >> 1;
      cout << m << ' ' << 0 << endl;
      cout << flush;
      string now;
      cin >> now;
      if (now == s)
        r = m - 1;
      else
        l = m + 1;
    }
    cout << 0 << ' ' << l << ' ' << l << ' ' << 0 << endl;
    cout << flush;
    return 0;
  } else {
    int l = 1, r = 1000000000 - 1;
    for (int i = 1; i <= n - 2; i++) {
      int m = (l + r) >> 1;
      cout << m << ' ' << 0 << endl;
      cout << flush;
      string now;
      cin >> now;
      if (now == s)
        l = m + 1;
      else
        r = m - 1;
    }
    cout << l << ' ' << 0 << ' ' << 1000000000 << ' ' << 1000000000 - l << endl;
    cout << flush;
    return 0;
  }
}
