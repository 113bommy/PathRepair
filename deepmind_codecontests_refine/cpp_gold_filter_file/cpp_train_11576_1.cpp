#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5;
struct Query {
  int op, u, v;
};
int N, Q;
Query q[Maxn + 5];
set<pair<int, int> > g1, g2;
int fa[Maxn + 5], siz[Maxn + 5];
stack<pair<int, int> > stk;
void check(int u, int v) {
  if (u > v) swap(u, v);
  pair<int, int> p = make_pair(u, v);
  if (g1.find(p) != g1.end()) g1.erase(p), g2.insert(p);
}
void update(int u, int v) {
  if (u > v) swap(u, v);
  pair<int, int> p = make_pair(u, v);
  if (g2.find(p) != g2.end())
    g2.erase(p);
  else
    g2.insert(p);
}
int find(int x) {
  if (fa[x] == x) return x;
  return find(fa[x]);
}
void unite(int u, int v) {
  int fu = find(u), fv = find(v);
  if (fu == fv) return;
  if (siz[fu] < siz[fv]) swap(fu, fv);
  stk.push(make_pair(fu, fv));
  siz[fu] += siz[fv], fa[fv] = fu;
}
void rebuild() {
  while (!stk.empty()) {
    int u = stk.top().first, v = stk.top().second;
    fa[v] = v, siz[u] -= siz[v];
    stk.pop();
  }
  for (set<pair<int, int> >::iterator it = g2.begin(); it != g2.end(); it++)
    unite((*it).first, (*it).second);
}
int main() {
  scanf("%d %d", &N, &Q);
  for (int i = 1; i <= Q; i++) scanf("%d %d %d", &q[i].op, &q[i].u, &q[i].v);
  int block_size = sqrt(Q);
  int ans = 0;
  for (int i = 1; i <= Q; i += block_size) {
    int k = min(Q, i + block_size - 1);
    g2.clear();
    for (int j = i; j <= k; j++)
      if (q[j].op == 1) {
        check(q[j].u, q[j].v);
        check(q[j].u % N + 1, q[j].v % N + 1);
      }
    for (int j = 1; j <= N; j++) fa[j] = j, siz[j] = 1;
    for (set<pair<int, int> >::iterator it = g1.begin(); it != g1.end(); it++)
      unite((*it).first, (*it).second);
    while (!stk.empty()) stk.pop();
    for (int j = i; j <= k; j++) {
      q[j].u = (q[j].u + ans - 1) % N + 1;
      q[j].v = (q[j].v + ans - 1) % N + 1;
      if (q[j].op == 1)
        update(q[j].u, q[j].v);
      else {
        rebuild();
        printf("%d", ans = (find(q[j].u) == find(q[j].v)));
      }
    }
    for (set<pair<int, int> >::iterator it = g2.begin(); it != g2.end(); it++)
      g1.insert((*it));
  }
  return 0;
}
