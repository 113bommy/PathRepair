#include <bits/stdc++.h>
long long mod;
long long k;
inline long long modadd(long long x, long long const &y) {
  return (x += y) >= mod ? x -= mod : x;
}
struct matrix {
 private:
  long long a[2][2];

 public:
  matrix(long long const &x = 0, long long const &y = 0, long long const &p = 0,
         long long const &z = 0) {
    a[0][0] = x, a[0][1] = y, a[1][0] = p, a[1][1] = z;
  }
  long long *operator[](long long const &x) { return a[x]; }
  const long long *operator[](long long const &x) const { return a[x]; }
  friend matrix operator*(matrix const &a, matrix const &b) {
    matrix res;
    res[0][0] =
        modadd(1ll * a[0][1] * b[1][0] % mod, 1ll * a[0][0] * b[0][0] % mod);
    res[0][1] =
        modadd(1ll * a[0][1] * b[1][1] % mod, 1ll * a[0][0] * b[0][1] % mod);
    res[1][0] =
        modadd(1ll * a[1][0] * b[0][0] % mod, 1ll * a[1][1] * b[1][0] % mod);
    res[1][1] =
        modadd(1ll * a[1][1] * b[1][1] % mod, 1ll * a[1][0] * b[0][1] % mod);
    return res;
  }
};
matrix pow(matrix x, long long y) {
  matrix res(1, 0, 0, 1);
  while (y) {
    if (y & 1) res = res * x;
    x = x * x;
    y >>= 1;
  }
  return res;
}
long long n, s[50010], cnt, m, t;
struct node {
  matrix v;
  long long ls, rs;
} tr[4000010];
void clone(long long &x) { tr[++cnt] = tr[x], x = cnt; }
void build(long long &x, long long const &l = 0, long long const &r = n - 1) {
  clone(x);
  if (l == r) return tr[x].v = matrix(0, s[l], 1, s[(l + 1) % n]), void();
  long long mid = (l + r) >> 1;
  build(tr[x].ls, l, mid), build(tr[x].rs, mid + 1, r);
  tr[x].v = tr[tr[x].ls].v * tr[tr[x].rs].v;
}
void update(long long const &p, long long const &y, long long const &v,
            long long &x, long long const &l = 0, long long const &r = n - 1) {
  clone(x);
  if (l == r) return tr[x].v[y][1] = v, void();
  long long mid = (l + r) >> 1;
  if (p <= mid)
    update(p, y, v, tr[x].ls, l, mid);
  else
    update(p, y, v, tr[x].rs, mid + 1, r);
  tr[x].v = tr[tr[x].ls].v * tr[tr[x].rs].v;
}
matrix query(long long const &x, long long const &pl = 0,
             long long const &pr = n - 1, long long const &l = 0,
             long long const &r = n - 1) {
  if (pl > pr) return matrix(1, 0, 0, 1);
  if (l == pl && r == pr) return tr[x].v;
  long long mid = (l + r) >> 1;
  if (pr <= mid)
    return query(tr[x].ls, pl, pr, l, mid);
  else if (pl > mid)
    return query(tr[x].rs, pl, pr, mid + 1, r);
  else
    return query(tr[x].ls, pl, mid, l, mid) *
           query(tr[x].rs, mid + 1, pr, mid + 1, r);
}
long long vx[50010], vy[50010], rt;
std::vector<std::tuple<long long, long long, long long>> v;
inline long long x(std::tuple<long long, long long, long long> &p) {
  return std::get<0>(p);
}
inline long long y(std::tuple<long long, long long, long long> &p) {
  return std::get<1>(p);
}
inline long long z(std::tuple<long long, long long, long long> &p) {
  return std::get<2>(p);
}
signed main() {
  scanf("%lld%lld", &k, &mod);
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) scanf("%lld", s + i);
  scanf("%lld", &m);
  for (long long i = 1; i <= m; i++) scanf("%lld%lld", vx + i, vy + i);
  v.emplace_back(-n, 0, 0), v.emplace_back(0x3f3f3f3f3f3f3f3fll, 0, 0);
  for (long long i = 1; i <= m; i++) {
    v.emplace_back(vx[i], 0, vy[i]);
    if (vx[i]) v.emplace_back(vx[i] - 1, 1, vy[i]);
  }
  std::sort(v.begin(), v.end());
  build(rt);
  t = cnt;
  matrix res(1, 0, 0, 1);
  long long las = 0;
  for (long long i = 1, tt = 1, pp = v.size(); i < pp; i = tt + 1) {
    tt = i;
    while (tt + 1 < pp && x(v[tt + 1]) / n == x(v[i]) / n) ++tt;
    if (x(v[i]) / n >= k / n) {
      las = x(v[i - 1]) / n;
      break;
    }
    res = res * pow(query(rt), x(v[i]) / n - 1 - x(v[i - 1]) / n);
    long long p = rt;
    cnt = t;
    for (long long j = i; j <= tt; j++)
      update(x(v[j]) % n, y(v[j]), z(v[j]), p);
    res = res * query(p);
  }
  res = res * pow(query(rt), k / n - 1 - las);
  cnt = t;
  for (long long i = 0, pp = v.size(); i < pp; i++)
    if (x(v[i]) / n == k / n) update(x(v[i]) % n, y(v[i]), z(v[i]), rt);
  res = res * query(rt, 0, k % n - 1);
  printf("%lld\n", res[1][0]);
  return 0;
}
