#include <bits/stdc++.h>
const int bufSize = 1e6;
inline char nc() {
  return getchar();
  static char buf[bufSize], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, bufSize, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename T>
inline T read(T &r) {
  static char c;
  static int flag;
  flag = 1, r = 0;
  for (c = nc(); !isdigit(c); c = nc())
    if (c == '-') flag = -1;
  for (; isdigit(c); c = nc()) r = r * 10 + c - 48;
  return r *= flag;
}
const int maxn = 2e6 + 100;
int m, opt[maxn], tot, L[maxn], R[maxn], full[maxn], val[maxn], rev[maxn],
    set[maxn];
long long LL[maxn], RR[maxn], H[maxn];
inline void pushup(int p) {
  if (full[p << 1] && full[p << 1 | 1] && val[p << 1] == val[p << 1 | 1])
    full[p] = 1, val[p] = val[p << 1];
  else
    full[p] = 0, val[p] = 0;
}
inline void pushset(int p, int k) {
  full[p] = 1, val[p] = k, set[p] = k, rev[p] = 0;
}
inline void pushrev(int p) { val[p] ^= 1, rev[p] ^= 1; }
inline void pushdown(int p) {
  if (set[p] != -1)
    pushset(p << 1, set[p]), pushset(p << 1 | 1, set[p]), set[p] = -1;
  if (rev[p]) pushrev(p << 1), pushrev(p << 1 | 1), rev[p] = 0;
}
void build(int l, int r, int p) {
  set[p] = -1, full[p] = 1;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, p << 1), build(mid + 1, r, p << 1 | 1);
}
void modify(int l, int r, int p, int ll, int rr, int k) {
  pushdown(p);
  if (l >= ll && r <= rr) return (void)(pushset(p, k));
  int mid = (l + r) >> 1;
  if (ll <= mid) modify(l, mid, p << 1, ll, rr, k);
  if (rr > mid) modify(mid + 1, r, p << 1 | 1, ll, rr, k);
  pushup(p);
}
void reverse(int l, int r, int p, int ll, int rr) {
  pushdown(p);
  if (l >= ll && r <= rr) return (void)(pushrev(p));
  int mid = (l + r) >> 1;
  if (ll <= mid) reverse(l, mid, p << 1, ll, rr);
  if (rr > mid) reverse(mid + 1, r, p << 1 | 1, ll, rr);
  pushup(p);
}
int find(int l, int r, int p) {
  pushdown(p);
  if (l == r) return l;
  int mid = (l + r) >> 1;
  if (full[p << 1] && val[p << 1]) return find(mid + 1, r, p << 1 | 1);
  return find(l, mid, p << 1);
}
int main() {
  read(m);
  H[++tot] = 1;
  for (int i = 1; i <= m; ++i) {
    read(opt[i]), read(LL[i]), read(RR[i]), H[++tot] = LL[i], H[++tot] = RR[i],
                                            H[++tot] = RR[i] + 1;
    if (LL[i] > 1) H[++tot] = LL[i] - 1;
  }
  std::sort(H + 1, H + 1 + tot), tot = std::unique(H + 1, H + 1 + tot) - H - 1;
  for (int i = 1; i <= m; ++i)
    LL[i] = std::lower_bound(H + 1, H + 1 + tot, LL[i]) - H,
    RR[i] = std::lower_bound(H + 1, H + 1 + tot, RR[i]) - H;
  build(1, tot, 1);
  for (int i = 1; i <= m; ++i) {
    if (opt[i] == 1)
      modify(1, tot, 1, LL[i], RR[i], 1);
    else if (opt[i] == 2)
      modify(1, tot, 1, LL[i], RR[i], 0);
    else
      reverse(1, tot, 1, LL[i], RR[i]);
    printf("%lld\n", H[find(1, tot, 1)]);
  }
  return 0;
}
