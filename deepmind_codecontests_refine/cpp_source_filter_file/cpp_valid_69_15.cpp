#include <bits/stdc++.h>
using namespace std;
void init_code() {}
vector<string> v;
void init() {
  long long num = 1;
  v.push_back(to_string(num));
  while (true) {
    num *= 2;
    if (num <= 1e15)
      v.push_back(to_string(num));
    else
      break;
  }
}
long long count(string a, string b) {
  long long ans = 0;
  long long i = 0, j = 0;
  while (i < (long long)a.size() and j < (long long)b.size()) {
    if (a[i] == b[j]) {
      i++;
      j++;
    } else {
      i++;
      ans++;
    }
  }
  if (i != (long long)a.size()) ans += ((long long)a.size() - i);
  if (j != (long long)b.size()) ans += ((long long)b.size() - j);
  return min(ans, (long long)a.size() + (long long)b.size());
}
void solve() {
  long long n;
  cin >> n;
  string s = to_string(n);
  long long ans = INT_MAX;
  for (auto x : v) {
    ans = min(ans, count(s, x));
  }
  cout << ans;
}
signed main() {
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init();
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
    cout << '\n';
  }
}
