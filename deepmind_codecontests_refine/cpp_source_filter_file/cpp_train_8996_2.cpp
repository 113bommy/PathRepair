#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
struct Node {
  long long x, y;
} pnt[maxn];
struct Que {
  int v, id;
};
int n, m, top, f[maxn], ans[maxn];
vector<int> rou[maxn];
vector<Que> que[maxn];
int Cross(Node p0, Node p1) { return p0.x * p1.y - p0.y * p1.x; }
bool Check(Node p0, Node p1, Node p2) {
  Node l0, l1;
  l0.x = p1.x - p0.x, l0.y = p1.y - p0.y;
  l1.x = p2.x - p1.x, l1.y = p2.y - p1.y;
  return Cross(l0, l1) > 0;
}
void Convex() {
  ans[0] = n, ans[1] = n - 1, top = 1, rou[n].push_back(n - 1);
  for (int i = n - 2; i >= 1; i--) {
    while (top > 0 && Check(pnt[i], pnt[ans[top]], pnt[ans[top - 1]])) top--;
    rou[ans[top]].push_back(i);
    ans[++top] = i;
  }
}
int Find(int x) {
  if (f[x] == x) return x;
  f[x] = Find(f[x]);
  return f[x];
}
void LCA(int u) {
  f[u] = u;
  int v;
  for (int i = 0; i < que[u].size(); i++) {
    v = Find(que[u][i].v);
    if (v > 0) ans[que[u][i].id] = v;
  }
  for (int i = 0; i < rou[u].size(); i++) {
    v = rou[u][i];
    LCA(v), f[v] = u;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &pnt[i].x, &pnt[i].y);
  scanf("%d", &m);
  int u, v;
  Que tmp;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    tmp.id = i;
    tmp.v = v, que[u].push_back(tmp);
    tmp.v = u, que[v].push_back(tmp);
  }
  Convex();
  LCA(n);
  for (int i = 1; i < m; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[m]);
}
