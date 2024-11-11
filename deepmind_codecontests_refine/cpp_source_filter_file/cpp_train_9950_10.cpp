#include <bits/stdc++.h>
using namespace std;
const long long N = 500005;
const long long mod = 1e9 + 7;
vector<long long> pre(N), suf(N);
void solve() {
  long long x = 0, y = 0, c = 0, ans = 0;
  long long n, m;
  string s, t, r;
  cin >> s >> t;
  r = t;
  n = (long long)(s.size());
  for (long long i = 0; i < n; ++i) {
    if (s[i] == t[x]) x++;
    pre[i + 1] = x;
  }
  x = 0;
  m = (long long)(t.size());
  for (long long i = n - 1; i >= 0; --i) {
    if (s[i] == r[m - x - 1]) x++;
    suf[i + 1] = x;
  }
  reverse(r.begin(), r.end());
  x = 0;
  for (long long i = 1; i <= n; ++i) {
    if (suf[i] + pre[i] - (suf[i] - suf[i + 1]) * (pre[i] - pre[i - 1]) > x) {
      x = suf[i] + pre[i] - (suf[i] - suf[i + 1]) * (pre[i] - pre[i - 1]);
      y = i;
    }
  }
  if ((suf[y] - suf[y + 1]) * (pre[y] - pre[y - 1])) {
    s = t.substr(0, pre[y - 1]);
  } else {
    s = t.substr(0, pre[y]);
  }
  string str = r.substr(0, suf[y]);
  reverse(str.begin(), str.end());
  s = s + str;
  if ((long long)(s.size()) > m) {
    cout << t << "\n";
    return;
    ;
  }
  if (s == "") {
    cout << "-"
         << "\n";
    return;
    ;
  } else
    cout << s + str << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
