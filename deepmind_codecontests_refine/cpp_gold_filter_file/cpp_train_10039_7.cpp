#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, k, d, ansl = 1, ansr = 1;
int a[MAXN];
map<int, int> lst;
long long Read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
template <typename T>
void Put1(T x) {
  if (x > 9) Put1(x / 10);
  putchar(x % 10 ^ 48);
}
template <typename T>
void Put(T x, char c = -1) {
  if (x < 0) putchar('-'), x = -x;
  Put1(x);
  if (c >= 0) putchar(c);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T Abs(T x) {
  return x < 0 ? -x : x;
}
bool gotit;
int sl[MAXN], sr[MAXN], hl, hr, ret;
struct SegmentTree {
  struct node {
    int lz, w;
  } t[MAXN << 2];
  void calc(int x, int val) {
    t[x].w += val;
    t[x].lz += val;
  }
  void up(int x) { t[x].w = Min(t[(x << 1)].w, t[(x << 1 | 1)].w); }
  void down(int x) {
    if (!t[x].lz) return;
    calc((x << 1), t[x].lz);
    calc((x << 1 | 1), t[x].lz);
    t[x].lz = 0;
  }
  void Add(int x, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
      calc(x, val);
      return;
    }
    int mid = (l + r) >> 1;
    down(x);
    if (ql <= mid) Add((x << 1), l, mid, ql, qr, val);
    if (mid + 1 <= qr) Add((x << 1 | 1), mid + 1, r, ql, qr, val);
    up(x);
  }
  void Build(int x, int l, int r) {
    t[x].w = t[x].lz = 0;
    if (l == r) {
      t[x].w = l;
      return;
    }
    int mid = (l + r) >> 1;
    Build((x << 1), l, mid);
    Build((x << 1 | 1), mid + 1, r);
    up(x);
  }
  void Del(int x, int l, int r, int pos) {
    if (l == r) {
      t[x].w = 0;
      return;
    }
    down(x);
    int mid = (l + r) >> 1;
    if (pos <= mid)
      Del((x << 1), l, mid, pos);
    else
      Del((x << 1 | 1), mid + 1, r, pos);
    up(x);
  }
  void ef(int x, int l, int r, int val) {
    if (l == r) {
      if (t[x].w <= val) gotit = 1, ret = l;
      return;
    }
    down(x);
    int mid = (l + r) >> 1;
    if (t[(x << 1)].w <= val)
      ef((x << 1), l, mid, val);
    else
      ef((x << 1 | 1), mid + 1, r, val);
  }
  void Query(int x, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
      if (t[x].w <= val) ef(x, l, r, val);
      return;
    }
    down(x);
    int mid = (l + r) >> 1;
    if (!gotit && ql <= mid) Query((x << 1), l, mid, ql, qr, val);
    if (!gotit && mid + 1 <= qr) Query((x << 1 | 1), mid + 1, r, ql, qr, val);
  }
} st;
int main() {
  n = Read();
  k = Read();
  d = Read();
  for (int i = 1; i <= n; ++i) a[i] = Read() + 1e9 + 1;
  if (!d) {
    for (int L = 1; L <= n; ++L) {
      int R = L;
      while (R < n && a[R + 1] == a[L]) R++;
      if (R - L > ansr - ansl) ansl = L, ansr = R;
      L = R;
    }
    Put(ansl, ' '), Put(ansr);
    return 0;
  }
  st.Build(1, 1, n);
  for (int i = 1, L = 1; i <= n; ++i) {
    int ori = L;
    if (a[i] % d == a[i - 1] % d)
      L = Max(L, lst[a[i]] + 1);
    else
      L = i;
    lst[a[i]] = i;
    while (ori < L) st.Del(1, 1, n, ori++);
    while (hl && sl[hl] >= L && a[sl[hl]] >= a[i]) {
      st.Add(1, 1, n, Max(L, sl[hl - 1] + 1), sl[hl], a[sl[hl]] / d);
      hl--;
    }
    st.Add(1, 1, n, Max(L, sl[hl] + 1), i, -a[i] / d);
    sl[++hl] = i;
    while (hr && sr[hr] >= L && a[sr[hr]] <= a[i]) {
      st.Add(1, 1, n, Max(L, sr[hr - 1] + 1), sr[hr], -a[sr[hr]] / d);
      hr--;
    }
    st.Add(1, 1, n, Max(L, sr[hr] + 1), i, a[i] / d);
    sr[++hr] = i;
    gotit = 0;
    ret = 0;
    st.Query(1, 1, n, L, i, k + i);
    if (i - ret > ansr - ansl) ansl = ret, ansr = i;
  }
  Put(ansl, ' '), Put(ansr);
  return 0;
}
