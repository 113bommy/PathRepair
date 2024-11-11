#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline void chkmin(T1 &x, const T2 &y) {
  if (x > y) x = y;
}
template <typename T1, typename T2>
inline void chkmax(T1 &x, const T2 &y) {
  if (x < y) x = y;
}
long long get(string s) {
  vector<long long> cnt(26);
  long long ans = 0;
  for (auto i : s) {
    for (long long j = i - 'a' + 1; j < 26; j++) {
      ans += cnt[j];
    }
    cnt[i - 'a']++;
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  auto x = s, y = t;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  if (x != y) {
    cout << "NO" << endl;
    return;
  }
  map<long long, long long> cnt;
  for (auto i : s) cnt[i]++;
  for (auto i : cnt) {
    if (i.second >= 2) {
      cout << "YES" << endl;
      return;
    }
  }
  if (get(s) % 2 != get(t) % 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
