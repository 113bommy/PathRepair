#include <bits/stdc++.h>
using namespace std;
int fillData(int node, int parent, int prec, vector<int> *adj, int *history,
             int *depth, int *count, int *nodes, int nodeDepth) {
  depth[node] = nodeDepth;
  history[prec] = node;
  nodes[node] = prec;
  prec++;
  count[node] = 1;
  for (int child : adj[node]) {
    if (child != parent) {
      int temp = fillData(child, node, prec, adj, history, depth, count, nodes,
                          nodeDepth + 1);
      prec += temp;
      count[node] += temp;
    }
  }
  return count[node];
}
void buildMin(int node, int *tree, int *history, int *depth, int a, int b) {
  if (a == b) {
    tree[node] = depth[history[a]];
    return;
  }
  int mid = (a + b) / 2;
  buildMin(node * 2 + 1, tree, history, depth, a, mid);
  buildMin(node * 2 + 2, tree, history, depth, mid + 1, b);
  tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
}
void buildMax(int node, int *tree, int *history, int *count, int a, int b) {
  if (a == b) {
    tree[node] = a + count[history[a]] - 1;
    return;
  }
  int mid = (a + b) / 2;
  buildMax(node * 2 + 1, tree, history, count, a, mid);
  buildMax(node * 2 + 2, tree, history, count, mid + 1, b);
  tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
}
int getMin(int node, int *tree, int a, int b, int f, int t, int MX) {
  if (t < a || b < f) {
    return MX;
  }
  if (f >= a && t <= b) {
    return tree[node];
  }
  int mid = (f + t) / 2;
  return min(getMin(node * 2 + 1, tree, a, b, f, mid, MX),
             getMin(node * 2 + 2, tree, a, b, mid + 1, t, MX));
}
int getMax(int node, int *tree, int a, int b, int f, int t) {
  if (t < a || b < f) {
    return -1;
  }
  if (f >= a && t <= b) {
    return tree[node];
  }
  int mid = (f + t) / 2;
  return max(getMax(node * 2 + 1, tree, a, b, f, mid),
             getMax(node * 2 + 2, tree, a, b, mid + 1, t));
}
int common(int *history, int *tree, int *nodes, int x, int y, int n) {
  int ix = nodes[x], iy = nodes[y];
  int lo = 0, hi = min(ix, iy) - 1;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (getMax(0, tree, mid, hi, 0, n - 1) >= max(ix, iy)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return history[lo];
}
int closest(int parent, int node, int target, int *tree, int *history,
            int *nodes, int n) {
  int iparent = nodes[parent], inode = nodes[node];
  int lo = iparent, hi = inode;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (getMin(0, tree, mid, hi, 0, n - 1, n) > target) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  return history[lo];
}
int getParent(int *history, int *tree, int i1, int i2, int n) {
  int lo = i1 + 1, hi = i2;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (getMax(0, tree, lo, mid, 0, n - 1) >= i2) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return history[lo];
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> *adj = new vector<int>[n];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adj[b - 1].push_back(a - 1);
  }
  int *history = new int[n];
  int *count = new int[n];
  int *depth = new int[n];
  int *nodes = new int[n];
  int *treeMin = new int[4 * n];
  int *treeMax = new int[4 * n];
  fillData(0, -1, 0, adj, history, depth, count, nodes, 0);
  buildMin(0, treeMin, history, depth, 0, n - 1);
  buildMax(0, treeMax, history, count, 0, n - 1);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (x == y) {
      cout << count[0] << endl;
      continue;
    }
    int parent = common(history, treeMax, nodes, x, y, n);
    int midDepth, midNode, node;
    if (parent == x || parent == y) {
      if ((depth[x] - depth[y]) % 2 != 0) {
        cout << 0 << endl;
        continue;
      }
      midDepth = (depth[x] + depth[y]) / 2;
      node = parent == x ? y : x;
    } else if ((depth[x] + depth[y] - 2 * depth[parent]) % 2 != 0) {
      cout << 0 << endl;
      continue;
    } else if (depth[x] > depth[y]) {
      midDepth = depth[x] - (depth[x] + depth[y] - 2 * depth[parent]) / 2;
      node = x;
    } else if (depth[y] > depth[x]) {
      midDepth = depth[y] - (depth[x] + depth[y] - 2 * depth[parent]) / 2;
      node = y;
    } else {
      int p1 = getParent(history, treeMax, nodes[parent], nodes[x], n);
      int p2 = getParent(history, treeMax, nodes[parent], nodes[y], n);
      cout << count[0] - count[p1] - count[p2] << endl;
      continue;
    }
    midNode = closest(parent, node, midDepth, treeMin, history, nodes, n);
    int secParent = getParent(history, treeMax, nodes[midNode], nodes[node], n);
    cout << count[midNode] - count[secParent] << endl;
  }
  return 0;
}
