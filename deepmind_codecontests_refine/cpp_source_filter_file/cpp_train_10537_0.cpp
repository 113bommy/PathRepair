#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
void solve() {
  string s, t;
  cin >> s >> t;
  long long n = s.length();
  vector<bool> sh(26);
  vector<bool> th(26);
  bool ok = 1;
  for (auto i : s) sh[i - 'a'] = 1;
  for (auto i : t) th[i - 'a'] = 1;
  for (long long i = 0; i < 26; i++) {
    if (th[i] and !sh[i]) ok = 0;
  }
  if (!ok) {
    puts("-1");
    return;
  }
  long long nxt[n + 1][26];
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j < 26; j++) nxt[i][j] = inf;
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = 0; j < 26; j++) {
      nxt[i][j] = nxt[i + 1][j];
    }
    nxt[i][s[i] - 'a'] = i;
  }
  long long ans = 1;
  long long pos = 1;
  for (long long i = 0; i < t.size(); i++) {
    if (pos == n) {
      pos = 0;
      ans++;
    }
    if (nxt[pos][t[i] - 'a'] == inf) {
      pos = 0;
      ans++;
    }
    if (nxt[pos][t[i] - 'a'] == inf and pos == 0) {
      ans = inf;
      break;
    }
    pos = nxt[pos][t[i] - 'a'] + 1;
  }
  if (ans >= inf)
    puts("-1");
  else
    cout << ans << "\n";
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
