#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 7;
const int mod = 1e9 + 7;
template <class T>
inline T read() {
  char ch;
  bool flag = 0;
  T x = 0;
  while (ch = getchar(), !isdigit(ch))
    if (ch == '-') flag = 1;
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  return flag ? -x : x;
}
struct {
  inline operator long long() {
    long long _tmp;
    return scanf("%lld", &_tmp), _tmp;
  }
  inline operator int() {
    int _tmp;
    return scanf("%d", &_tmp), _tmp;
  }
  template <class T>
  inline void operator()(T &x) {
    x = *this;
  }
  template <class T, class... A>
  inline void operator()(T &x, A &...a) {
    x = *this, this->operator()(a...);
  }
} IN;
const int N = 1.2e5 + 5;
int n, m, top1, top2, a[N];
struct Node {
  int id, val;
} sta1[N], sta2[N];
int cnt[N << 2], tag[N << 2], val[N << 2], tim[N << 2];
long long ans[N << 2];
void build(int x, int l, int r) {
  cnt[x] = 1, val[x] = l;
  if (l != r)
    build(((x) << 1), l, ((l + r) >> 1)),
        build(((x) << 1 | 1), ((l + r) >> 1) + 1, r);
}
void add1(int x, int v) { tag[x] += v, val[x] += v; }
void add2(int x, int v) { ans[x] += 1ll * v * cnt[x], tim[x] += v; }
void pushdown(int x) {
  if (tag[x])
    add1(((x) << 1), tag[x]), add1(((x) << 1 | 1), tag[x]), tag[x] = 0;
  if (tim[x]) {
    if (val[x] == val[((x) << 1)]) add2(((x) << 1), tim[x]);
    if (val[x] == val[((x) << 1 | 1)]) add2(((x) << 1 | 1), tim[x]);
    tim[x] = 0;
  }
}
void pushup(int x) {
  val[x] = min(val[((x) << 1)], val[((x) << 1 | 1)]);
  cnt[x] = (val[x] == val[((x) << 1)]) * cnt[((x) << 1)] +
           (val[x] == val[((x) << 1 | 1)]) * cnt[((x) << 1 | 1)];
  ans[x] = ans[((x) << 1)] + ans[((x) << 1 | 1)];
}
void update(int x, int l, int r, int L, int R, int tmp) {
  if (L <= l && r <= R) return add1(x, tmp), void();
  pushdown(x);
  if (L <= ((l + r) >> 1)) update(((x) << 1), l, ((l + r) >> 1), L, R, tmp);
  if (R > ((l + r) >> 1))
    update(((x) << 1 | 1), ((l + r) >> 1) + 1, r, L, R, tmp);
  pushup(x);
}
int query(int x, int l, int r, int L, int R) {
  if (L == l && r == R) return ans[x];
  pushdown(x);
  if (R <= ((l + r) >> 1))
    return query(((x) << 1), l, ((l + r) >> 1), L, R);
  else if (L > ((l + r) >> 1))
    return query(((x) << 1 | 1), ((l + r) >> 1) + 1, r, L, R);
  else
    return query(((x) << 1), l, ((l + r) >> 1), L, ((l + r) >> 1)) +
           query(((x) << 1 | 1), ((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, R);
}
long long _ans[N];
int l, r;
std::vector<pair<int, int> > sta[N];
int main() {
  IN(n);
  for (int i = 1; i <= n; ++i) IN(a[i]);
  build(1, 1, n), IN(m);
  for (int i = 1; i <= m; ++i) IN(l, r), sta[r].push_back(make_pair(l, i));
  for (int i = 1; i <= n; ++i) {
    add1(1, -1);
    while (top1 && sta1[top1].val < a[i])
      update(1, 1, n, sta1[top1 - 1].id + 1, sta1[top1].id,
             a[i] - sta1[top1].val),
          --top1;
    sta1[++top1] = (Node){i, a[i]};
    while (top2 && sta2[top2].val > a[i])
      update(1, 1, n, sta2[top2 - 1].id + 1, sta2[top2].id,
             sta2[top2].val - a[i]),
          --top2;
    sta2[++top2] = (Node){i, a[i]};
    add2(1, 1);
    for (pair<int, int> now : sta[i])
      _ans[now.second] = query(1, 1, n, now.first, i);
  }
  for (int i = 1; i <= m; ++i) printf("%lld\n", _ans[i]);
  return 0;
}
