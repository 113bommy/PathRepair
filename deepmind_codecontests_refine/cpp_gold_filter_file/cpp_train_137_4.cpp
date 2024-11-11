#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long mod = 1e9 + 7;
long long fpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1)
    return (a * fpow(a * a % mod, n / 2)) % mod;
  else
    return fpow(a * a % mod, n / 2);
}
long long T = 1;
void unstoppable() {
  long long n;
  string s;
  cin >> n >> s;
  map<char, long long> mp, vis;
  for (char c : s) mp[c]++;
  for (auto e : mp)
    if (e.second % n) {
      cout << -1;
      return;
    }
  string ans = "";
  for (long long i = 0; i < s.size(); ++i) {
    if (!vis[s[i]]) {
      vis[s[i]] = 1;
      long long tmp = mp[s[i]] / n;
      for (long long j = 0; j < tmp; ++j) ans += s[i];
    }
  }
  while (n--) {
    cout << ans;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (T--) {
    unstoppable();
  }
}
