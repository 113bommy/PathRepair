#include <bits/stdc++.h>
using namespace std;
int n, m, pos[100010], h[100010];
class segment_tree {
 public:
  int dat[800040], f[800040];
  void modify(int p, int l, int r, int pos, int v) {
    if (l == r) {
      dat[p] = v;
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
      modify((p << 1), l, mid, pos, v);
    else
      modify(((p << 1) | 1), mid + 1, r, pos, v);
    dat[p] = max(dat[(p << 1)], dat[((p << 1) | 1)]);
  }
  int query(int p, int l, int r, int R) {
    if (r <= R) return dat[p];
    int mid = (l + r) >> 1;
    if (mid < R)
      return max(query((p << 1), l, mid, R),
                 query(((p << 1) | 1), mid + 1, r, R));
    return query((p << 1), l, mid, R);
  }
  void insert(int p, int v) {
    modify(1, 0, n, p, f[p] = query(1, 0, n, p - 1) + 1);
  }
} tp, th;
int ti, tj, tk;
set<int> st;
int main() {
  scanf("%d%d", &n, &m);
  for (int T = 1; T <= m; T++) {
    scanf("%d", &ti);
    if (ti == 1) {
      scanf("%d%d", &tj, &tk);
      tj = n - tj + 1;
      tk = T + 10 - tk;
      pos[tk] = tj, h[tj] = tk;
      st.insert(tj);
      for (int i = tk + 1; i <= tk + 9; i++) {
        if (pos[i]) tp.modify(1, 0, n, pos[i], 0);
      }
      for (int i = tk; i <= tk + 9; i++) {
        if (pos[i]) {
          tp.insert(pos[i], n);
          th.f[i] = tp.f[pos[i]];
          th.modify(1, 0, m + 10, i, th.f[i]);
        }
      }
    } else {
      scanf("%d", &tj);
      set<int>::iterator it = st.end();
      while (tj--) --it, th.modify(1, 0, m + 10, h[*it], 0);
      tp.modify(1, 0, n, *it, 0);
      pos[h[*it]] = 0;
      for (st.erase(it++); it != st.end(); ++it) {
        th.insert(h[*it], m + 10);
        tp.f[*it] = th.f[h[*it]];
        tp.modify(1, 0, n, *it, tp.f[*it]);
      }
    }
    printf("%d\n", tp.dat[1]);
  }
  return 0;
}
