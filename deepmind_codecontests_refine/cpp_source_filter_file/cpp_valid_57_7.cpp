#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long &first : v) cin >> first;
    bool flag = false;
    for (long long i = 0; i < n; i++) {
      if ((i & 1) && (v[i] & 1)) flag = true;
      if (!(i & 1) && !(v[i] & 1)) flag = true;
    }
    if (flag) {
      cout << -1 << '\n';
      continue;
    }
    vector<long long> res(n);
    iota((res).begin(), (res).end(), 1);
    long long curr = n - 1;
    vector<long long> ans;
    while (v != res) {
      for (long long i = 0; i < n; i++) {
        if (v[i] == res[curr]) {
          ans.emplace_back(i + 1);
          reverse(v.begin(), v.begin() + i + 1);
          break;
        }
      }
      long long pos = 0;
      for (long long i = 0; i < n; i++) {
        if (v[i] == res[curr - 1]) {
          ans.emplace_back(i + 1);
          pos = i + 2;
          reverse(v.begin(), v.begin() + i);
          break;
        }
      }
      ans.emplace_back(pos);
      reverse(v.begin(), v.begin() + pos);
      ans.emplace_back(3);
      reverse(v.begin(), v.begin() + 3);
      ans.emplace_back(curr + 1);
      reverse(v.begin(), v.begin() + curr + 1);
      curr -= 2;
    }
    cout << ans.size() << '\n';
    for (long long first : ans) cout << first << ' ';
    cout << '\n';
  }
}
