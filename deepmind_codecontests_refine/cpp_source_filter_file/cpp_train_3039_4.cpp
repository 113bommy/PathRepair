#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const long long INF = 0x3f3f3f3f;
const long long MOD = 1000000007;
long long find_first(string &s, char c, long long x) {
  while (s[x] != c) {
    x++;
  }
  return x;
}
void reverse(string &s, long long l, long long r) {
  string t;
  for (long long i = 0; i < l; i++) {
    t += s[i];
  }
  for (long long i = l; i <= r; i++) {
    t += s[r + l - i];
  }
  for (long long i = r + 1; i < s.size(); i++) {
    t += s[i];
  }
  s = t;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<long long, long long> > ans;
  for (long long i = 0; i < 2 * k; i++) {
    if (i % 2 == 0 && s[i] == ')') {
      long long r = find_first(s, '(', i + 1);
      ans.emplace_back(i + 1, r + 1);
      reverse(s, i, r);
    }
    if (i % 2 == 1 && s[i] == '(') {
      long long r = find_first(s, ')', i + 1);
      ans.emplace_back(i + 1, r + 1);
      reverse(s, i, r);
    }
  }
  for (long long i = 2 * k; i < n / 2 + k; i++) {
    if (s[i] == ')') {
      long long r = find_first(s, '(', i + 1);
      ans.emplace_back(i + 1, r + 1);
      reverse(s, i, r);
    }
  }
  for (long long i = n / 2 + k; i < n; i++) {
    if (s[i] == '(') {
      long long r = find_first(s, ')', i + 1);
      ans.emplace_back(i + 1, r + 1);
      reverse(s, i, r);
    }
  }
  cout << ans.size() << '\n';
  for (pair<long long, long long> p : ans) {
    cout << p.first << ' ' << p.second << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
}
