#include <bits/stdc++.h>
using namespace std;
const long long inf = 1ll << 40;
const int N = 100005;
int n, S[N], matl[N], matr[N];
int id[N], rk[N], pos[N], rt[N];
long long k, a[N], b[N], val[N];
long long diff, lim;
priority_queue<pair<long long, long long> > Q;
struct TREE_S {
  long long t[N];
  void init() { memset(t, 0, sizeof(t)); }
  void change(int x, long long v) {
    for (; x <= n + 1; x += x & (-x)) t[x] += v;
  }
  long long ask(int x) {
    long long s = 0;
    for (; x; x -= x & (-x)) s += t[x];
    return s;
  }
} T1, T2;
struct TREE_MN {
  long long t[N];
  void init() { memset(t, 1, sizeof(t)); }
  void change(int x, long long v) {
    for (; x <= n + 1; x += x & (-x)) t[x] = min(t[x], v);
  }
  long long ask(int x) {
    long long s = 1ll << 60;
    for (; x; x -= x & (-x)) s = min(s, t[x]);
    return s;
  }
} T3;
long long count(long long x) {
  long long sum = 0;
  T1.init();
  for (int i = (int)(0); i <= (int)(n); i++) {
    int p1 = lower_bound(b + 1, b + n + 2, a[i]) - b;
    int p2 = upper_bound(b + 1, b + n + 2, a[i] - x) - b - 1;
    sum += T1.ask(p2);
    T1.change(p1, 1);
  }
  return sum;
}
namespace SEG {
const int M = 4000005;
int ls[M], rs[M], nd;
void insert(int &nk, int k, int l, int r, int p) {
  nk = ++nd;
  ls[nk] = ls[k];
  rs[nk] = rs[k];
  if (l == r) return;
  int mid = (l + r) / 2;
  if (p <= mid)
    insert(ls[nk], ls[k], l, mid, p);
  else
    insert(rs[nk], rs[k], mid + 1, r, p);
}
int ask(int k, int l, int r, int p) {
  if (!k || p == -1) return -1;
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (p <= mid) {
    int tmp = ask(ls[k], l, mid, p);
    if (tmp != -1) return tmp;
  }
  return ask(rs[k], mid + 1, r, p);
}
}  // namespace SEG
void update_val(int x) {
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (pair<long long, long long>(a[id[mid]], id[mid]) >=
        pair<long long, long long>(val[x], pos[x]))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  ans = SEG::ask(rt[x], 0, n, ans);
  if (ans == -1)
    val[x] = inf;
  else
    val[x] = a[id[ans]], pos[x] = id[ans];
}
bool cmp(int x, int y) { return a[x] == a[y] ? x < y : a[x] < a[y]; }
void init_segment() {
  for (int i = (int)(1); i <= (int)(n + 1); i++) b[i + 1] = a[i];
  sort(b + 1, b + n + 2);
  lim = max(k - n, 0ll);
  long long l = -inf, r = inf, ans = inf + 1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (count(mid) <= lim)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  T3.init();
  T2.init();
  T1.init();
  for (int i = (int)(0); i <= (int)(n); i++) {
    int p1 = lower_bound(b + 1, b + n + 2, a[i]) - b;
    int p2 = upper_bound(b + 1, b + n + 2, a[i] - ans) - b - 1;
    int pos = min(1ll * i, T3.ask(p2));
    ++S[pos + 1];
    --S[i + 1];
    lim -= T2.ask(p2);
    diff += a[i] * T2.ask(p2) - T1.ask(p2);
    T3.change(p1, i);
    T2.change(p1, 1);
    T1.change(p1, a[i]);
  }
  static vector<int> vec[N];
  --ans;
  for (int i = (int)(0); i <= (int)(n); i++) {
    int p1 = lower_bound(b + 1, b + n + 2, a[i]) - b;
    int p2 = lower_bound(b + 1, b + n + 2, a[i] - ans) - b;
    val[i] = a[i] - ans;
    if (b[p2] == a[i] - ans && vec[p2].size()) {
      int v = min((long long)vec[p2].size(), lim);
      pos[i] = (v == vec[p2].size() ? vec[p2].back() + 1 : vec[p2][v]);
      lim -= v;
      diff += 1ll * v * ans;
      if (v) ++S[vec[p2][0] + 1], --S[i + 1];
    } else
      pos[i] = 0;
    vec[p1].push_back(i);
  }
  for (int i = (int)(1); i <= (int)(n); i++) S[i] += S[i - 1];
  for (int i = (int)(0); i <= (int)(n); i++) id[i] = i;
  sort(id, id + n + 1, cmp);
  for (int i = (int)(0); i <= (int)(n); i++) rk[id[i]] = i;
  for (int i = (int)(1); i <= (int)(n); i++)
    SEG::insert(rt[i], rt[i - 1], 0, n, rk[i - 1]);
  for (int i = (int)(1); i <= (int)(n); i++) {
    update_val(i);
    Q.push(pair<long long, long long>(a[i] - val[i], i));
  }
  for (int i = (int)(1); i <= (int)(min(1ll * n, k)); i++) {
    int x = Q.top().second;
    Q.pop();
    assert(val[x] != -inf);
    matl[i] = ++pos[x];
    matr[i] = x;
    update_val(x);
    Q.push(pair<long long, long long>(a[x] - val[x], x));
  }
}
namespace SEG2 {
const int M = 4000005;
int ls[M], rs[M], nd;
long long s1[M], s2[M];
void insert(int &k, long long l, long long r, long long p, long long v) {
  if (!k) k = ++nd;
  s1[k] += p * v;
  s2[k] += v;
  if (l == r) return;
  long long mid = (l + r) / 2;
  if (p <= mid)
    insert(ls[k], l, mid, p, v);
  else
    insert(rs[k], mid + 1, r, p, v);
}
long long ask(int k, long long l, long long r, int rk) {
  if (rk > s2[k]) return s1[k];
  if (!k) return s1[k];
  if (l == r) return rk * l;
  long long mid = (l + r) / 2;
  if (s2[rs[k]] > rk) return ask(rs[k], mid + 1, r, rk);
  return s1[rs[k]] + ask(ls[k], l, mid, rk - s2[rs[k]]);
}
}  // namespace SEG2
struct node {
  long long sl, sr, s, mn;
  node operator+(const node &a) const {
    node b;
    b.s = s + a.s;
    b.mn = min(min(mn, a.mn), sr + a.sl);
    b.sl = min(sl, s + a.sl);
    b.sr = min(a.sr, a.s + sr);
    return b;
  }
} t1[N], t2[N];
set<int> SS;
int L[N], R[N], rtt, rem;
void merge(int x, int y) {
  int l = L[x], r = R[y];
  ++rem;
  SEG2::insert(rtt, 0, 3 * inf, max(-t1[l].mn, -t2[l].mn), -1);
  SEG2::insert(rtt, 0, 3 * inf, max(-t1[y].mn, -t2[y].mn), -1);
  t1[l] = t1[l] + t1[y];
  t2[l] = t2[l] + t2[y];
  R[l] = r;
  L[r] = l;
  SEG2::insert(rtt, 0, 3 * inf, max(-t1[l].mn, -t2[l].mn), 1);
}
void insert(int id) {
  long long val = (id == 0 || id == n + 1 ? -inf : a[id] - a[id - 1]);
  L[id] = R[id] = id;
  t1[id] = (node){val, val, val, val};
  t2[id] = (node){-val, -val, -val, -val};
  SEG2::insert(rtt, 0, 3 * inf, max(-val, val), 1);
  if (id == 0 || id == n + 1) return;
  rem -= 2;
  if (R[id - 1] != -1) merge(id - 1, id);
  if (L[id + 1] != -1) merge(id, id + 1);
}
long long ask(int x) {
  if (R[0] == n + 1) return (x == 0 ? 0 : -10 * inf);
  if (x > rem + SEG2::s2[rtt] - 1) return -10 * inf;
  return a[n] + SEG2::ask(rtt, 0, 3 * inf, x + 1) - 2 * inf;
}
void solve() {
  rem = n - 1;
  for (int i = (int)(0); i <= (int)(n + 1); i++) L[i] = R[i] = -1;
  insert(0);
  insert(n + 1);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (S[i])
      insert(i);
    else
      SS.insert(i);
  long long maxv = -(1ll << 60), sum = 0;
  for (int i = (int)(0); i <= (int)(min(1ll * n, k)); i++) {
    if (i) {
      set<int>::iterator it;
      it = SS.lower_bound(matl[i]);
      for (; it != SS.end() && *it <= matr[i]; SS.erase(it++)) insert(*it);
      sum += a[matr[i]] - a[matl[i] - 1];
    }
    maxv = max(maxv, ask(min(1ll * n, k) - i) + sum);
  }
  printf("%lld\n", diff + maxv);
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%lld", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++) a[i] += a[i - 1];
  init_segment();
  solve();
}
