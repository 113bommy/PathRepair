#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
inline int read() {
  int x(0), sgn(1);
  char ch(getchar());
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
  return x * sgn;
}
void File() {}
template <int Maxn>
struct Segment_Tree {
  int ls[Maxn], rs[Maxn], tot[Maxn], Size;
  Segment_Tree() { Size = 0; }
  long long res[Maxn], val[Maxn];
  inline void Push_Up(int o) {
    tot[o] = tot[ls[o]] + tot[rs[o]];
    val[o] = val[ls[o]] + val[rs[o]];
    res[o] = res[ls[o]] + res[rs[o]] + val[ls[o]] * tot[rs[o]];
  }
  void Update(int &o, int l, int r, int up) {
    if (!o) o = ++Size;
    if (l == r) {
      tot[o] = 1;
      val[o] = up;
      return;
    }
    int mid = (l + r) >> 1;
    if (up <= mid)
      Update(ls[o], l, mid, up);
    else
      Update(rs[o], mid + 1, r, up);
    Push_Up(o);
  }
  int Merge(int x, int y, int l, int r) {
    if (!x || !y) return x | y;
    int mid = (l + r) >> 1;
    ls[x] = Merge(ls[x], ls[y], l, mid);
    rs[x] = Merge(rs[x], rs[y], mid + 1, r);
    Push_Up(x);
    return x;
  }
};
const int N = 4e5 + 1e3;
Segment_Tree<N * 20> T;
int rt[N], fa[N], lb[N], rb[N], n;
long long ans = 0;
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void Merge(int x, int y) {
  x = find(x);
  y = find(y);
  fa[y] = x;
  ans -= T.res[rt[x]] + 1ll * lb[x] * T.val[rt[x]];
  ans -= T.res[rt[y]] + 1ll * lb[y] * T.val[rt[y]];
  chkmin(lb[x], lb[y]);
  chkmax(rb[x], rb[y]);
  rt[x] = T.Merge(rt[x], rt[y], 1, n);
  ans += T.res[rt[x]] + 1ll * lb[x] * T.val[rt[x]];
}
int main() {
  File();
  n = read();
  for (register int i = (1), iend = (int)(N - 1e3); i <= iend; ++i)
    lb[i] = rb[i] = fa[i] = i;
  for (register int i = (1), iend = (int)(n); i <= iend; ++i) {
    int a = read(), b = read(), t;
    ans -= 1ll * a * b;
    t = rt[find(a)] ? rb[find(a)] + 1 : a;
    T.Update(rt[t], 1, n, b);
    ans += T.res[rt[t]] + 1ll * t * T.val[rt[t]];
    if (rt[find(t - 1)]) Merge(t, t - 1);
    if (rt[find(t + 1)]) Merge(t + 1, t);
    printf("%lld\n", ans);
  }
  return 0;
}
