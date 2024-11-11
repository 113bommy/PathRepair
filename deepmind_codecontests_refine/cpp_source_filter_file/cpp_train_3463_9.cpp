#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct OP {
  double flag;
  int st, ed, lft;
  OP() {}
  OP(int a, int b, double c, int d) {
    st = a;
    ed = b;
    flag = c;
    lft = d;
  }
};
struct node {
  double P;
  int lft, rht, flag;
  int mid() { return (lft + ((rht - lft) >> 1)); }
  void fun(double tmp) {
    P *= tmp;
    flag = 1;
  }
};
int B[N], Z[N];
vector<OP> op;
vector<int> Y;
map<int, int> H;
struct Segtree {
  node tree[N * 4 * 4];
  void PushDown(int ind) {
    if (tree[ind].flag) {
      tree[(ind << 1)].fun(tree[ind].P);
      tree[(ind << 1 | 1)].fun(tree[ind].P);
      tree[ind].flag = 0;
      tree[ind].P = 1;
    }
  }
  void build(int lft, int rht, int ind) {
    tree[ind].lft = lft;
    tree[ind].rht = rht;
    tree[ind].P = 1;
    tree[ind].flag = 0;
    if (lft != rht) {
      int mid = tree[ind].mid();
      build(lft, mid, (ind << 1));
      build(mid + 1, rht, (ind << 1 | 1));
    }
  }
  void updata(int st, int ed, int ind, double flag) {
    int lft = tree[ind].lft, rht = tree[ind].rht;
    if (st <= lft && rht <= ed)
      tree[ind].fun(flag);
    else {
      PushDown(ind);
      int mid = tree[ind].mid();
      if (st <= mid) updata(st, ed, (ind << 1), flag);
      if (ed > mid) updata(st, ed, (ind << 1 | 1), flag);
    }
  }
  double query(int pos, int ind) {
    if (tree[ind].lft == tree[ind].rht)
      return tree[ind].P;
    else {
      PushDown(ind);
      int mid = tree[ind].mid();
      if (pos <= mid)
        return query(pos, (ind << 1));
      else
        return query(pos, (ind << 1 | 1));
    }
  }
} seg;
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    Y.clear();
    H.clear();
    op.clear();
    for (int i = 0; i < n; i++) {
      int a, b, c, d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      Y.push_back(a - b);
      Y.push_back(a + b);
      Y.push_back(a);
      op.push_back(OP(a - b, a, (100 - c) / 100.0, 1));
      op.push_back(OP(a, a + b, (100 - c) / 100.0, 0));
    }
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &B[i], &Z[i]);
      Y.push_back(B[i]);
    }
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    for (int i = 0; i < (int)Y.size(); i++) H[Y[i]] = i;
    seg.build(0, (int)Y.size(), 1);
    for (int i = 0; i < (int)op.size(); i++) {
      if (op[i].lft)
        seg.updata(H[op[i].st], H[op[i].ed] - 1, 1, op[i].flag);
      else
        seg.updata(H[op[i].st] + 1, H[op[i].ed], 1, op[i].flag);
    }
    double res = 0;
    for (int i = 0; i < m; i++) {
      res += Z[i] * seg.query(H[B[i]], 1);
    }
    printf("%.4lf\n", res);
  }
  return 0;
}
