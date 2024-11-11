#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18, mxn = 1e5 + 5;
void solve() {
  long long a, b, res = 0;
  cin >> a >> b;
  string s;
  cin >> s;
  bool ok = false;
  for (long long i = 0; i < (long long)(s).size(); i++) {
    if (s[i] == '1') ok = true;
    if (s[i] == '0' and ok) {
      long long start = i, end = i;
      while (end < (long long)(s).size() and s[end] != '1') end++;
      if (end == (long long)(s).size()) {
        break;
      }
      end--;
      if (((end - start + 1) * b + a) < (2 * a)) {
        res += (end - start + 1) * b;
        for (; start <= end; start++) s[start] = '1';
      }
      i = end;
    }
  }
  for (long long i = 0; i < (long long)(s).size(); i++) {
    if (s[i] == '1') {
      res += a;
      while (i < (long long)(s).size() and s[i] != '0') i++;
    }
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
}
