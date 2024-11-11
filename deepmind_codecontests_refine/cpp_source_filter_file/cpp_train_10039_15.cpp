#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int INF = 2000000;
int a, b, c, d, e, f, g, h, i, j;
int G[N], K, D;
struct Segment_Tree {
  struct node {
    int left, right;
    int delta, Min;
  };
  node tree[N << 2];
  void Build(int root, int left, int right) {
    tree[root].left = left, tree[root].right = right;
    tree[root].delta = tree[root].Min = 0;
    if (left == right) return;
    int mid = (left + right) >> 1;
    Build(root << 1, left, mid);
    Build(root << 1 | 1, mid + 1, right);
  }
  void Update(int root) {
    if (root > (a << 2) || tree[root].delta == 0) return;
    if (tree[root].left != tree[root].right) {
      tree[root << 1].delta += tree[root].delta;
      tree[root << 1 | 1].delta += tree[root].delta;
    }
    tree[root].Min += tree[root].delta;
    tree[root].delta = 0;
  }
  void Add(int root, int ll, int rr, int delta) {
    int mid = (tree[root].left + tree[root].right) >> 1;
    Update(root);
    if (tree[root].left == ll && tree[root].right == rr) {
      tree[root].delta += delta, Update(root);
      return;
    }
    if (rr <= mid)
      Add(root << 1, ll, rr, delta);
    else if (ll > mid)
      Add(root << 1 | 1, ll, rr, delta);
    else {
      Add(root << 1, ll, mid, delta);
      Add(root << 1 | 1, mid + 1, rr, delta);
    }
    Update(root << 1), Update(root << 1 | 1);
    tree[root].Min = min(tree[root << 1].Min, tree[root << 1 | 1].Min);
  }
  int Find(int root) {
    Update(root), Update(root << 1), Update(root << 1 | 1);
    if (tree[root].Min > K) return -1;
    if (tree[root].left == tree[root].right) return tree[root].left;
    if (tree[root << 1].Min <= K) return Find(root << 1);
    if (tree[root << 1 | 1].Min <= K) return Find(root << 1 | 1);
  }
};
Segment_Tree T;
int Best;
pair<int, int> an;
int main() {
  cin >> a >> K >> D;
  for (i = 1; i <= a; i++) cin >> G[i], G[i] += INF + 1;
  if (D == 0) {
    int last = 1;
    for (i = 1; i <= a; i++) {
      if (i == 1 || G[i] != G[i - 1]) last = i;
      if (i - last + 1 >= Best) Best = i - last + 1, an = make_pair(last, i);
    }
    cout << an.first << " " << an.second << endl;
    return 0;
  }
  T.Build(1, 1, a), T.Add(1, 1, a, INF);
  int last = 1;
  map<int, int> E;
  stack<int> Z1, Z2;
  Z1.push(0), Z2.push(0);
  for (i = 1; i <= a; i++) {
    if (i == 1 || (G[i] - G[i - 1]) % D != 0) {
      if (i != 1) T.Add(1, last, i - 1, INF);
      last = i;
    }
    if (E.count(G[i]) && E[G[i]] >= last) {
      T.Add(1, last, E[G[i]], INF);
      last = E[G[i]] + 1;
    }
    E[G[i]] = i;
    while (Z1.top() != 0 && G[i] > G[Z1.top()]) {
      int rr = Z1.top();
      Z1.pop();
      T.Add(1, Z1.top() + 1, rr, G[i] / D - G[rr] / D);
    }
    while (Z2.top() != 0 && G[i] < G[Z2.top()]) {
      int rr = Z2.top();
      Z2.pop();
      T.Add(1, Z2.top() + 1, rr, G[rr] / D - G[i] / D);
    }
    Z1.push(i), Z2.push(i);
    T.Add(1, i, i, -INF + i);
    K++;
    int L = T.Find(1);
    if (L != -1 && i - L + 1 > Best) {
      Best = i - L + 1;
      an = make_pair(L, i);
    }
  }
  cout << an.first << " " << an.second << endl;
  return 0;
}
