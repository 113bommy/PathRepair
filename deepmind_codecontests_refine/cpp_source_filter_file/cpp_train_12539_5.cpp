#include <bits/stdc++.h>
using namespace std;
int visit[128000];
vector<int> g[128000];
bool visited[128000];
vector<int> tree[128000];
vector<int> res;
bool make_tree(int v) {
  bool flag = false;
  visited[v] = true;
  for (int i : g[v])
    if (!visited[i]) {
      tree[v].push_back(i);
      bool f = make_tree(i);
      if (f) flag = true;
    }
  return (flag || visit[v]);
}
void vis(int v) {
  res.push_back(v);
  visit[v] = 1 - visit[v];
}
void dfs(int v) {
  vis(v);
  for (int i : tree[v]) {
    dfs(i);
    vis(v);
    if (visit[i]) {
      vis(i);
      vis(v);
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)(m); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < (int)(n); i++) scanf("%d", &visit[i]);
  vector<int> need;
  for (int i = 0; i < (int)(n); i++) {
    if (!visited[i]) {
      bool flag = make_tree(i);
      if (flag) need.push_back(i);
    }
  }
  if (need.size() >= 2) {
    cout << -1 << endl;
    return 0;
  }
  if (need.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  dfs(need[0]);
  int rnum = res.size(), pos = 0;
  if (visit[0]) {
    pos = 1;
    --rnum;
  }
  printf("%d\n", rnum);
  for (int i = pos; i < (int)res.size(); ++i) {
    if (i > pos) printf(" ");
    printf("%d", res[i] + 1);
  }
  printf("\n");
  return 0;
}
