#include <bits/stdc++.h>
using std::cerr;
using std::endl;
struct IO {
  const static int S = 120000 * 20 * 2;
  char buc_in[S], buc_out[S], *p_in = buc_in, *p_out = buc_out;
  IO() { fread(buc_in, 1, S, stdin); }
  ~IO() { fwrite(buc_out, 1, p_out - buc_out, stdout); }
  inline int rd() {
    int ret = 0;
    while (!isdigit(*p_in)) ++p_in;
    while (isdigit(*p_in)) ret = ret * 10 + *p_in++ - '0';
    return ret;
  }
  inline void out(long long x) {
    static char buc[30], *p = buc;
    do *p++ = x % 10 + '0';
    while (x /= 10);
    while (p != buc) *p_out++ = *--p;
    *p_out++ = '\n';
  }
} io;
const int N = 120000 + 233;
int n, p[N], q;
int ql[N], qr[N], id[N];
long long ans[N];
struct SegTree {
  int min, min_cnt, tag_min, tag_ans;
  long long ans;
} seg[N * 4];
inline void pushup(int p) {
  seg[p].min = std::min(seg[(p << 1)].min, seg[(p << 1 | 1)].min);
  seg[p].min_cnt = seg[p].min == seg[(p << 1)].min ? seg[(p << 1)].min_cnt
                                                   : seg[(p << 1 | 1)].min_cnt;
  if (seg[(p << 1)].min == seg[(p << 1 | 1)].min)
    seg[p].min_cnt = seg[(p << 1)].min_cnt + seg[(p << 1 | 1)].min_cnt;
  seg[p].ans = seg[(p << 1)].ans + seg[(p << 1 | 1)].ans;
}
inline void push_min(int p, int v) { seg[p].min += v, seg[p].tag_min += v; }
inline void push_ans(int p, int v) {
  seg[p].ans += 1ll * seg[p].min_cnt * v;
  seg[p].tag_ans += v;
}
inline void pushdown(int p) {
  if (seg[p].tag_min) {
    push_min((p << 1), seg[p].tag_min);
    push_min((p << 1 | 1), seg[p].tag_min);
    seg[p].tag_min = 0;
  }
  if (seg[p].tag_ans) {
    if (seg[(p << 1)].min == seg[p].min) push_ans((p << 1), seg[p].tag_ans);
    if (seg[(p << 1 | 1)].min == seg[p].min)
      push_ans((p << 1 | 1), seg[p].tag_ans);
    seg[p].tag_ans = 0;
  }
}
void build(int p, int L, int R) {
  if (L == R) {
    seg[p].min = L;
    seg[p].min_cnt = 1;
    return;
  }
  build((p << 1), L, ((L + R) >> 1));
  build((p << 1 | 1), ((L + R) >> 1) + 1, R);
  pushup(p);
}
void modify(int p, int l, int r, int v, int L, int R) {
  if (l <= L && r >= R) return push_min(p, v);
  pushdown(p);
  if (l <= ((L + R) >> 1)) modify((p << 1), l, r, v, L, ((L + R) >> 1));
  if (r > ((L + R) >> 1)) modify((p << 1 | 1), l, r, v, ((L + R) >> 1) + 1, R);
  pushup(p);
}
int query(int p, int l, int r, int L, int R) {
  if (l <= L && r >= R) return seg[p].ans;
  pushdown(p);
  long long ret = 0;
  if (l <= ((L + R) >> 1)) ret += query((p << 1), l, r, L, ((L + R) >> 1));
  if (r > ((L + R) >> 1))
    ret += query((p << 1 | 1), l, r, ((L + R) >> 1) + 1, R);
  return ret;
}
int stk_min[N], top_min, stk_max[N], top_max;
inline void modify(int x) {
  while (top_min && p[stk_min[top_min]] > p[x]) {
    modify(1, stk_min[top_min - 1] + 1, stk_min[top_min],
           p[stk_min[top_min]] - p[x], 1, n);
    --top_min;
  }
  stk_min[++top_min] = x;
  while (top_max && p[stk_max[top_max]] < p[x]) {
    modify(1, stk_max[top_max - 1] + 1, stk_max[top_max],
           p[x] - p[stk_max[top_max]], 1, n);
    --top_max;
  }
  stk_max[++top_max] = x;
  push_min(1, -1);
  push_ans(1, 1);
}
int main() {
  n = io.rd();
  for (int i = 1; i <= n; ++i) p[i] = io.rd();
  q = io.rd();
  for (int i = 1; i <= q; ++i) ql[i] = io.rd(), qr[i] = io.rd(), id[i] = i;
  std::sort(id + 1, id + q + 1, [&](int x, int y) {
    return qr[x] == qr[y] ? ql[x] < ql[y] : qr[x] < qr[y];
  });
  build(1, 1, n);
  for (int i = 1, j = 1; i <= n; ++i) {
    modify(i);
    while (j <= q && qr[id[j]] < i) ++j;
    while (j <= q && qr[id[j]] == i)
      ans[id[j]] = query(1, ql[id[j]], i, 1, n), ++j;
  }
  for (int i = 1; i <= q; ++i) io.out(ans[i]);
  return 0;
}
