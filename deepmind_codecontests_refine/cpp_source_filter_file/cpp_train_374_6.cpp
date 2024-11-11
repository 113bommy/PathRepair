#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n;
string s[N];
int cnt[N][26];
bool used[26];
set<int> g[26], b[26];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < s[i].size(); ++j) {
      cnt[i][s[i][j] - 'a']++;
      used[s[i][j] - 'a'] = true;
      if (cnt[i][s[i][j] - 'a'] > 1) {
        cout << "NO";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < s[i].size() - 1; ++j) {
      g[s[i][j] - 'a'].insert(s[i][j + 1] - 'a');
      b[s[i][j + 1] - 'a'].insert(s[i][j] - 'a');
    }
  for (int i = 0; i < 26; ++i) {
    if (g[i].size() > 1) {
      cout << "NO";
      return 0;
    }
  }
  vector<string> res;
  for (int i = 0; i < 26; ++i) {
    if (used[i] && b[i].size() == 0) {
      string t;
      int cur = i;
      while (1) {
        used[cur] = false;
        t += (char)('a' + cur);
        if (g[cur].size() == 0)
          break;
        else {
          if (used[*g[cur].begin()])
            cur = *g[cur].begin();
          else {
            cout << "NO";
            return 0;
          }
        }
      }
      res.push_back(t);
    }
  }
  for (int i = 0; i < 26; ++i)
    if (!used[i]) {
      cout << "NO";
      return 0;
    }
  sort(res.begin(), res.end());
  for (auto v : res) cout << v;
  return 0;
}
