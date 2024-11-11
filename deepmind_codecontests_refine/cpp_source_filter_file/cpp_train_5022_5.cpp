#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
const int P = 1004535809;
const int base = 131;
inline long long quickpow(long long x, int k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * x % P;
    x = x * x % P;
    k >>= 1;
  }
  return res;
}
int n, h[101000], K;
long long jzppw[101000 + 101000];
long long *pw = jzppw + 101000;
inline void init() {
  const int ibase = quickpow(base, P - 2);
  pw[0] = 1;
  const int up = n;
  for (int i = 1; i <= up; ++i) pw[i] = pw[i - 1] * base % P;
  for (int i = -1; i >= -up; --i) pw[i] = pw[i + 1] * ibase % P;
}
struct Str {
  long long ha;
  int len;
  Str() { ha = len = 0; }
  Str(long long jzp, int zzz) { ha = jzp, len = zzz; }
  inline bool operator==(const Str &a) const {
    return ha == a.ha && len == a.len;
  }
  inline Str operator+(const Str &a) const {
    return Str((ha * pw[a.len] + a.ha) % P, len + a.len);
  }
  inline Str operator-(const Str &a) const {
    return Str(((ha - a.ha * pw[len - a.len]) % P + P) % P, len - a.len);
  }
};
struct Data {
  int ls, rs;
  Str lb, rb;
  bool isw;
  Data() {
    ls = rs = isw = 0;
    lb = rb = Str();
  }
} dat[101000 << 2];
Str query_R(int len, int cur) {
  if (len == dat[cur].rb.len) return dat[cur].rb;
  if (!len) return Str();
  int l = dat[dat[cur].rs].rb.len;
  if (l < len)
    return dat[dat[cur].rs].rb +
           (query_R(len - l + dat[dat[cur].rs].lb.len, dat[cur].ls) -
            dat[dat[cur].rs].lb);
  return query_R(len, dat[cur].rs);
}
Str query_L(int len, int cur) {
  if (len == dat[cur].lb.len) return dat[cur].lb;
  if (!len) return Str();
  int l = dat[dat[cur].ls].lb.len;
  if (l < len)
    return dat[dat[cur].ls].lb +
           (query_L(len - l + dat[dat[cur].ls].rb.len, dat[cur].rs) -
            dat[dat[cur].ls].rb);
  return query_L(len, dat[cur].ls);
}
inline void pushup(int cur) {
  if (dat[dat[cur].ls].isw || dat[dat[cur].rs].isw)
    return dat[cur].isw = true, void();
  dat[cur].isw = false;
  if (dat[dat[cur].ls].rb.len > dat[dat[cur].rs].lb.len) {
    dat[cur].lb = dat[dat[cur].ls].lb;
    Str str = query_R(dat[dat[cur].rs].lb.len, dat[cur].ls);
    if (str == dat[dat[cur].rs].lb)
      dat[cur].rb =
          dat[dat[cur].rs].rb + (dat[dat[cur].ls].rb - dat[dat[cur].rs].lb);
    else
      dat[cur].isw = true;
  } else {
    dat[cur].rb = dat[dat[cur].rs].rb;
    Str str = query_L(dat[dat[cur].ls].rb.len, dat[cur].rs);
    if (str == dat[dat[cur].ls].rb)
      dat[cur].lb =
          dat[dat[cur].ls].lb + (dat[dat[cur].rs].lb - dat[dat[cur].ls].rb);
    else
      dat[cur].isw = true;
  }
}
int root, ttot;
void build(int L, int R, int &cur) {
  cur = ++ttot;
  if (L == R)
    return h[L] > 0 ? dat[cur].rb = Str(h[L], 1) : dat[cur].lb = Str(-h[L], 1),
                      void();
  int mid = (L + R) >> 1;
  build(L, mid, dat[cur].ls);
  build(mid + 1, R, dat[cur].rs);
  pushup(cur);
}
void modify(int L, int R, int pos, int v, int cur) {
  if (L == R) {
    dat[cur].lb = dat[cur].rb = Str();
    v > 0 ? dat[cur].rb = Str(h[L], 1) : dat[cur].lb = Str(-h[L], 1);
    return;
  }
  int mid = (L + R) >> 1;
  if (pos <= mid)
    modify(L, mid, pos, v, dat[cur].ls);
  else
    modify(mid + 1, R, pos, v, dat[cur].rs);
  pushup(cur);
}
int stk[111], stop;
void dfs_get(int L, int R, int l, int r, int cur) {
  if (l <= L && R <= r) return stk[++stop] = cur, void();
  int mid = (L + R) >> 1;
  if (l <= mid) dfs_get(L, mid, l, r, dat[cur].ls);
  if (r > mid) dfs_get(mid + 1, R, l, r, dat[cur].rs);
}
Str seq[111];
Str query_jzp(int nw, int len) {
  if (!len) return Str();
  if (len == seq[nw].len) return seq[nw];
  if (len <= dat[stk[nw]].rb.len) return query_R(len, stk[nw]);
  return dat[stk[nw]].rb +
         (query_jzp(nw - 1, len - dat[stk[nw]].rb.len + dat[stk[nw]].lb.len) -
          dat[stk[nw]].lb);
}
inline bool Query(int l, int r) {
  stop = 0;
  dfs_get(1, n, l, r, root);
  for (int i = 1; i <= stop; ++i) {
    if (dat[stk[i]].isw) return false;
    if (dat[stk[i]].lb.len > seq[i - 1].len) return false;
    if (dat[stk[i]].lb == query_jzp(i - 1, dat[stk[i]].lb.len)) {
      seq[i] = dat[stk[i]].rb + (seq[i - 1] - dat[stk[i]].lb);
    } else
      return false;
  }
  return seq[stop].len == 0;
}
int main() {
  read(n);
  read(K);
  init();
  for (int i = 1; i <= n; ++i) read(h[i]);
  build(1, n, root);
  int q;
  read(q);
  while (q--) {
    int op;
    read(op);
    if (op == 1) {
      int p, v;
      read(p), read(v);
      modify(1, n, p, v, root);
    } else {
      int l, r;
      read(l), read(r);
      puts(Query(l, r) ? "Yes" : "No");
    }
  }
  return 0;
}
