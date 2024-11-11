#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, a, b, c;
  string s;
  cin >> n >> a >> b >> c >> s;
  long long pre[n + 5], suf[n + 5];
  memset(pre, 0, sizeof pre);
  ;
  memset(suf, 0, sizeof suf);
  ;
  vector<pair<long long, long long> > v;
  vector<pair<long long, long long> > v1;
  pre[0] = (s[0] == 'h' ? 1 : b + 1);
  for (long long i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + (s[i] == 'h' ? a + 1 : a + b + 1);
    v1.push_back({pre[i], i});
  }
  for (long long i = n - 1; i > 0; i--) {
    suf[i] = suf[i + 1];
    suf[i] += (s[i] == 'h' ? a + 1 : a + b + 1);
    v.push_back({suf[i], n - i});
  }
  sort(v.begin(), v.end());
  sort(v1.begin(), v1.end());
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long x = pre[i - 1] + (i - 1) * a;
    if (x < c) {
      pair<long long, long long> p = {c - x, 1000000000000};
      auto it = upper_bound(v.begin(), v.end(), p);
      if (it == v.begin()) {
        ans = max(ans, i);
      } else {
        it--;
        ans = max(ans, i + (*it).second);
      }
    }
  }
  for (long long i = n - 1; i >= 1; i--) {
    long long x = pre[0] + suf[i] + (n - i) * a;
    if (x < c) {
      pair<long long, long long> p = {c - x, 1000000000000};
      auto it = upper_bound(v1.begin(), v1.end(), p);
      if (it == v1.begin()) {
        ans = max(ans, n - i + 1);
      } else {
        it--;
        ans = max(ans, n - i + 1 + (*it).second);
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (pre[i] <= c) ans = max(ans, i + 1);
  }
  for (long long i = 1; i < n; i++) {
    if ((suf[i] + pre[0]) <= c) ans = max(ans, n - i + 1);
  }
  cout << min(ans, n);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test = 0, t;
  t = 1;
  while (test++ < t) {
    solve();
  }
}
