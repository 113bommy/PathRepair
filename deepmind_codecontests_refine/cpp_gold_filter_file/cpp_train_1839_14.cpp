#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long linf = 1ll * inf * inf;
const int N = 100000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);
class SegmentTree {
 private:
  struct node {
    int val;
    int leftChild, rightChild;
    int leftIdx, rightIdx;
    node() { reset(0, 0, -1, -1); }
    void reset(int u, int v, int _left, int _right) {
      val = 0;
      leftChild = _left;
      rightChild = _right;
      leftIdx = u;
      rightIdx = v;
    }
  };
  vector<node> tree;
  int cnt = 0;
  node& leftChild(node& root) { return tree[root.leftChild]; }
  node& rightChild(node& root) { return tree[root.rightChild]; }
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
  void mergeNode(node& root, node& lhs, node& rhs) {
    root.val = max(lhs.val, rhs.val);
  }
  void update(node& root, int u, int v, int val) {
    if (u > root.rightIdx || v < root.leftIdx) return;
    if (u <= root.leftIdx && root.rightIdx <= v) {
      root.val = max(root.val, val);
      return;
    }
    update(leftChild(root), u, v, val);
    update(rightChild(root), u, v, val);
    mergeNode(root, leftChild(root), rightChild(root));
  }
  int get(node& root, int u, int v) {
    if (u <= root.leftIdx && root.rightIdx <= v) return root.val;
    if (u > root.rightIdx || v < root.leftIdx) return 0;
    int res = max(get(leftChild(root), u, v), get(rightChild(root), u, v));
    return res;
  }

 public:
  void init(int l, int r) {
    tree.resize((r - l + 1) << 1);
    cnt = 1;
    buildTree(tree[0], l, r);
  }
  void update(int u, int v, int val) { update(tree[0], u, v, val); }
  int get(int u, int v) { return get(tree[0], u, v); }
} segmentTree[N];
map<int, int> f[N];
int dp[N];
int n, m;
int calc(int u, int c) {
  auto it = f[u].lower_bound(c);
  if (it == f[u].begin()) return 0;
  return segmentTree[u].get(1, (--it)->second);
}
void update(int v, int len, int c) {
  int pos = f[v][c];
  segmentTree[v].update(pos, pos, len);
}
pair<pair<int, int>, int> edge[N];
void solve() {
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    edge[i] = {{u, v}, c};
    f[v][c] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    int m = (int)(f[i]).size();
    if (m == 0) continue;
    segmentTree[i].init(1, m);
    int k = 0;
    for (auto& it : f[i]) {
      it.second = ++k;
    }
  }
  for (int i = (1), _b = (m + 1); i < _b; ++i) {
    int u = edge[i].first.first;
    int v = edge[i].first.second;
    int c = edge[i].second;
    int r = calc(u, c);
    ans = max(ans, r + 1);
    update(v, r + 1, c);
  }
  cout << ans;
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
