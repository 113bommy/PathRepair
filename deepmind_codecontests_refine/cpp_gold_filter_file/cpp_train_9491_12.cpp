#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long u;
  long long v;
  long long weight;
  edge(long long a, long long b, long long c) {
    u = a;
    v = b;
    weight = c;
  }
};
bool cmp(edge a, edge b) { return a.weight < b.weight; }
long long rnk[100005], parent[100002];
void makeset(long long id, long long x) { parent[id] = id; }
long long find(long long x) {
  if (x != parent[x]) parent[x] = find(parent[x]);
  return parent[x];
}
void merge(long long x, long long y) {
  long long r1 = find(x);
  long long r2 = find(y);
  if (r1 == r2) return;
  parent[r2] = r1;
}
int main() {
  long long n, i, j, k, m, u, v, c, x, y;
  vector<edge> e;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> u >> v >> c;
    if (i == 0) {
      c = 1e9;
      x = u;
      y = v;
    } else
      e.push_back(edge(u, v, c));
  }
  sort(e.begin(), e.end(), cmp);
  for (i = 1; i <= n; i++) {
    makeset(i, i);
  }
  for (i = 0; i < e.size(); i++) {
    u = e[i].u;
    v = e[i].v;
    if (find(u) != find(v)) {
      merge(u, v);
    }
    if (find(x) == find(y)) {
      cout << e[i].weight;
      return 0;
    }
  }
  cout << (1000000000);
}
