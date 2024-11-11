#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
struct disjointSetUnion {
  int *parent, *rank;
  int size;
  disjointSetUnion(int _size);
  ~disjointSetUnion();
  int getParent(int v);
  bool mergeSets(int u, int v);
};
disjointSetUnion::disjointSetUnion(int _size) {
  size = _size;
  parent = new int[size];
  rank = new int[size];
  for (int i = 0; i < size; ++i) {
    rank[i] = 0;
    parent[i] = i;
  }
}
disjointSetUnion::~disjointSetUnion() {
  delete[] parent;
  delete[] rank;
}
int disjointSetUnion::getParent(int v) {
  if (v == parent[v]) {
    return v;
  }
  return parent[v] = getParent(parent[v]);
}
bool disjointSetUnion::mergeSets(int u, int v) {
  u = getParent(u);
  v = getParent(v);
  if (u == v) {
    return false;
  }
  if (rank[u] < rank[v]) {
    swap(u, v);
  }
  parent[v] = u;
  if (rank[u] == rank[v]) {
    ++rank[u];
  }
  return true;
}
int main() {
  int n, m, modulo;
  scanf("%d%d%d", &n, &m, &modulo);
  disjointSetUnion dsu(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    dsu.mergeSets(u - 1, v - 1);
  }
  map<int, int> sizes;
  for (int i = 0; i < n; ++i)
    if (!sizes.insert(make_pair(dsu.getParent(i), 1)).second) {
      ++sizes[dsu.getParent(i)];
    }
  long long result = 1;
  if ((int)sizes.size() > 1) {
    for (auto& o : sizes) {
      result *= o.second;
      result %= modulo;
    }
    for (int i = 0; i + 2 < (int)sizes.size(); ++i) {
      result *= n;
      result %= modulo;
    }
  }
  printf("%I64d", result % modulo);
  return 0;
}
