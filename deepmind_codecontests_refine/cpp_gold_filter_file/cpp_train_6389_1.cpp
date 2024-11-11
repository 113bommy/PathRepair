#include <bits/stdc++.h>
const int N = 2e5 + 15;
int pos[N], h[N];
std::set<int> st;
char IN[300000], *SS = IN, *TT = IN;
struct Segment_Tree {
  int f[N], mx[N << 2];
  void Modify(int l, int r, int rt, int p, int v) {
    if (l == r) {
      mx[rt] = v;
      return;
    }
    int m = l + r >> 1;
    if (p <= m)
      Modify(l, m, rt << 1, p, v);
    else
      Modify(m + 1, r, rt << 1 | 1, p, v);
    mx[rt] = std::max(mx[rt << 1], mx[rt << 1 | 1]);
  }
  int Query(int l, int r, int rt, int R) {
    if (r <= R) return mx[rt];
    int m = l + r >> 1;
    if (m < R)
      return std::max(Query(l, m, rt << 1, R), Query(m + 1, r, rt << 1 | 1, R));
    return Query(l, m, rt << 1, R);
  }
  void Insert(int p, int n) {
    Modify(0, n, 1, p, f[p] = Query(0, n, 1, p - 1) + 1);
  }
} Tp, Th;
inline int read() {
  int now = 0;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    ;
  for (; isdigit(c); now = now * 10 + c - '0', c = getchar())
    ;
  return now;
}
int main() {
  int n = read(), m = read();
  for (int t = 1; t <= m; ++t)
    if (read() == 1) {
      int p = n - read() + 1, ht = t + 10 - read();
      pos[ht] = p, h[p] = ht, st.insert(p);
      for (int i = ht + 1; i <= ht + 9; ++i)
        if (pos[i]) Tp.Modify(0, n, 1, pos[i], 0);
      for (int i = ht; i <= ht + 9; ++i)
        if (pos[i]) {
          Tp.Insert(pos[i], n);
          Th.f[i] = Tp.f[pos[i]];
          Th.Modify(0, m + 10, 1, i, Th.f[i]);
        }
      printf("%d\n", Tp.mx[1]);
    } else {
      int k = read();
      std::set<int>::iterator it = st.end();
      while (k--) --it, Th.Modify(0, m + 10, 1, h[*it], 0);
      Tp.Modify(0, n, 1, *it, 0), pos[h[*it]] = 0;
      for (st.erase(it++); it != st.end(); ++it) {
        Th.Insert(h[*it], m + 10);
        Tp.f[*it] = Th.f[h[*it]];
        Tp.Modify(0, n, 1, *it, Tp.f[*it]);
      }
      printf("%d\n", Tp.mx[1]);
    }
  return 0;
}
