#include <bits/stdc++.h>
using namespace std;
int cnt[30];
bool vis[30], mark[30];
string ans;
vector<int> v[30];
void dfs(int x) {
  vis[x] = 1;
  ans += x + 'a';
  for (int i = 0; i < v[x].size(); i++) {
    if (cnt[v[x][i]] != 0 && !vis[v[x][i]]) dfs(v[x][i]);
  }
}
int main() {
  int n;
  while (cin >> n) {
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        if (j != s.size() - 1) {
          v[s[j] - 'a'].push_back(s[j + 1] - 'a');
          cnt[s[j + 1] - 'a']++;
        }
        mark[s[j] - 'a'] = 1;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[i] == 0 && mark[i]) dfs(i);
    }
    cout << ans << endl;
  }
  return 0;
}
