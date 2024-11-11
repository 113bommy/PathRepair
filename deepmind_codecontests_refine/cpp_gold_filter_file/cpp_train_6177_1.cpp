#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
struct Edge {
  int u, v, w, ans, id;
  bool operator<(const Edge &y) const { return this->w < y.w; }
} e[N];
int n, m;
bool cmp(Edge x, Edge y) { return x.id < y.id; }
map<int, vector<int> > v, mark;
map<int, int> vis, first;
set<int> Set;
int fa[N], tim;
char res[][20] = {"none", "at least one", "any"};
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void tarjan(int x) {
  if (vis[x]) return;
  vis[x] = first[x] = ++tim;
  for (int i = 0; i < v[x].size(); i++) {
    int y = v[x][i];
    int Mark = mark[x][i];
    if (Set.count(Mark)) continue;
    Set.insert(Mark);
    tarjan(y);
    if (vis[y] < vis[x]) {
      vis[x] = vis[y];
    }
    if (vis[y] > first[x]) {
      e[Mark].ans = 2;
    }
  }
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 0; i <= n; i++) fa[i] = i;
    for (int i = 0; i < m; i++) {
      scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
      e[i].ans = 0;
      e[i].id = i;
    }
    sort(e, e + m);
    for (int i = 0; i < m;) {
      int s = i, x, y;
      while (i < m && e[i].w == e[s].w) i++;
      v.clear();
      vis.clear();
      mark.clear();
      Set.clear();
      for (int j = s; j < i; j++) {
        x = find(e[j].u);
        y = find(e[j].v);
        if (x == y) continue;
        e[j].ans = 1;
        v[x].push_back(y);
        v[y].push_back(x);
        mark[x].push_back(j);
        mark[y].push_back(j);
      }
      for (map<int, vector<int> >::iterator it = v.begin(); it != v.end();
           it++) {
        tarjan(it->first);
      }
      for (int j = s; j < i; j++) {
        x = find(e[j].u);
        y = find(e[j].v);
        if (x == y) continue;
        fa[x] = y;
      }
    }
    sort(e, e + m, cmp);
    for (int i = 0; i < m; i++) {
      printf("%s\n", res[e[i].ans]);
    }
  }
  return 0;
}
