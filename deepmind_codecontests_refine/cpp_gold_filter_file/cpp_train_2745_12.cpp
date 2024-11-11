#include <bits/stdc++.h>
using namespace std;
int k, n, mxb, t;
int b[100010], ls[100010], x[100010];
inline int lowbit(int x) { return x & (-x); }
class tree {
 public:
  int dat[100010];
  void modify(int p, int v) {
    for (; p <= mxb; p += lowbit(p)) dat[p] = max(dat[p], v);
  }
  int query(int p) {
    int out = 0;
    for (; p; p -= lowbit(p)) out = max(out, dat[p]);
    return out;
  }
} T;
int main() {
  scanf("%d%d%d%d", &k, &n, &mxb, &t);
  while (k--) {
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]), ls[i] = b[i];
    sort(ls + 1, ls + n + 1);
    int end = unique(ls + 1, ls + n + 1) - ls - 1;
    if (t > end) {
      printf("%d\n", end);
      continue;
    }
    fill(T.dat, T.dat + mxb + 1, 0);
    memset(x, 0, sizeof(x));
    for (int i = 1; i <= t; i++) {
      for (int j = 1; j <= n; j++) {
        int v = T.query(b[j] - 1) + 1;
        if (v > x[j]) {
          x[j] = v;
          T.modify(b[j], v);
        }
      }
    }
    printf("%d\n", *max_element(x + 1, x + n + 1));
  }
  return 0;
}
