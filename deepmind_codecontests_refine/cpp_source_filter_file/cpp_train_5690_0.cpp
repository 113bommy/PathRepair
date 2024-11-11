#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> adj[N];
int vis[2][N];
vector<int> path;
bool solve(int t, int cur) {
  if (vis[t][cur]++) return 0;
  if (t && !adj[cur].size()) return 1;
  for (int i = 0; i < adj[cur].size(); ++i)
    if (solve(t ^ 1, adj[cur][i])) {
      path.push_back(adj[cur][i]);
      return 1;
    }
  return 0;
}
int vis2[N];
bool cycle(int cur) {
  if (vis2[cur] == 1) return 1;
  if (vis2[cur] == 2) return 0;
  vis2[cur] = 1;
  for (int i = 0; i < adj[cur].size(); ++i)
    if (cycle(adj[cur][i])) return 1;
  vis2[cur] = 1;
  return 0;
}
int n, m, c, s;
int main() {
  scanf("%d", &n), scanf("%d", &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c);
    for (int j = 0; j < c; ++j) {
      int v;
      scanf("%d", &v);
      v--;
      adj[i].push_back(v);
    }
  }
  scanf("%d", &s);
  s--;
  if (solve(0, s)) {
    puts("Win");
    cout << s + 1 << " ";
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); ++i) printf("%d ", path[i] + 1);
  } else if (cycle(s))
    return puts("Draw");
  else
    return puts("Lose");
}
