#include <bits/stdc++.h>
using namespace std;
const int max_n = 100005, max_e = 200010;
bool was[2005];
long long d[2005];
long long u[2005];
struct Edge {
  int id;
  int v;
  int cost;
  int f;
  int c;
  Edge* p;
  Edge* next;
  void addEdge(int id, int v, int cost, int c, Edge* p, Edge*& head) {
    this->id = id;
    this->v = v;
    this->cost = cost;
    this->f = 0;
    this->c = c;
    this->p = p;
    this->next = head;
    head = this;
  }
} edges[10000];
Edge* h[2005];
void addEdge(int v1, int v2, int cost, int id, int c) {
  static Edge* e = edges;
  (e + 0)->addEdge(id, v2, -cost, c, e + 1, h[v1]);
  (e + 1)->addEdge(id, v1, cost, 0, e + 0, h[v2]);
  e += 2;
}
struct Segment {
  int a, b, c;
  int id;
  void scan(int i) {
    scanf("%d %d %d", &a, &b, &c);
    b += a;
    id = i;
  }
  bool operator<(const Segment& s) const { return a < s.a; }
} a[1002];
int x[2010];
int p[2010];
Edge* pe[2010];
bool slv(int n) {
  memset(d, 63, sizeof(d));
  memset(was, 0, sizeof(was));
  d[0] = 0;
  const long long inf = d[1];
  while (true) {
    long long mx = inf;
    int i = -1;
    for (int j = 0; j < n; j++) {
      if (!was[j] && d[j] < mx) {
        mx = d[j];
        i = j;
      }
    }
    if (i == -1) {
      break;
    }
    mx -= u[i];
    was[i] = true;
    for (Edge* e = h[i]; e; e = e->next) {
      if (e->f < e->c && u[e->v] + mx + e->cost < d[e->v]) {
        if (was[e->v]) {
          continue;
        }
        d[e->v] = u[e->v] + mx + e->cost;
        p[e->v] = i;
        pe[e->v] = e;
      }
    }
  }
  if (d[n - 1] - u[n - 1] >= 0) {
    return false;
  }
  for (int i = n - 1; i; i = p[i]) {
    Edge* e = pe[i];
    e->f++;
    e->p->f--;
  }
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      u[i] -= d[i];
    } else {
      u[i] = 0;
    }
  }
  return true;
}
int r[1010];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    a[i].scan(i);
    x[i + i] = a[i].a;
    x[i + i + 1] = a[i].b;
  }
  sort(x, x + n + n);
  int m = unique(x, x + n + n) - x;
  for (int i = 0; i < n; i++) {
    a[i].a = lower_bound(x, x + m, a[i].a) - x;
    a[i].b = lower_bound(x, x + m, a[i].b) - x;
    addEdge(a[i].a, a[i].b, a[i].c, a[i].id, 1);
  }
  for (int i = 1; i < m; i++) {
    addEdge(i - 1, i, 0, n, k);
  }
  for (int i = 0; i < m; i++) {
    for (Edge* e = h[i]; e; e = e->next) {
      if (e->c == 1 && d[e->v] > d[i] + e->cost) {
        d[e->v] = d[i] + e->cost;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    u[i] = -d[i];
  }
  while (k--) {
    if (!slv(m)) {
      break;
    }
  }
  for (int i = 0; i < m; i++) {
    for (Edge* e = h[i]; e; e = e->next) {
      if (e->f != 0) {
        r[e->id] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", r[i]);
  }
  return 0;
}
