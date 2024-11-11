#include <bits/stdc++.h>
using namespace std;
const int maxElement = 100001;
std::vector<int> edges[maxElement];
bool vis[100000 + 1];
int level[100000 + 1]{};
void DFS(int u, int l) {
  level[l]++;
  vis[u] = true;
  for (int i = 0; i < edges[u].size(); i++) {
    if (!vis[edges[u][i]]) {
      DFS(edges[u][i], l + 1);
    }
  }
  return;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    edges[x].push_back(i);
  }
  DFS(1, 1);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (level[i] % 2) ans++;
  }
  cout << ans;
  return 0;
}
