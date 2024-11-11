#include <bits/stdc++.h>
using namespace std;
using dd = long double;
struct Tree {
  struct Node {
    dd mul;
    dd add;
    dd sum;
    Node() : mul(1), add(0), sum(0) {}
  };
  int S;
  vector<Node> drz;
  void update(int v) { drz[v].sum = drz[2 * v].sum + drz[2 * v + 1].sum; }
  Tree(const vector<int>& tab) {
    int n = tab.size();
    S = 1;
    while (S < n) {
      S *= 2;
    }
    drz.resize(2 * S);
    for (int i = 0; i < n; i++) {
      drz[i + S].sum = tab[i];
    }
    for (int v = S - 1; v; v--) {
      update(v);
    }
  }
  void receive(int v, int len, dd mul, dd add) {
    drz[v].sum = drz[v].sum * mul + add * len;
    drz[v].mul *= mul;
    drz[v].add = drz[v].add * mul + add;
  }
  void push(int v, int len) {
    dd mul = drz[v].mul;
    dd add = drz[v].add;
    receive(2 * v, len / 2, mul, add);
    receive(2 * v + 1, len / 2, mul, add);
    drz[v].mul = 1;
    drz[v].add = 0;
  }
  void mul_add_rec(int v, int vl, int vr, int l, int r, dd mul, dd add) {
    if (vl > r || l > vr) {
      return;
    }
    if (l <= vl && vr <= r) {
      receive(v, vr - vl + 1, mul, add);
      return;
    }
    push(v, vr - vl + 1);
    int vc = (vl + vr) / 2;
    mul_add_rec(2 * v, vl, vc, l, r, mul, add);
    mul_add_rec(2 * v + 1, vc + 1, vr, l, r, mul, add);
    update(v);
  }
  void mul_add(int l, int r, dd mul, dd add) {
    mul_add_rec(1, 0, S - 1, l, r, mul, add);
  }
  dd sum_rec(int v, int vl, int vr, int l, int r) {
    if (vl > r || l > vr) {
      return 0;
    }
    if (l <= vl && vr <= r) {
      return drz[v].sum;
    }
    push(v, vr - vl + 1);
    int vc = (vl + vr) / 2;
    return sum_rec(2 * v, vl, vc, l, r) + sum_rec(2 * v + 1, vc + 1, vr, l, r);
  }
  dd sum(int l, int r) { return sum_rec(1, 0, S - 1, l, r); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> tab(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> tab[i];
  }
  Tree tree(tab);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      auto sum1 = tree.sum(l1, r1);
      auto sum2 = tree.sum(l2, r2);
      int len1 = r1 - l1 + 1;
      int len2 = r2 - l2 + 1;
      tree.mul_add(l1, r1, 1.0 * (len1 - 1) / len1, 1.0 * sum2 / (len1 * len2));
      tree.mul_add(l2, r2, 1.0 * (len2 - 1) / len2, 1.0 * sum1 / (len1 * len2));
    } else {
      int l, r;
      cin >> l >> r;
      cout << setprecision(10) << fixed << tree.sum(l, r) << "\n";
    }
  }
}
