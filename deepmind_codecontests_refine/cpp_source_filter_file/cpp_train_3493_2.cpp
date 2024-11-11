#include <bits/stdc++.h>
using namespace std;
double base[100005];
struct Seg {
  vector<pair<double, double> > tree;
  Seg(int V) : tree(4 * V + 2) {}
  void build(int x, int L, int R) {
    if (L == R) {
      tree[x].first = base[L];
      tree[x].second = 1.0 - base[L];
      return;
    }
    int mid = (L + R) >> 1;
    build(x + x, L, mid);
    build(x + x + 1, mid + 1, R);
    pair<double, double> p = tree[x + x], q = tree[x + x + 1];
    tree[x].first =
        p.first * q.first * (1.0 / (1.0 - (1.0 - q.first) * (1.0 - p.second)));
    tree[x].second = p.second * q.second *
                     (1.0 / (1.0 - (1.0 - p.second) * (1.0 - q.first)));
  }
  void update(int x, int L, int R, int idx, double per) {
    if (idx < L || R < idx) return;
    if (L == R && L == idx) {
      tree[x].first = per;
      tree[x].second = 1.0 - per;
      return;
    }
    int mid = (L + R) >> 1;
    update(x + x, L, mid, idx, per);
    update(x + x + 1, mid + 1, R, idx, per);
    pair<double, double> p = tree[x + x];
    pair<double, double> q = tree[x + x + 1];
    double r1 =
        p.first * q.first * (1.0 / (1.0 - (1.0 - q.first) * (1.0 - p.second)));
    double r2 = p.second * q.second *
                (1.0 / (1.0 - (1.0 - p.second) * (1.0 - q.first)));
    tree[x] = make_pair(r1, r2);
  }
  pair<double, double> domi(int x, int L, int R, int left, int right) {
    if (R < left || L > right) {
      return make_pair(1.0, 1.0);
    }
    if (left <= L && R <= right) {
      return tree[x];
    }
    int mid = (L + R) >> 1;
    pair<double, double> p = domi(x + x, L, mid, left, right);
    pair<double, double> q = domi(x + x + 1, mid + 1, R, left, right);
    double r1 =
        p.first * q.first * (1.0 / (1.0 - (1.0 - q.first) * (1.0 - p.second)));
    double r2 = p.second * q.second *
                (1.0 / (1.0 - (1.0 - p.second) * (1.0 - q.first)));
    return make_pair(r1, r2);
  }
};
int n, query;
int main() {
  scanf("%d %d", &n, &query);
  for (int a, b, i = 1; i <= n; i++) {
    scanf("%d %d", &a, &b);
    base[i] = (double)a / (double)b;
  }
  Seg seg(n);
  seg.build(1, 1, n);
  for (int ty, a, b, c, i = 1; i <= query; i++) {
    scanf("%d", &ty);
    if (ty == 1) {
      scanf("%d %d %d", &a, &b, &c);
      seg.update(1, 1, n, a, (double)b / (double)c);
    } else {
      scanf("%d %d", &a, &b);
      double key = seg.domi(1, 1, n, a, b).first;
      printf("answer%.6lf\n", key);
    }
  }
}
