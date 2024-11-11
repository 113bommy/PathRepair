#include <bits/stdc++.h>
using namespace std;
using vl = vector<long long>;
using vi = vector<long long>;
using vvi = vector<vi>;
using pi = pair<long long, long long>;
using vpi = vector<pi>;
using vvvi = vector<vvi>;
using vvpi = vector<vector<pi>>;
using vvvpi = vector<vvpi>;
using vvvvi = vector<vvvi>;
using vppi =
    vector<pair<pair<long long, long long>, pair<long long, long long>>>;
void solve() {
  string s;
  cin >> s;
  long long ans1 = 0, ans2 = 0;
  for (long long i = 1; i < s.size(); i++) {
    if (s[i] == 'a' && s[i - 1] == 'b')
      ans2++;
    else if (s[i] == 'b' && s[i - 1] == 'a')
      ans1++;
  }
  if (ans1 == ans2) {
    cout << s << endl;
    return;
  } else {
    if (s[0] == 'a') {
      s[0] = 'b';
    } else
      s[0] = 'b';
    cout << s << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
