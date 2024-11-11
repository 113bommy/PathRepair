#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, INF = 0x3f3f3f3f;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e6 + 50;
int n, b[N];
struct _ {
  int first, second;
  long long v;
  bool operator<(const _ &rhs) const {
    int ma = max(first, second), ma2 = max(rhs.first, rhs.second);
    if (ma != ma2) return ma < ma2;
    int mi = min(first, second), mi2 = min(rhs.first, rhs.second);
    return mi > mi2;
  }
} a[N], ff[N];
int ID(int first) { return lower_bound(b + 1, b + 1 + *b, first) - b; }
struct node {
  long long v, tag;
  int pos;
  void upd(long long first) { tag += first, v += first; }
  node operator+(const node &rhs) const {
    node ret;
    ret.v = max(v, rhs.v);
    ret.pos = ret.v == v ? pos : rhs.pos;
    ret.tag = 0;
    return ret;
  }
} tr[N << 2];
void build(int o, int l, int r) {
  if (l == r)
    tr[o].v = b[l], tr[o].pos = b[l];
  else
    build((o << 1), l, ((l + r) >> 1)),
        build(((o << 1) | 1), ((l + r) >> 1) + 1, r),
        tr[o] = tr[(o << 1)] + tr[((o << 1) | 1)];
}
void pd(int o) {
  if (tr[o].tag) {
    tr[(o << 1)].upd(tr[o].tag);
    tr[((o << 1) | 1)].upd(tr[o].tag);
    tr[o].tag = 0;
  }
}
void upd(int o, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) return tr[o].upd(v);
  pd(o);
  if (((l + r) >> 1) >= ql) upd((o << 1), l, ((l + r) >> 1), ql, qr, v);
  if (((l + r) >> 1) < qr)
    upd(((o << 1) | 1), ((l + r) >> 1) + 1, r, ql, qr, v);
  tr[o] = tr[(o << 1)] + tr[((o << 1) | 1)];
}
node qry(int o, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return tr[o];
  pd(o);
  long long ans = -1e18;
  if (((l + r) >> 1) >= qr) return qry((o << 1), l, ((l + r) >> 1), ql, qr);
  if (((l + r) >> 1) < ql)
    return qry(((o << 1) | 1), ((l + r) >> 1) + 1, r, ql, qr);
  node L = qry((o << 1), l, ((l + r) >> 1), ql, qr),
       R = qry(((o << 1) | 1), ((l + r) >> 1) + 1, r, ql, qr);
  if (L.v > R.v) return L;
  return R;
}
int Ma(int i) { return max(a[i].first, a[i].second); }
int Mi(int i) { return min(a[i].first, a[i].second); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%lld", &a[i].first, &a[i].second, &a[i].v);
    b[++*b] = a[i].first, b[++*b] = a[i].second;
  }
  sort(b + 1, b + 1 + *b), *b = unique(b + 1, b + 1 + *b) - b - 1;
  for (int i = 1; i <= n; ++i)
    a[i].first = ID(a[i].first), a[i].second = ID(a[i].second);
  build(1, 1, *b);
  sort(a + 1, a + 1 + n);
  int top = 0;
  for (int i = 1; i <= n; ++i) {
    if (!top)
      ff[++top] = a[i];
    else {
      if (ff[top].first == a[i].first && ff[top].second == a[i].second)
        ff[top].v += a[i].v;
      else
        ff[++top] = a[i];
    }
  }
  n = top;
  for (int i = 1; i <= n; ++i) a[i] = ff[i];
  long long ans = 0;
  int posl = 2e9, posr = 2e9;
  for (int i = 1; i <= n; ++i) {
    int j = i;
    while (j < n && Ma(j + 1) == Ma(i)) ++j;
    int R = -b[Ma(i)];
    for (int k = i; k <= j; ++k) {
      upd(1, 1, *b, 1, Mi(k), a[k].v);
    }
    node pp = qry(1, 1, *b, 1, Ma(i));
    long long ret = R + pp.v;
    if (ret > ans) {
      ans = ret;
      posl = pp.pos, posr = b[Ma(i)];
    }
    i = j;
  }
  printf("%lld\n", ans);
  printf("%d %d %d %d\n", posl, posl, posr, posr);
}
