#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
vector<int> digraph[5010];
int marc[5010];
map<pii, int> arcs;
int color[5010];
int colors = 1;
void dfs(int u) {
  marc[u] = 1;
  for (int v : digraph[u]) {
    if (marc[v] == 1) {
      color[arcs[{u, v}]] = 2;
      colors = 2;
      continue;
    }
    if (marc[v] == 0) dfs(v);
    color[arcs[{u, v}]] = 1;
  }
  marc[u] = 2;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    digraph[u].push_back(v);
    arcs[{u, v}] = i;
  }
  for (int i = 1; i <= n; ++i)
    if (marc[i] == 0) dfs(i);
  printf("%d\n", colors);
  for (int i = 0; i < m; ++i) printf("%d ", color[i]);
  printf("\n");
}
