#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
struct node {
  node *p, *c[2], *m;
  int f, v;
  node(int _v) : p(), c(), f() {
    m = this;
    v = _v;
  }
};
inline int val(node *n) { return n != NULL ? n->v : INF; }
inline node *min(node *n) { return n != NULL ? n->m : NULL; }
inline node *min(node *m, node *n) { return val(m) < val(n) ? m : n; }
inline void push(node *n) {
  if (n == NULL) return;
  if (n->f) {
    if (n->c[0]) n->c[0]->f ^= 1;
    if (n->c[1]) n->c[1]->f ^= 1;
    swap(n->c[0], n->c[1]);
    n->f = 0;
  }
}
inline void pull(node *n) {
  if (n == NULL) return;
  n->m = min(n, min(min(n->c[0]), min(n->c[1])));
}
inline int dir(node *n) { return n == n->p->c[1]; }
inline bool is_root(node *n) { return n->p == NULL || n != n->p->c[dir(n)]; }
inline void connect(node *n, node *p, int d) {
  if (n != NULL) n->p = p;
  if (p != NULL) p->c[d] = n;
}
inline void rotate(node *n) {
  bool d = dir(n);
  node *p = n->p;
  connect(n->c[!d], p, d);
  if (is_root(p))
    n->p = p->p;
  else
    connect(n, p->p, dir(p));
  connect(p, n, !d);
  pull(p), pull(n);
}
inline void splay(node *n) {
  while (!is_root(n)) {
    node *p = n->p;
    if (!is_root(p)) push(p->p);
    push(p), push(n);
    if (!is_root(p)) {
      bool b = dir(n) ^ dir(p);
      rotate(b ? n : p);
    }
    rotate(n);
  }
  push(n);
}
void expose(node *n) {
  node *l = NULL, *m = n;
  for (; m != NULL; m = m->p) {
    splay(m);
    m->c[1] = l;
    pull(m);
    l = m;
  }
  splay(n);
}
void evert(node *n) {
  expose(n);
  n->f ^= 1;
}
void link(node *m, node *n) {
  evert(m), expose(n);
  m->p = n;
}
void cut(node *m, node *n) {
  evert(m), expose(n);
  n->c[0]->p = NULL;
  n->c[0] = NULL;
}
bool connected(node *m, node *n) {
  expose(m), expose(n);
  return m->p != NULL;
}
node *path_min(node *m, node *n) {
  evert(m), expose(n);
  return min(n);
}
const int MAXN = 500005;
const int MAXM = 2 * MAXN;
int A[MAXM], B[MAXM];
node *V[MAXN], *E[MAXM];
unordered_map<long, int> inv;
vector<pair<int, int>> res;
void del_edge(int e) {
  cut(V[A[e]], E[e]);
  cut(V[B[e]], E[e]);
  res.push_back({A[e], B[e]});
}
void add_edge(int e) {
  node *a = V[A[e]];
  node *b = V[B[e]];
  if (connected(a, b)) {
    node *m = path_min(a, b);
    assert(m->v == 0);
    del_edge(inv[long(m)]);
    res.push_back({A[e], B[e]});
  }
  link(a, E[e]);
  link(b, E[e]);
}
int N, ok[MAXN];
unordered_map<long long, int> edge;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    V[i] = new node(INF);
  }
  for (int i = 1; i < N; i++) {
    scanf("%d %d", &A[i], &B[i]);
  }
  for (int i = N + 1; i < 2 * N; i++) {
    scanf("%d %d", &A[i], &B[i]);
    int lo = min(A[i], B[i]);
    int hi = max(A[i], B[i]);
    long long id = (long long)lo * N + hi;
    edge[id] = i;
    E[i] = new node(1);
  }
  for (int i = 1; i < N; i++) {
    int lo = min(A[i], B[i]);
    int hi = max(A[i], B[i]);
    long long id = (long long)lo * N + hi;
    if (edge[id]) {
      ok[edge[id]] = 1;
      E[i] = E[edge[id]];
    } else {
      E[i] = new node(0);
    }
    inv[long(E[i])] = i;
    add_edge(i);
  }
  for (int i = N + 1; i < 2 * N; i++) {
    if (!ok[i]) {
      add_edge(i);
    }
  }
  printf("%d\n", int(res.size()) / 2);
  for (int i = 0; i < res.size(); i += 2) {
    int a = res[i].first, b = res[i].second;
    int c = res[i + 1].first, d = res[i + 1].second;
    printf("%d %d %d %d\n", a, b, c, d);
  }
}
