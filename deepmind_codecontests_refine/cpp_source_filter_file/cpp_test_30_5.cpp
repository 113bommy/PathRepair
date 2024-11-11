#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, ans = 1e9 + 7;
  string s;
  cin >> n >> s;
  bool flag = 1, f = 0;
  for (long long i = 0; i < n / 2; ++i) {
    if (s[i] != s[n - i - 1]) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << "0\n";
    return;
  }
  for (long long i = 0; i < 26; ++i) {
    string tmp = "";
    vector<long long> v, p;
    map<long long, long long> mp;
    flag = 0;
    for (long long j = 0; j < n; ++j) {
      if (s[j] == i + 'a')
        p.push_back(j);
      else
        tmp += s[j], v.push_back(j);
    }
    long long k = v.size(), cnt = p.size();
    for (long long j = 0; j < k / 2; ++j) {
      if (tmp[j] != tmp[k - j - 1]) {
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    for (long long x : p) {
      long long a = lower_bound(v.begin(), v.end(), x) - v.begin();
      if (k % 2 && a == k / 2) {
        --cnt;
        continue;
      }
      if (a > k / 2) {
        a = k - a;
        if (mp[a]) {
          --mp[a];
          cnt -= 2;
        }
      } else {
        ++mp[a];
      }
    }
    ans = min(ans, cnt);
    f = 1;
  }
  if (f)
    cout << ans << '\n';
  else
    cout << "-1\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
