#include <bits/stdc++.h>
using namespace std;
string s[110];
vector<int> v[30];
int vis[30], n;
vector<int> sorted;
void dfs(int x) {
  if (vis[x] == 1) return;
  vis[x] = 1;
  for (int i = 0; i < v[x].size(); i++) dfs(v[x][i]);
  sorted.push_back(x);
}
void check(int x) {
  if (vis[x] == 2) "Impossible", exit(0);
  if (vis[x] == 1) return;
  vis[x] = 2;
  for (int i = 0; i < v[x].size(); i++) check(v[x][i]);
  vis[x] = 1;
}
void push(int x, int y, int i) {
  if (i == s[x].size()) return;
  if (i == s[y].size()) cout << "Impossible", exit(0);
  if (s[x][i] == s[y][i]) {
    push(x, y, i + 1);
    return;
  }
  v[s[y][i]].push_back(s[x][i]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < s[i].size(); j++) s[i][j] -= 'a';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) push(i, j, 0);
  }
  for (int i = 0; i < 26; i++) check(i);
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 26; i++) dfs(i);
  for (int i = 0; i < sorted.size(); i++) cout << char('a' + sorted[i]);
  return 0;
}
