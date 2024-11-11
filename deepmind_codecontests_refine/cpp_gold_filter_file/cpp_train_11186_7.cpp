#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, k, m, id[N][26 + 4];
vector<int> adj[N];
bool mark[N][2];
void dfs(int u) {
  for (auto v : adj[u]) {
    dfs(v);
    mark[u][0] |= !mark[v][0];
    mark[u][1] |= !mark[v][1];
  }
  mark[u][0] |= adj[u].empty();
}
void build(string s) {
  for (int i = 0, par = 0; i < s.size(); i++)
    if (!id[par][s[i] - 'a']) {
      adj[par].push_back(++m);
      par = id[par][s[i] - 'a'] = m;
    } else
      par = id[par][s[i] - 'a'];
}
void readInput() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    build(s);
  }
}
void solve() {
  dfs(0);
  if (mark[0][1] && (mark[0][0] || k & 1))
    cout << "First\n";
  else
    cout << "Second\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  readInput(), solve();
  return 0;
}
