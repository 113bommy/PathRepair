#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m, q, x, y;
unordered_map<int, unordered_map<int, int> > state;
template <class T>
void read(T& x, T f = 1, char ch = getchar()) {
  x = 0;
  while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
struct Node {
  Node *lson, *rson;
  int l, r;
  int miL, mxR;
  Node(int _l, int _r) {
    l = _l, r = _r;
    miL = m + 1, mxR = 0;
  }
} * root;
void update(Node* cur) {
  cur->miL = min(cur->lson->miL, cur->rson->miL);
  cur->mxR = max(cur->lson->mxR, cur->rson->mxR);
}
void build(Node*& cur, int l, int r) {
  cur = new Node(l, r);
  if (l == r) return;
  int mid = l + r >> 1;
  build(cur->lson, l, mid);
  build(cur->rson, mid + 1, r);
}
void modify(Node* cur, int x, int val, int tag) {
  if (cur->l == x && cur->r == x) {
    if (tag == 2)
      cur->mxR = max(cur->mxR, val);
    else
      cur->miL = min(cur->miL, val);
    return;
  }
  int mid = cur->l + cur->r >> 1;
  if (x <= mid)
    modify(cur->lson, x, val, tag);
  else
    modify(cur->rson, x, val, tag);
  update(cur);
}
int query(Node* cur, int l, int r, int tag) {
  if (cur->l == l && cur->r == r) {
    if (tag == 2)
      return cur->mxR;
    else
      return cur->miL;
  }
  int mid = cur->l + cur->r >> 1;
  if (r <= mid)
    return query(cur->lson, l, r, tag);
  else if (l > mid)
    return query(cur->rson, l, r, tag);
  else {
    if (tag == 2)
      return max(query(cur->lson, l, mid, tag),
                 query(cur->rson, mid + 1, r, tag));
    else
      return min(query(cur->lson, l, mid, tag),
                 query(cur->rson, mid + 1, r, tag));
  }
}
int main() {
  read(n), read(m);
  read(q);
  bool tag = 1;
  build(root, 1, n);
  while (q--) {
    read(x), read(y);
    if (!tag) {
      puts("NO");
      continue;
    }
    int i = x + 1 >> 1, j = y + 1 >> 1;
    if (!state[i][j]) {
      if (x & 1) {
        state[i][j] = 1;
        if (query(root, i, n, 2) >= j) tag = 0;
        modify(root, i, j, 1);
      } else {
        state[i][j] = 2;
        if (query(root, 1, i, 1) <= j) tag = 0;
        modify(root, i, j, 2);
      }
    } else
      tag = 0;
    if (!tag)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
