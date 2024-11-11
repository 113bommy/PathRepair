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
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  if (flag) x = -x;
}
using namespace std;
const double eps = 3e-16;
const double inf = 1e17;
int n, m;
inline void Read(double &x) {
  int a;
  read(a);
  x = a / 1000.0;
}
inline double F(double x) { return x < 0 ? -x : x; }
double X, Y;
struct Seg {
  double k, b;
  inline void Read_Seg() {
    Read(k), Read(b);
    b = k * X + b - Y;
  }
} S[106789];
double h[106789], lsh[106789], memo[106789];
int ltot, htot;
inline pair<double, double> get_inter(double r, Seg s) {
  double k = s.k, b = s.b;
  double a = k * k + 1, c = b * b - r * r;
  b = 2.0 * k * b;
  double delta = b * b - 4.0 * a * c;
  if (delta < -eps)
    return make_pair(inf, inf);
  else if (delta < eps)
    delta = eps;
  double x = (-b + sqrt(delta)) / (2.0 * a);
  double xx = (-b - sqrt(delta)) / (2.0 * a);
  double y = k * x + s.b;
  double yy = k * xx + s.b;
  double t1 = atan2(y, x), t2 = atan2(yy, xx);
  return make_pair(t1, t2);
}
struct Segments {
  int l, r, id;
  bool operator<(const Segments a) const {
    return r < a.r || (r == a.r && l < a.l);
  }
} Sts[106789];
bool cmp(const Segments &a, const Segments &b) {
  return a.l < b.l || (a.l == b.l && a.r < b.r);
}
bool vis[106789];
int tre[106789];
inline void add(int cur, int x) {
  for (int i = cur; i <= ltot; i += ((i) & (-i))) tre[i] += x;
}
inline int query(int cur) {
  int res = 0;
  for (int i = cur; i; i -= ((i) & (-i))) res += tre[i];
  return res;
}
inline bool che(double r) {
  memset(vis, 0, sizeof(vis));
  memset(tre, 0, sizeof(tre));
  ltot = 0;
  htot = 0;
  for (int i = 1; i <= n; ++i) {
    pair<double, double> inters = get_inter(r, S[i]);
    if (inters.first > 1e16) {
      vis[i] = true;
      continue;
    }
    memo[i] = h[++htot] = inters.first;
    memo[i + n] = h[++htot] = inters.second;
  }
  sort(h + 1, h + 1 + htot);
  h[htot + 1] = -464234.23634423;
  for (int i = 1; i <= htot; ++i) {
    if (F(h[i] - h[i + 1]) > eps) lsh[++ltot] = h[i];
  }
  htot = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      Sts[++htot].l =
          lower_bound(lsh + 1, lsh + 1 + ltot, memo[i] - 2.0 * eps) - lsh;
      Sts[htot].r =
          lower_bound(lsh + 1, lsh + 1 + ltot, memo[i + n] + 2.0 * eps) - lsh -
          1;
      if (Sts[htot].l > Sts[htot].r) swap(Sts[htot].l, Sts[htot].r);
      Sts[htot].id = i;
    }
  sort(Sts + 1, Sts + 1 + htot, cmp);
  int cnt = 0;
  for (int i = 1; i <= htot; ++i) {
    cnt += query(Sts[i].r) - query(Sts[i].l - 1);
    if (cnt >= m) return true;
    add(Sts[i].r, 1);
  }
  return false;
}
inline pair<double, double> get_inter_(double r, Seg s) {
  double k = s.k, b = s.b;
  double a = k * k + 1, c = b * b - r * r;
  b = 2.0 * k * b;
  double delta = b * b - 4.0 * a * c;
  if (delta < eps) return make_pair(inf, inf);
  double x = (-b + sqrt(delta)) / (2.0 * a);
  double xx = (-b - sqrt(delta)) / (2.0 * a);
  double y = k * x + s.b;
  double yy = k * xx + s.b;
  double t1 = atan2(y, x), t2 = atan2(yy, xx);
  return make_pair(t1, t2);
}
inline pair<double, double> line_inter(int i, int j) {
  double k = S[i].k, b = S[i].b;
  double k_ = S[j].k, b_ = S[j].b;
  double x = (b_ - b) / (k - k_);
  double y = k * x + b;
  return make_pair(x, y);
}
inline double get_len(pair<double, double> pr) {
  return sqrt(pr.first * pr.first + pr.second * pr.second);
}
multiset<Segments> st;
inline void calc(double r) {
  memset(vis, 0, sizeof(vis));
  ltot = 0;
  htot = 0;
  for (int i = 1; i <= n; ++i) {
    pair<double, double> inters = get_inter_(r, S[i]);
    if (inters.first > 1e16) {
      vis[i] = true;
      continue;
    }
    memo[i] = h[++htot] = inters.first;
    memo[i + n] = h[++htot] = inters.second;
  }
  double ans = 0;
  sort(h + 1, h + 1 + htot);
  h[htot + 1] = -464234.23634423;
  for (int i = 1; i <= htot; ++i) {
    if (F(h[i] - h[i + 1]) > eps) lsh[++ltot] = h[i];
  }
  htot = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      Sts[++htot].l =
          lower_bound(lsh + 1, lsh + 1 + ltot, memo[i] - 5.0 * eps) - lsh;
      Sts[htot].r =
          lower_bound(lsh + 1, lsh + 1 + ltot, memo[i + n] + 5.0 * eps) - lsh -
          1;
      if (Sts[htot].l > Sts[htot].r) swap(Sts[htot].l, Sts[htot].r);
      Sts[htot].id = i;
    }
  sort(Sts + 1, Sts + 1 + htot, cmp);
  int ct = 0;
  for (int i = 1; i <= htot; ++i) {
    int nw = Sts[i].id;
    for (multiset<Segments>::iterator it =
             st.lower_bound((Segments){ltot + 1, Sts[i].l, 0});
         it != st.end() && (*it).r < Sts[i].r; ++it) {
      int to = (*it).id;
      ans += get_len(line_inter(nw, to));
      ++ct;
    }
    st.insert(Sts[i]);
  }
  ans += (m - ct) * r;
  printf("%.9lf\n", ans);
}
inline void work() {
  double R = 0, l = 0, r = 1e13;
  int ct = 0;
  while (++ct <= 100) {
    double mid = (l + r) / 2.0;
    if (che(mid))
      R = r = mid;
    else
      l = mid;
  }
  calc(R);
}
int main() {
  read(n);
  Read(X), Read(Y);
  read(m);
  for (int i = 1; i <= n; ++i) S[i].Read_Seg();
  work();
  return 0;
}
