#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], n, m;
struct ST {
  int tree[4 * N];
  ST() {}
  void build(int n, int ll, int rr) {
    tree[n] = 0;
    if (ll == rr) return;
    int m = (ll + rr) / 2;
    build(2 * n, ll, m);
    build(2 * n + 1, m + 1, rr);
  }
  void push(int n, int ll, int rr, int lq, int rq, int pos) {
    if (ll == lq && rr == rq) {
      tree[n] = pos;
      return;
    }
    int m = (ll + rr) / 2;
    if (tree[n]) {
      tree[2 * n] = tree[n];
      tree[2 * n + 1] = tree[n] + (m - ll + 1);
      tree[n] = 0;
    }
    if (lq <= m) {
      push(2 * n, ll, m, lq, min(rq, m), pos);
      pos += (m - lq + 1);
    }
    if (rq > m) push(2 * n + 1, m + 1, rr, max(lq, m + 1), rq, pos);
  }
  int get(int n, int ll, int rr, int pos) {
    if (ll == rr) return tree[n];
    if (tree[n]) return tree[n] + (pos - ll);
    if (pos <= (ll + rr) / 2) return get(2 * n, ll, (ll + rr) / 2, pos);
    return get(2 * n + 1, (ll + rr) / 2 + 1, rr, pos);
  }
} t;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n + 1; ++i) scanf("%d", a + i);
  for (int i = 1; i < n + 1; ++i) scanf("%d", b + i);
  t.build(1, 1, n);
  int type, x, y, k, tmp;
  while (m--) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d%d%d", &x, &y, &k);
      t.push(1, 1, n, y, y + k - 1, x);
    } else {
      scanf("%d", &x);
      tmp = t.get(1, 1, n, x);
      if (tmp == 0)
        printf("%d\n", b[x]);
      else
        printf("%d\n", a[tmp]);
    }
  }
  return 0;
}
