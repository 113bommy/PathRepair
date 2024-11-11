#include <bits/stdc++.h>
const int MAXN = 1e5 + 10;
int a[MAXN], n;
namespace solver1 {
namespace seg_tree {
const int SIZE = 1e6;
struct Data {
  int max, maxl, maxr;
  int maxp_l, maxp_r, maxlp, maxrp;
  int min, minl, minr;
  int minp_l, minp_r, minlp, minrp;
  int sum;
  void rev() {
    sum = -sum;
    std::swap(max, min), max = -max, min = -min;
    std::swap(maxl, minl), maxl = -maxl, minl = -minl;
    std::swap(maxr, minr), maxr = -maxr, minr = -minr;
    std::swap(maxp_l, minp_l);
    std::swap(maxp_r, minp_r);
    std::swap(maxlp, minlp);
    std::swap(maxrp, minrp);
  }
  void set(int x, int p) {
    sum = x;
    if (x > 0) {
      max = maxl = maxr = x;
      min = minl = minr = 0;
      maxp_l = maxp_r = maxlp = maxrp = p;
      minlp = p - 1;
      minrp = p + 1;
      minp_l = p + 1;
      minp_r = p;
    } else if (x < 0) {
      min = minl = minr = x;
      max = maxl = maxr = 0;
      minp_l = minp_r = minlp = minrp = p;
      maxlp = p - 1;
      maxrp = p + 1;
      maxp_l = p + 1, maxp_r = p;
    } else {
      max = maxl = maxr = min = minl = minr = x;
      maxp_l = maxp_r = maxlp = maxrp = minp_l = minp_r = minlp = minrp = p;
    }
  }
};
struct Node {
  int ls, rs;
  Data data;
  bool tag;
} tree[SIZE];
int root, cnt;
void rev(Node& node) {
  node.data.rev();
  node.tag ^= 1;
}
void merge(Data left, Data right, Data& res) {
  res.sum = left.sum + right.sum;
  res.max = left.max;
  res.maxp_l = left.maxp_l;
  res.maxp_r = left.maxp_r;
  if (right.max > res.max) {
    res.max = right.max;
    res.maxp_l = right.maxp_l;
    res.maxp_r = right.maxp_r;
  }
  if (right.maxl + left.maxr > res.max) {
    res.max = right.maxl + left.maxr;
    res.maxp_l = left.maxrp;
    res.maxp_r = right.maxlp;
  }
  res.min = left.min;
  res.minp_l = left.minp_l;
  res.minp_r = left.minp_r;
  if (right.min < res.min) {
    res.min = right.min;
    res.minp_l = right.minp_l;
    res.minp_r = right.minp_r;
  }
  if (right.minl + left.minr < res.min) {
    res.min = right.minl + left.minr;
    res.minp_l = left.minrp;
    res.minp_r = right.minlp;
  }
  res.maxl = left.maxl;
  res.maxlp = left.maxlp;
  if (left.sum + right.maxl > res.maxl) {
    res.maxl = left.sum + right.maxl;
    res.maxlp = right.maxlp;
  }
  res.minl = left.minl;
  res.minlp = left.minlp;
  if (left.sum + right.minl < res.minl) {
    res.minl = left.sum + right.minl;
    res.minlp = right.minlp;
  }
  res.maxr = right.maxr;
  res.maxrp = right.maxrp;
  if (right.sum + left.maxr > res.maxr) {
    res.maxr = right.sum + left.maxr;
    res.maxrp = left.maxrp;
  }
  res.minr = right.minr;
  res.minrp = right.minrp;
  if (right.sum + left.minr > res.minr) {
    res.minr = right.sum + left.minr;
    res.minrp = left.minrp;
  }
}
void update(Node& tmp) {
  merge(tree[tmp.ls].data, tree[tmp.rs].data, tmp.data);
}
void push_down(Node& tmp) {
  if (tmp.tag) {
    tmp.tag = 0;
    rev(tree[tmp.ls]);
    rev(tree[tmp.rs]);
  }
}
void _build(int& node, int l, int r) {
  node = ++cnt;
  if (l == r) {
    tree[node].data.set(a[l], l);
    return;
  }
  int mid = (l + r) >> 1;
  _build(tree[node].ls, l, mid);
  _build(tree[node].rs, mid + 1, r);
  update(tree[node]);
}
void build() { _build(root, 1, n); }
int p, v;
int ql, qr;
void _modify(int node, int l, int r) {
  if (l == r) {
    tree[node].data.set(v, p);
    return;
  }
  push_down(tree[node]);
  int mid = (l + r) >> 1;
  if (p <= mid)
    _modify(tree[node].ls, l, mid);
  else
    _modify(tree[node].rs, mid + 1, r);
  update(tree[node]);
}
void modify(int _p, int _v) {
  p = _p, v = _v;
  _modify(root, 1, n);
}
void _nega(int node, int l, int r) {
  if (ql <= l && r <= qr) {
    rev(tree[node]);
    return;
  }
  push_down(tree[node]);
  int mid = (l + r) >> 1;
  if (ql <= mid) _nega(tree[node].ls, l, mid);
  if (qr > mid) _nega(tree[node].rs, mid + 1, r);
  update(tree[node]);
}
void nega(int l, int r) {
  if (l > r) return;
  ql = l, qr = r;
  _nega(root, 1, n);
}
Data _query(int node, int l, int r) {
  if (ql <= l && r <= qr) {
    return tree[node].data;
  }
  push_down(tree[node]);
  int mid = (l + r) >> 1;
  Data ans1, ans2;
  bool flag1 = 0, flag2 = 0;
  if (ql <= mid) flag1 = 1, ans1 = _query(tree[node].ls, l, mid);
  if (qr > mid) flag2 = 1, ans2 = _query(tree[node].rs, mid + 1, r);
  if (flag1 && flag2) {
    merge(ans1, ans2, ans1);
    return ans1;
  } else if (flag1) {
    return ans1;
  } else {
    return ans2;
  }
}
int query(int l, int r, int& ansl, int& ansr) {
  ql = l, qr = r;
  Data ans = _query(root, 1, n);
  ansl = ans.maxp_l;
  ansr = ans.maxp_r;
  return ans.max;
}
}  // namespace seg_tree
void work(int l, int r, int k) {
  int rangel[50], ranger[50], ans = 0;
  for (int i = 1; i <= k; i++) {
    int tmp = seg_tree::query(l, r, rangel[i], ranger[i]);
    if (tmp <= 0) {
      k = i - 1;
      break;
    }
    seg_tree::nega(rangel[i], ranger[i]);
    ans += tmp;
  }
  for (int i = 1; i <= k; i++) {
    seg_tree::nega(rangel[i], ranger[i]);
  }
  printf("%d\n", ans);
}
void main() {
  int type;
  scanf("%d", &type);
  if (type == 0) {
    int p, v;
    scanf("%d%d", &p, &v);
    seg_tree::modify(p, v);
  } else {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    work(l, r, k);
  }
}
}  // namespace solver1
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  solver1::seg_tree::build();
  int q;
  scanf("%d", &q);
  while (q--) {
    solver1::main();
  }
}
