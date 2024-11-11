#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int cnt[32];
set<int> g[32];
bool mark[32], vis[32];
string ans;
void dfs(int v) {
  vis[v] = true;
  for (int u : g[v])
    if (!vis[u]) dfs(u);
  ans += (char)(v + 'a');
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int i = 0; i < s.size(); i++) mark[s[i] - 'a'] = true;
    for (int i = 1; i < s.size(); i++) {
      g[s[i] - 'a'].insert(s[i - 1] - 'a');
      cnt[s[i] - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++)
    if (mark[i] and !cnt[i] and !vis[i]) dfs(i);
  cout << ans << endl;
  return 0;
}
