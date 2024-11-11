#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> e[N];
pair<int, int> edge[N];
set<int> s[N];
int deep[N], link[N], root;
void dfs(int v = root, int p = -1) {
  static int timer = 0;
  for (int to : e[v]) {
    if (to == p) {
      continue;
    }
    deep[to] = deep[v] + 1;
    link[to] = timer;
    dfs(to, v);
    timer += p == -1;
  }
}
char f(int v, int u) {
  if (v == u) {
    return true;
  }
  if (link[v] != link[u]) {
    if (v != root)
      if (!s[link[v]].empty())
        if (*s[link[v]].begin() < deep[v]) {
          return false;
        }
    if (!s[link[u]].empty())
      if (*s[link[u]].begin() < deep[u]) {
        return false;
      }
    return true;
  }
  auto x = s[link[v]].lower_bound(deep[v]);
  if (x == s[link[v]].end()) {
    return true;
  }
  return deep[u] <= *x;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    edge[i] = {x, y};
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 0; i < n; i++)
    if (e[i].size() > e[root].size()) {
      root = i;
    }
  dfs();
  int q;
  scanf("%d", &q);
  while (q--) {
    int action;
    scanf("%d", &action);
    if (action == 1) {
      int num;
      scanf("%d", &num);
      int v = edge[num].first, u = edge[num].second;
      if (deep[v] > deep[u]) {
        swap(v, u);
      }
      s[link[u]].erase(deep[v]);
    } else if (action == 2) {
      int num;
      scanf("%d", &num);
      int v = edge[num].first, u = edge[num].second;
      if (deep[v] > deep[u]) {
        swap(v, u);
      }
      s[link[u]].insert(deep[v]);
    } else {
      int v, u;
      scanf("%d%d", &v, &u);
      v--;
      u--;
      if (deep[v] > deep[u]) {
        swap(v, u);
      }
      if (!f(v, u)) {
        printf("-1\n");
        continue;
      }
      printf("%d\n",
             link[v] == link[u] ? deep[u] - deep[v] : deep[v] + deep[u]);
    }
  }
  return 0;
}
