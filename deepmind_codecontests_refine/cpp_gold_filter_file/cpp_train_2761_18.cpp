#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1000;
long long goodSum[N];
long long badSum[N];
struct i_tree1 {
  long long t[4 * N];
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = badSum[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(v + v, tl, tm);
      build(v + v + 1, tm + 1, tr);
      t[v] = t[v + v] + t[v + v + 1];
    }
  }
  void update(int v, int tl, int tr, int pos, long long new_val) {
    if (tl == tr)
      t[v] = new_val;
    else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
      else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
  long long que(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return que(v + v, tl, tm, l, min(r, tm)) +
           que(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
  }
} bad;
struct i_1_tree {
  long long t[4 * N];
  void build(int v, int tl, int tr) {
    if (tl == tr) {
      t[v] = goodSum[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(v + v, tl, tm);
      build(v + v + 1, tm + 1, tr);
      t[v] = t[v + v] + t[v + v + 1];
    }
  }
  void update(int v, int tl, int tr, int pos, long long new_val) {
    if (tl == tr)
      t[v] = new_val;
    else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
      else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
  long long que(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
      return t[v];
    }
    int tm = (tl + tr) / 2;
    return que(v + v, tl, tm, l, min(r, tm)) +
           que(v + v + 1, tm + 1, tr, max(l, tm + 1), r);
  }
} good;
int main() {
  int n, k, a, b, q;
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
  int idx = 0;
  int idx1 = 0;
  bad.build(1, 0, N - 1);
  good.build(1, 0, N - 1);
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int d, c;
      scanf("%d %d", &d, &c);
      goodSum[d] = min((long long)a, goodSum[d] + c);
      good.update(1, 0, N - 1, d, goodSum[d]);
      badSum[d] = min((long long)b, badSum[d] + c);
      bad.update(1, 0, N - 1, d, badSum[d]);
    } else {
      int p;
      scanf("%d", &p);
      int l = p;
      int r = l + k - 1;
      long long ans =
          bad.que(1, 0, N - 1, 0, l - 1) + good.que(1, 0, N - 1, r + 1, N - 1);
      printf("%d\n", ans);
    }
  }
  return 0;
}
