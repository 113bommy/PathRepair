#include <bits/stdc++.h>
using namespace std;
ifstream in("in.in");
ofstream out("out.out");
int n, m;
const int inf = 1000000005;
struct segTree {
  int l, r, lazy = inf, Max = inf;
  segTree *lChild, *rChild;
  segTree(int l, int r) : l(l), r(r) {
    if (l != r) {
      int mij = (l + r) / 2;
      lChild = new segTree(l, mij);
      rChild = new segTree(mij + 1, r);
    }
  }
  void Recalc() { Max = max(lChild->Max, rChild->Max); }
  void UpdateNode(int x) {
    lazy = min(lazy, x);
    Max = min(Max, x);
  }
  void push() {
    (*lChild).UpdateNode(lazy);
    (*rChild).UpdateNode(lazy);
  }
  void Update(int ql, int qr, int x) {
    if (ql > r || qr < l) {
      return;
    }
    if (ql <= l && r <= qr) {
      UpdateNode(x);
      return;
    }
    push();
    if (lChild->r >= ql) (*lChild).Update(ql, qr, x);
    if (rChild->l <= qr) (*rChild).Update(ql, qr, x);
    Recalc();
  }
  int Querry(int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return Max;
    push();
    return max((*lChild).Querry(ql, qr), (*rChild).Querry(ql, qr));
  }
  void debug() {
    if (l != r) {
      (*lChild).debug();
      (*rChild).debug();
    }
  }
};
int main() {
  int i;
  cin >> n >> m;
  segTree root(0, m - 1);
  struct triple {
    int l, r, w;
    bool operator<(const triple other) const { return w > other.w; }
  };
  vector<triple> v;
  for (i = 0; i < n; i++) {
    int l, r, w;
    cin >> l >> r >> w;
    v.push_back({l - 1, r - 1, w});
  }
  sort(v.begin(), v.end());
  int cost = inf;
  for (i = 0; i < n; i++) {
    int cost_l = ((v[i].l == 0) ? -1 : root.Querry(0, v[i].l - 1));
    int cost_r = ((v[i].r == m - 1) ? -1 : root.Querry(v[i].r, m - 2));
    if (cost_l == -1 && cost_r == -1)
      cost = min(cost, 0);
    else {
      cost = min(cost, max(cost_l, cost_r) - v[i].w);
      root.Update(v[i].l, v[i].r - 1, v[i].w);
    }
  }
  cout << cost << "\n";
}
