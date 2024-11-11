#include <bits/stdc++.h>
using ll = long long;
const int INF = 0x3f3f3f3f;
using namespace std;
int n, m, a, b, edges, vertices;
bool vis[150002];
vector<int> adj[150002];
void dfs(int src) {
  vis[src] = true;
  vertices++;
  edges += adj[src].size();
  for (int ch : adj[src]) {
    if (!vis[ch]) {
      vis[ch] = true;
      dfs(ch);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &a, &b);
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      edges = 0;
      vertices = 0;
      dfs(i);
      if (edges != vertices * (vertices - 1)) {
        puts("NO");
        return 0;
      }
    }
  }
  puts("YES");
  return 0;
}
