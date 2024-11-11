#include <bits/stdc++.h>
using namespace std;
string s[70000];
vector<string> sub[70000];
string ans[70000];
vector<string> f(string s, int len) {
  vector<string> ret;
  for (int i = 0; i <= s.size() - len; i++) {
    ret.push_back(s.substr(i, len));
  }
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
  }
  for (int len = 1; len <= 8; len++) {
    map<string, int> m;
    for (int i = 0; i < N; i++) {
      sub[i].clear();
      for (int j = 0; j <= s[i].size() - len; j++) {
        string t = s[i].substr(j, len);
        sub[i].push_back(t);
        m[t]++;
      }
    }
    for (int i = 0; i < N; i++) {
      if (ans[i].size()) continue;
      for (auto t : sub[i]) {
        m[t]--;
      }
      for (auto t : sub[i]) {
        if (m[t] == 0) {
          ans[i] = t;
          break;
        }
      }
      for (auto t : sub[i]) {
        m[t]++;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    if (ans[i].size() == 0) ans[i] = s[i];
    cout << ans[i] << endl;
  }
}
