#include <bits/stdc++.h>
using namespace std;
struct UF {
  int n;
  vector<int> p;
  UF(int _n) : n(_n), p(n, -1) {}
  int group(int a) {
    if (p[a] == -1) return a;
    return p[a] = group(p[a]);
  }
  void merge(int a, int b) {
    int x = group(a), y = group(b);
    if (x == y) return;
    p[x] = y;
  }
};
const int N = 100010;
int n, m;
vector<int> g[N];
vector<int> c[N];
int deg[N];
bool test(const vector<int>& vs) {
  vector<int> que;
  for (int i = 0; i < int(vs.size()); i++) {
    if (!deg[i]) que.push_back(i);
  }
  for (int i = 0; i < int(que.size()); i++) {
    int v = que[i];
    for (int j = 0; j < int(g[v].size()); j++) {
      int u = g[v][j];
      deg[u]--;
      if (!deg[u]) que.push_back(u);
    }
  }
  return que.size() == vs.size();
}
int main() {
  scanf("%d %d", &n, &m);
  UF uf(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    g[a].push_back(b);
    uf.merge(a, b);
    deg[b]++;
  }
  for (int i = 0; i < n; i++) {
    c[uf.group(i)].push_back(i);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == uf.group(i)) {
      ans += int(c[i].size()) - test(c[i]);
    } else {
      assert(c[i].empty());
    }
  }
  printf("%d\n", ans);
  return 0;
}
