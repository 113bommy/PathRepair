#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool Up(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool Down(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
inline int getus() {
  int tmp, c;
  while (tmp = fgetc(stdin), tmp < '0' || tmp > '9')
    ;
  tmp -= '0';
  while (c = fgetc(stdin), '0' <= c && c <= '9') tmp = tmp * 10 + c - '0';
  return tmp;
}
inline int getint() {
  int tmp, c, flag;
  while (flag = fgetc(stdin), flag != '-' && (flag < '0' || flag > '9'))
    ;
  if (flag == '-')
    tmp = 0;
  else
    tmp = flag - '0';
  while (c = fgetc(stdin), '0' <= c && c <= '9') tmp = tmp * 10 + c - '0';
  return flag == '-' ? -tmp : tmp;
}
int N, K, a[100022], da[100022], r[100022], cnt[100022];
int ans[100022], q1[100022], q2[100022];
int p[100022], p2[100022];
inline bool CmpQ(int a, int b) {
  return max(r[q1[a]], r[q2[a]]) < max(r[q1[b]], r[q2[b]]);
}
inline bool CmpR(int a, int b) { return r[a] < r[b]; }
struct Segtree {
  int tmax[100022];
  int pos, val, cl, cr;
  Segtree() { memset(tmax, -63, sizeof(tmax)); }
  int Max(int t, int nl, int nr) {
    if (nr < cl || cr < nl) return INT_MIN;
    if (cl <= nl && nr <= cr) return tmax[t];
    int m = (nl + nr) >> 1;
    return max(Max(((t) << 1), nl, m), Max((((t) << 1) + 1), m + 1, nr));
  }
  void Change(int t, int l, int r) {
    if (!(l <= pos && pos <= r)) return;
    if (l == r) {
      Up(tmax[t], val);
      return;
    }
    int m = (l + r) >> 1;
    Change(((t) << 1), l, m);
    Change((((t) << 1) + 1), m + 1, r);
    tmax[t] = max(tmax[((t) << 1)], tmax[(((t) << 1) + 1)]);
  }
  int Max(int l, int r) {
    cl = l;
    cr = r;
    return Max(1, 1, N);
  }
  void Change(int p, int v) {
    pos = p;
    val = v;
    Change(1, 1, N);
  }
} seg;
struct BIT {
  int C[100022];
  BIT() { memset(C, 0, sizeof(C)); }
  void Clear() { memset(C, 0, sizeof(C)); }
  void Add(int i, int d) {
    for (; i <= N; i += ((i) & (-(i)))) C[i] += d;
  }
  int Sum(int i) {
    int res = 0;
    for (; i; i -= ((i) & (-(i)))) res += C[i];
    return res;
  }
  int Sum(int l, int r) {
    assert(l <= r);
    return Sum(r) - Sum(l - 1);
  }
} bit;
namespace Discrete {
int n, v[100022];
void Init() {
  sort(v + 1, v + N + 1);
  n = unique(v + 1, v + N + 1) - v - 1;
  v[0] = INT_MIN;
  v[n + 1] = INT_MAX;
}
int ask_e(int key) {
  int *t = lower_bound(v + 1, v + n + 1, key);
  assert(*t == key);
  return t - v;
}
int ask_ge(int key) {
  int *t = lower_bound(v + 1, v + n + 1, key);
  assert(*t == key || (*(t - 1) < key && key < *t));
  return t - v;
}
int ask_le(int key) {
  int *t = lower_bound(v + 1, v + n + 1, key);
  if (*t != key) --t;
  assert(*t == key || (*t < key && key < *(t + 1)));
  return t - v;
}
void getInter(int &a, int &b) {
  a = ask_ge(a);
  b = ask_le(b);
}
}  // namespace Discrete
void Work() {
  int Q = getus();
  for (int i = (1); i <= (Q); ++i) {
    q1[i] = getus();
    q2[i] = getus();
    p2[i] = i;
  }
  sort(p2 + 1, p2 + Q + 1, CmpQ);
  int ptr = N + 1;
  for (int i = (Q); i >= (1); --i) {
    int x = q1[p2[i]], y = q2[p2[i]];
    int rmin = max(r[x], r[y]);
    while (r[p[ptr - 1]] >= rmin) {
      --ptr;
      seg.Change(da[p[ptr]], cnt[p[ptr]]);
    }
    int l = max(a[x] - K, a[y] - K);
    int r = min(a[x] + K, a[y] + K);
    Discrete::getInter(l, r);
    ans[p2[i]] = seg.Max(l, r);
  }
  for (int i = (1); i <= (Q); ++i)
    if (ans[i] >= 0)
      printf("%d\n", ans[i]);
    else
      puts("-1");
}
void Init() {
  N = getus();
  K = getus();
  for (int i = (1); i <= (N); ++i) r[p[i] = i] = getus();
  for (int i = (1); i <= (N); ++i) a[i] = Discrete::v[i] = getus();
  Discrete::Init();
  sort(p + 1, p + N + 1, CmpR);
  for (int x = (1); x <= (N); ++x) {
    int i = p[x], age = da[i] = Discrete::ask_e(a[i]);
    int l = a[i] - K, r = a[i] + K;
    Discrete::getInter(l, r);
    assert(l <= r);
    bit.Add(age, 1);
    cnt[i] = bit.Sum(l, r);
  }
}
int main() {
  Init();
  Work();
  return 0;
}
