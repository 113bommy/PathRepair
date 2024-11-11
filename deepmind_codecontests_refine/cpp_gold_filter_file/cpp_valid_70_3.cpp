#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
void solve() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (int i = 0; i < s.length(); i++) {
    mp[s[i]] += 1;
  }
  int dist = mp.size();
  int n = s.length();
  int i = n - 1;
  string rem = "";
  char cur = s[i];
  if (dist != 0 and mp[cur] % dist) {
    cout << -1 << endl;
    return;
  }
  if (dist == 1) {
    cout << s << " " << s[0] << endl;
    return;
  }
  int cdist = mp[cur] / dist;
  int match[26] = {0};
  match[cur - 'a'] = cdist;
  string ans = "";
  int vis[26] = {0};
  while (i >= 0) {
    if (cur == s[i]) {
      cdist -= 1;
    }
    if (!cdist) {
      vis[cur - 'a'] = 1;
      rem += cur;
      dist -= 1;
      int pre = i;
      while (i >= 0) {
        if (!vis[s[i] - 'a']) {
          cur = s[i];
          i += 1;
          break;
        }
        i -= 1;
      }
      if (dist != 0 and mp[cur] % dist) {
        cout << -1 << endl;
        return;
      }
      cdist = mp[cur] / dist;
      match[cur - 'a'] = cdist;
      if (dist == 1 or dist == 0) {
        rem += cur;
        break;
      }
    }
    i -= 1;
  }
  int match1[26] = {0};
  for (int i = 0; i < n; i++) {
    bool f = true;
    match1[s[i] - 'a'] += 1;
    ans += s[i];
    for (int j = 0; j < 26; j++) {
      if (match1[j] != match[j]) {
        f = false;
        break;
      }
    }
    if (f) {
      break;
    }
  }
  reverse(rem.begin(), rem.end());
  string cs = ans;
  string tot = cs;
  for (int k = 0; k < mp.size(); k++) {
    string ns = "";
    char c = rem[k];
    for (int i = 0; i < cs.length(); i++) {
      if (cs[i] == c) continue;
      ns += cs[i];
    }
    tot = tot + ns;
    cs = ns;
  }
  if (tot != s) {
    cout << -1 << endl;
    return;
  }
  cout << ans << " " << rem << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
