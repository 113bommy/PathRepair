#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 7;
const int M = 9;
const int inf = 1e9 + 7;
const long long linf = 1e18 + 7;
const double pi = acos(-1);
const double eps = 1e-7;
const bool multipleTest = 0;
int n, q;
int d[N * 2];
int lo[N], hi[N], cnt;
vector<int> adj[N];
void dfs(int u) {
  lo[u] = ++cnt;
  for (int v : adj[u]) {
    dfs(v);
  }
  hi[u] = cnt;
}
bool isChild(int u, int v) { return lo[u] >= lo[v] && hi[u] <= hi[v]; }
class SegmentTree {
 public:
  const static int MAXN = N;
  struct node {
    long long val;
    long long lz;
    int leftChild;
    int rightChild;
    int leftIdx, rightIdx;
    node() {
      val = lz = 0;
      rightChild = leftChild = -1;
    }
    void reset(int u, int v, int _left, int _right) {
      val = lz = 0;
      leftChild = _left;
      rightChild = _right;
      leftIdx = u;
      rightIdx = v;
    }
  };
  node tree[MAXN * 2];
  int cnt = 0;
  void buildTree(node& root, int l, int r) {
    if (l == r) {
      root.reset(l, r, -1, -1);
      return;
    }
    int g = (l + r) >> 1;
    int leftChild = cnt++, rightChild = cnt++;
    buildTree(tree[leftChild], l, g);
    buildTree(tree[rightChild], g + 1, r);
    root.reset(l, r, leftChild, rightChild);
  }
  void init(int l, int r) {
    cnt = 1;
    buildTree(tree[0], l, r);
  }
  void pushDown(node& root, long long val) {
    root.val += val;
    root.lz += val;
  }
  void updateLz(node& root) {
    if (root.lz > 0) {
      if (root.leftChild != -1) {
        pushDown(tree[root.leftChild], root.lz);
      }
      if (root.rightChild != -1) {
        pushDown(tree[root.rightChild], root.lz);
      }
      root.lz = 0;
    }
  }
  void update(node& root, int u, int v, long long val) {
    if (root.leftIdx == u && root.rightIdx == v) {
      pushDown(root, val);
      return;
    }
    updateLz(root);
    int g = (root.leftIdx + root.rightIdx) >> 1;
    if (u <= g) update(tree[root.leftChild], u, min(g, v), val);
    if (g < v) update(tree[root.rightChild], max(u, g + 1), v, val);
    root.val = min(tree[root.leftChild].val, tree[root.rightChild].val);
    return;
  }
  void update(int u, int v, long long val) {
    assert(u <= v);
    update(tree[0], u, v, val);
  }
  long long get(node& root, int u, int v) {
    if (u <= root.leftIdx && root.rightIdx <= v) return root.val;
    if (u > root.rightIdx || v < root.leftIdx) return linf;
    updateLz(root);
    long long res =
        min(get(tree[root.leftChild], u, v), get(tree[root.rightChild], u, v));
    root.val = min(tree[root.leftChild].val, tree[root.rightChild].val);
    return res;
  }
  long long get(int u, int v) {
    assert(u <= v);
    return get(tree[0], u, v);
  }
} segmentTree;
int edge[2 * N];
long long getCost(int u) { return segmentTree.get(lo[u], lo[u]) - d[u + n]; }
void solve() {
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adj[u].push_back(v);
    d[v] = c;
    edge[i] = v;
  }
  for (int i = 1; i < n; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    d[u + n] = c;
    edge[i + n - 1] = u;
  }
  dfs(1);
  segmentTree.init(1, n);
  for (int i = 2; i <= n; ++i) {
    segmentTree.update(lo[i], lo[i], d[i + n]);
    segmentTree.update(lo[i], hi[i], d[i]);
  }
  while (q--) {
    int op, u, v;
    scanf("%d%d%d", &op, &u, &v);
    if (op == 1) {
      if (u < n) {
        u = edge[u];
        segmentTree.update(lo[u], hi[u], v - d[u]);
        d[u] = v;
      } else {
        u = edge[u];
        segmentTree.update(lo[u], lo[u], v - d[u + n]);
        d[u + n] = v;
      }
    } else {
      if (isChild(v, u)) {
        cout << getCost(v) - getCost(u) << '\n';
      } else {
        cout << getCost(v) + segmentTree.get(lo[u], hi[u]) - getCost(u) << '\n';
      }
    }
  }
}
void test() {
  n = q = 200000;
  for (int i = 1; i < n; ++i) {
    int u, v, c;
    v = i + 1;
    u = (rand() % i) + 1;
    c = rand() % 1000000;
    adj[u].push_back(v);
    d[v] = c;
    edge[i] = v;
  }
  for (int i = 1; i < n; ++i) {
    int u, v, c;
    u = i + 1;
    v = 1;
    c = rand() % 1000000;
    d[u + n] = c;
    edge[i + n - 1] = u;
  }
  dfs(1);
  segmentTree.init(1, n);
  for (int i = 2; i <= n; ++i) {
    segmentTree.update(lo[i], lo[i], d[i + n]);
    segmentTree.update(lo[i], hi[i], d[i]);
  }
  while (q--) {
    int op, u, v;
    scanf("%d%d%d", &op, &u, &v);
    if (op == 1) {
      if (u < n) {
        u = edge[u];
        segmentTree.update(lo[u], hi[u], v - d[u]);
        d[u] = v;
      } else {
        u = edge[u];
        segmentTree.update(lo[u], lo[u], v - d[u + n]);
        d[u + n] = v;
      }
    } else {
      if (isChild(v, u)) {
        cout << getCost(v) - getCost(u) << '\n';
      } else {
        cout << getCost(v) + segmentTree.get(lo[u], hi[u]) - getCost(u) << '\n';
      }
    }
  }
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
