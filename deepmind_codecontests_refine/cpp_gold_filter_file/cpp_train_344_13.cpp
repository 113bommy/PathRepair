#include <bits/stdc++.h>
using namespace std;
void fast_stream() { std::ios_base::sync_with_stdio(0); }
string s, t;
string res;
bool used[10001];
bool dfs(int pos, string cur) {
  if (pos == t.size() || pos == s.size()) {
    if (pos < s.size()) {
      string rest;
      for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;
        rest += s[i];
      }
      sort(rest.begin(), rest.end());
      res = cur + rest;
      return true;
    }
    return false;
  } else {
    for (int i = 0; i < s.size(); i++) {
      if (used[i]) continue;
      if (s[i] == t[pos]) {
        used[i] = true;
        bool a = dfs(pos + 1, cur + s[i]);
        used[i] = false;
        if (a) return true;
        break;
      }
    }
    int best = -1;
    for (int i = 0; i < s.size(); i++) {
      if (used[i]) continue;
      if (s[i] > t[pos]) {
        if (best == -1 || s[best] > s[i]) best = i;
      }
    }
    if (best != -1) {
      res = cur;
      res += s[best];
      used[best] = true;
      string rest;
      for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;
        rest += s[i];
      }
      sort(rest.begin(), rest.end());
      res += rest;
      return true;
    }
    return false;
  }
}
void solve() {
  cin >> s >> t;
  bool ans = dfs(0, "");
  if (!ans)
    cout << -1 << endl;
  else
    cout << res << endl;
}
int main() {
  solve();
  return 0;
}
