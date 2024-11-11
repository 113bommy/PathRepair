#include <bits/stdc++.h>
const int MAXN = 200005;
struct Edge;
struct Node {
  Edge *e;
  bool solved;
  int dist, size, max, sizeOdd;
  long long sum;
} N[MAXN];
struct Edge {
  Node *u, *v;
  Edge *next;
  Edge() {}
  Edge(Node *u, Node *v) : u(u), v(v), next(u->e) {}
} _pool[MAXN << 1], *_curr = _pool;
void addEdge(int u, int v) {
  N[u].e = new (_curr++) Edge(&N[u], &N[v]);
  N[v].e = new (_curr++) Edge(&N[v], &N[u]);
}
void dfs(Node *u, Node *fa, std::vector<Node *> &vec) {
  u->size = 1;
  u->max = 0;
  vec.push_back(u);
  for (Edge *e = u->e; e; e = e->next)
    if (!e->v->solved && e->v != fa) {
      dfs(e->v, u, vec);
      u->size += e->v->size;
      u->max = std::max(u->max, e->v->size);
    }
}
Node *center(Node *s, std::vector<Node *> &vec) {
  vec.clear();
  dfs(s, NULL, vec);
  Node *res = NULL;
  for (int i = 0; i < vec.size(); i++) {
    vec[i]->max = std::max(vec[i]->max, s->size - vec[i]->size);
    if (!res || res->max > vec[i]->max) res = vec[i];
  }
  return res;
}
void dfs(Node *u, Node *fa = NULL) {
  u->dist = (fa ? fa->dist + 1 : 1);
  u->sum = 0;
  for (Edge *e = u->e; e; e = e->next)
    if (e->v != fa && !e->v->solved) dfs(e->v, u);
}
void add(Node *u, Node *fa = NULL) {
  u->sum += (u->dist + 1) / 2;
  u->size = 1;
  u->sizeOdd = (u->dist % 2);
  for (Edge *e = u->e; e; e = e->next)
    if (e->v != fa && !e->v->solved) {
      add(e->v, u);
      u->sum += e->v->sum;
      u->size += e->v->size;
      u->sizeOdd += e->v->sizeOdd;
    }
}
long long calc(Node *u, const std::vector<Node *> &vec) {
  u->dist = 0;
  for (Edge *e = u->e; e; e = e->next)
    if (!e->v->solved) dfs(e->v, u);
  int childCnt = 0;
  u->size = 1;
  u->sizeOdd = 0;
  for (Edge *e = u->e; e; e = e->next)
    if (!e->v->solved) {
      add(e->v, u);
      ++childCnt;
      u->size += e->v->size;
      u->sizeOdd += e->v->sizeOdd;
    }
  long long res = 0, more = 0;
  for (Edge *e = u->e; e; e = e->next)
    if (!e->v->solved) {
      res += e->v->sum * (u->size - e->v->size);
      more += e->v->sizeOdd * (u->sizeOdd - e->v->sizeOdd);
    }
  res -= more / 2;
  return res;
}
long long solve() {
  static std::stack<Node *> s;
  s.push(&N[1]);
  long long res = 0;
  while (!s.empty()) {
    Node *u = s.top();
    s.pop();
    static std::vector<Node *> vec;
    Node *root = center(u, vec);
    root->solved = true;
    res += calc(root, vec);
    for (Edge *e = root->e; e; e = e->next)
      if (!e->v->solved) s.push(e->v);
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    addEdge(u, v);
  }
  long long ans = solve();
  printf("%lld\n", ans);
  return 0;
}
