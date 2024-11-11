#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
vector<int> V[N];
set<int>::iterator it, it1, it2;
set<int> T[N], NT[N];
int flag[N], Fa[N];
stack<int> S;
vector<pair<pair<int, int>, int> > ans;
void bfs(int root) {
  queue<int> Q;
  Q.push(root);
  flag[root] = 1;
  while (!Q.empty()) {
    int u = Q.front();
    for (int v : V[u])
      if (v != Fa[u]) {
        if (!flag[v])
          Q.push(v), flag[v] = 1, Fa[v] = u, T[u].insert(v);
        else
          NT[u].insert(v);
      }
    S.push(u);
    Q.pop();
  }
}
void dfs() {
  while (!S.empty()) {
    int u = S.top();
    S.pop();
    while (((int)(NT[u]).size()) >= 2) {
      it = NT[u].begin();
      int a = *it;
      NT[u].erase(it++);
      int b = *it;
      NT[u].erase(it++);
      NT[a].erase(u);
      NT[b].erase(u);
      ans.push_back(make_pair(make_pair(a, b), u));
    }
    while (((int)(T[u]).size()) >= 2) {
      it = T[u].begin();
      int a = *it;
      T[u].erase(it++);
      int b = *it;
      T[u].erase(it++);
      ans.push_back(make_pair(make_pair(a, b), u));
    }
    if (((int)(NT[u]).size()) + ((int)(T[u]).size()) == 2) {
      it1 = NT[u].begin(), it2 = T[u].begin();
      int a = *it1, b = *it2;
      ans.push_back(make_pair(make_pair(a, b), u));
      NT[u].erase(it1);
      T[u].erase(it2);
      NT[a].erase(u);
    } else if (!Fa[u] && ((int)(NT[u]).size()) + ((int)(T[u]).size()) == 1) {
      T[Fa[u]].erase(u);
      if (((int)(NT[u]).size())) {
        it = NT[u].begin();
        int a = *it;
        NT[u].erase(it);
        NT[a].erase(u);
        ans.push_back(make_pair(make_pair(a, Fa[u]), u));
      } else {
        it = T[u].begin();
        int a = *it;
        ans.push_back(make_pair(make_pair(a, Fa[u]), u));
        T[u].erase(it);
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (m); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    V[a].push_back(b);
    V[b].push_back(a);
  }
  for (int i = (1); i < (n + 1); ++i)
    if (!flag[i]) bfs(i);
  dfs();
  printf("%d\n", ((int)(ans).size()));
  for (int i = (0); i < (((int)(ans).size())); ++i)
    printf("%d %d %d\n", ans[i].first.first, ans[i].second,
           ans[i].first.second);
  return 0;
}
