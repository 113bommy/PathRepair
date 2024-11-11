#include <bits/stdc++.h>
using namespace std;
class UnionFindTree {
 private:
  vector<int> parent;
  vector<int> rank;

 public:
  explicit UnionFindTree(int n = 0) : parent(n), rank(n) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    parent[x] = find(parent[x]);
    return parent[x];
  }
  int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return x;
    }
    if (rank[x] < rank[y]) {
      parent[x] = y;
      return y;
    } else if (rank[x] > rank[y]) {
      parent[y] = x;
      return x;
    } else {
      parent[y] = x;
      ++rank[x];
      return x;
    }
  }
  bool same(int x, int y) { return find(x) == find(y); }
};
vector<int> result;
vector<int> x;
vector<vector<int> > conn;
int recur(int u, int p) {
  int is_leaf = 1, required = x[u], y = x[u] ^ 1;
  result.push_back(u);
  for (int i = 0; i < conn[u].size(); ++i) {
    if (conn[u][i] == p) {
      continue;
    }
    is_leaf = 0;
    const int t = recur(conn[u][i], u);
    if (t == 1) {
      result.push_back(u);
      y ^= 1;
      required = 1;
    } else if (t == 2) {
      result.push_back(u);
      result.push_back(conn[u][i]);
      result.push_back(u);
      required = 1;
    }
  }
  if (required == 0) {
    result.pop_back();
    return 0;
  } else if (y == 0) {
    return 1;
  } else {
    if (p < 0) {
      result.pop_back();
    }
    return 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  UnionFindTree uft(n);
  conn = vector<vector<int> >(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    if (!uft.same(a, b)) {
      uft.unite(a, b);
      conn[a].push_back(b);
      conn[b].push_back(a);
    }
  }
  x = vector<int>(n);
  int root = -1;
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    if (x[i]) {
      root = i;
    }
  }
  if (root < 0) {
    cout << 0 << endl;
    return 0;
  }
  root = uft.find(root);
  bool connected = true;
  for (int i = 0; i < n; ++i) {
    if (x[i] && !uft.same(root, i)) {
      connected = false;
    }
  }
  if (!connected) {
    cout << -1 << endl;
    return 0;
  }
  result.clear();
  recur(root, -1);
  cout << result.size() << endl;
  for (int i = 0; i < result.size(); ++i) {
    if (i != 0) {
      cout << " ";
    }
    cout << (result[i] + 1);
  }
  cout << endl;
  return 0;
}
