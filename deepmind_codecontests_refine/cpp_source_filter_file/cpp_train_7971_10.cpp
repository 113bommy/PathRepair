#include <bits/stdc++.h>
static const int N = 500010;
int n, numn = 1, rank[N];
std ::pair<int, int> a[N];
struct SegmentTree {
  int tag, child[2];
  std ::pair<int, int> mn;
} node[N << 2];
void add(int root, int val) {
  node[root].tag += val, node[root].mn.first += val;
}
void push(int root) {
  if (node[root].tag) {
    add(node[root].child[0], node[root].tag),
        add(node[root].child[1], node[root].tag);
    node[root].tag = 0;
  }
}
void update(int root) {
  node[root].mn =
      min(node[node[root].child[0]].mn, node[node[root].child[1]].mn);
}
int insert(int root, int nl, int nr, int l, int r, int val) {
  if (l > nr || nl > r) return root;
  if (!root) root = ++numn;
  if (l <= nl && nr <= r) {
    add(root, val);
    if (l == r) node[root].mn.second = l;
    return root;
  }
  push(root);
  int mid = (nl + nr) >> 1;
  node[root].child[0] = insert(node[root].child[0], nl, mid, l, r, val);
  node[root].child[1] = insert(node[root].child[1], mid + 1, nr, l, r, val);
  update(root);
  return root;
}
std ::pair<int, int> query(int root, int nl, int nr, int l, int r) {
  if (l > nr || nl > r) return std ::make_pair(1e9, 1e9);
  if (l <= nl && nr <= r) return node[root].mn;
  push(root);
  int mid = (nl + nr) >> 1;
  return min(query(node[root].child[0], nl, mid, l, r),
             query(node[root].child[1], mid + 1, nr, l, r));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].first), a[i].second = i;
  std ::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) rank[a[i].second] = i;
  for (int i = 1; i <= n; ++i) insert(1, 1, n, i, i, a[i].first);
  std ::set<int> neg, zer, pos;
  for (int i = 1; i <= n; ++i) {
    int t = rank[i];
    std ::pair<int, int> rec = query(1, 1, n, t, t);
    if (!rec.first)
      zer.insert(t);
    else if (rec.first < 0) {
      neg.insert(t), insert(1, 1, n, t, n, 1);
      int ln = *(--neg.end());
      if (a[ln].first == 1 - (int)neg.size()) {
        neg.erase(t), zer.insert(t), insert(1, 1, n, ln, n, -1);
      } else if (!zer.empty()) {
        int fz = *(zer.begin());
        zer.erase(fz), pos.insert(fz), insert(1, 1, n, fz, n, -1);
      }
    } else {
      pos.insert(t), insert(1, 1, n, t, n, -1);
      std ::pair<int, int> rec = query(1, 1, n, t, n);
      if (!~rec.first) {
        pos.erase(rec.second), zer.insert(rec.second),
            insert(1, 1, n, rec.second, n, 1);
      }
    }
    printf("%d\n", (int)pos.size() - (int)neg.size());
  }
  return 0;
}
