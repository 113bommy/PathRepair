#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
  int *rank, *parent, size;
  UnionFind(int msize) {
    size = msize;
    rank = new int[size];
    parent = new int[size];
  }
  ~UnionFind() {
    delete[] rank;
    delete[] parent;
  }
  void clear(int msize = -1) {
    if (msize >= 0) size = msize;
    for (int i = 0; i < size; i++) parent[i] = i, rank[i] = 1;
  }
  int find(int node) {
    if (node == parent[node]) return node;
    return parent[node] = find(parent[node]);
  }
  void union_(int a, int b) {
    a = find(a), b = find(b);
    if (rank[a] <= rank[b])
      parent[a] = b, rank[b] += rank[a];
    else
      parent[b] = a, rank[a] += rank[b];
  }
};
vector<int> adj[100005];
vector<pair<int, int> > v;
bool used[100005];
int a[100005];
int main() {
  int n, m;
  scanf(" %d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf(" %d", &a[i]);
    v.push_back(make_pair(a[i], i));
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf(" %d %d", &x, &y);
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  UnionFind uf(100005);
  uf.clear(n);
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    int node = v[i].second;
    int value = v[i].first;
    for (int j = 0; j < adj[node].size(); j++) {
      int node2 = adj[node][j];
      if (used[node2]) {
        int k = uf.find(node);
        int k2 = uf.find(node2);
        if (k != k2) {
          ret += (long long)uf.rank[k] * uf.rank[k2] * value;
          uf.union_(k, k2);
        }
      }
    }
    used[node] = true;
  }
  double ans = (double)(2 * ret) / ((double)n * (n - 1));
  printf("%lf\n", ans);
  return 0;
}
