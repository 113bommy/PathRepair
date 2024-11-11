#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int mo = 998244353;
const int jzm = 2333;
const int orG = 3, invG = 332748118;
const double Pi = acos(-1.0);
const double eps = 1e-9;
template <typename _T>
_T Fabs(_T x) {
  return x < 0 ? -x : x;
}
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
template <typename _T>
void print(_T x) {
  if (x < 0) {
    x = (~x) + 1;
    putchar('-');
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int add(int x, int y) { return x + y < mo ? x + y : x + y - mo; }
int qkpow(int a, int s) {
  int t = 1;
  while (s) {
    if (s & 1) t = 1ll * a * t % mo;
    a = 1ll * a * a % mo;
    s >>= 1;
  }
  return t;
}
double sqr(double x) { return x * x; }
int n, m, tot, cnt[200005], idx;
double summ, alen;
struct point {
  double x, y;
  point() { x = y = 0; }
  point(double X, double Y) {
    x = X;
    y = Y;
  }
  point operator+(const point &rhs) const {
    return point(x + rhs.x, y + rhs.y);
  }
} a[200005];
double dist(point x, point y) { return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y)); }
point walk(point p, double len, point agl) {
  return p + point(agl.x * len, agl.y * len);
}
struct line {
  point s, t, agl;
  double len, pre;
  line() { len = pre = 0; }
  line(point S, point T) {
    s = S;
    t = T;
    len = dist(s, t);
    agl = point((t.x - s.x) / len, (t.y - s.y) / len);
  }
} s[200005];
struct ming {
  double l, r, a, b, c;
  ming() { l = r = a = b = 0; }
  ming(double L, double R, double A, double B, double C) {
    l = L;
    r = R;
    a = A;
    b = B;
    c = C;
  }
  double delta() { return sqr(b) - 4.0 * a * c; }
  double leftRoot() { return (-b - sqrt(delta())) / (2.0 * a); }
  double rightRoot() { return (-b + sqrt(delta())) / (2.0 * a); }
} b[400005];
struct range {
  double wh;
  int col;
  bool typ;
  range() {
    wh = 0;
    col = 0;
    typ = 0;
  }
  range(double X, int Y, bool Z) {
    wh = X;
    col = Y;
    typ = Z;
  }
  bool friend operator<(const range &x, const range &y) {
    if (Fabs(x.wh - y.wh) < eps) return x.typ > y.typ;
    return x.wh < y.wh;
  }
} d[400005 << 2];
void insert(double L, double R) {
  if (L > R) return;
  int l = (int)floor(L / alen), r = (int)floor(R / alen);
  if (l > m) l -= m, L -= summ;
  if (r > m) r -= m, R -= summ;
  int las = idx;
  if (l == r) {
    d[++idx] = range(L - alen * l, l, 1);
    d[++idx] = range(R - alen * l, l, 0);
  } else {
    d[++idx] = range(L - alen * l, l, 1);
    d[++idx] = range(alen, l, 0);
    int id = l;
    while (id != r) {
      id++;
      if (id > m) id -= m;
      if (id == r) break;
      d[++idx] = range(0.0, id, 1);
      d[++idx] = range(alen, id, 0);
    }
    d[++idx] = range(0.0, r, 1);
    d[++idx] = range(R - alen * r, r, 0);
  }
}
bool check(double mid) {
  idx = 0;
  for (int i = 1; i <= tot; i++) {
    ming tmp = b[i];
    tmp.c -= sqr(mid);
    if (tmp.delta() < 0 || (Fabs(tmp.a) < eps && tmp.c > 0)) continue;
    insert(tmp.l + max(0.0, tmp.leftRoot()),
           min(tmp.r, tmp.l + tmp.rightRoot()));
  }
  sort(d + 1, d + idx + 1);
  int siz = 0;
  for (int i = 1; i <= m; i++) cnt[i] = 0;
  for (int i = 1; i <= idx; i++) {
    if (d[i].typ == 1)
      cnt[d[i].col]++;
    else
      cnt[d[i].col]--;
    if (d[i].typ == 1 && cnt[d[i].col] == 1) siz++;
    if (d[i].typ == 0 && cnt[d[i].col] == 0) siz--;
    if (siz == m) return 1;
  }
  return 0;
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) scanf("%lf %lf", &a[i].x, &a[i].y);
  for (int i = 1; i < n; i++) s[i] = line(a[i], a[i + 1]);
  s[n] = line(a[n], a[1]);
  for (int i = n + 1; i <= 2 * n; i++) s[i] = s[i - n];
  for (int i = 1; i <= n; i++) summ += s[i].len;
  alen = summ / (1.0 * m);
  for (int i = 1; i <= 2 * n; i++) s[i].pre = s[i - 1].pre + s[i].len;
  for (int i = n + 1, j = 1; i <= 2 * n; i++) {
    while (s[i - 1].pre - s[j].pre > alen) j++;
    while (s[i].pre - s[j - 1].pre > alen) {
      point st = s[j].s, ed = s[i].s;
      if (s[i - 1].pre - s[j - 1].pre > alen)
        st = walk(st, s[i - 1].pre - s[j - 1].pre - alen, s[j].agl);
      if (s[i - 1].pre - s[j - 1].pre < alen)
        ed = walk(ed, alen - s[i - 1].pre + s[j - 1].pre, s[i].agl);
      b[++tot].a = sqr(s[i].agl.x - s[j].agl.x) + sqr(s[i].agl.y - s[j].agl.y);
      b[tot].b = 2.0 * (st.x - ed.x) * (s[j].agl.x - s[i].agl.x) +
                 2.0 * (st.y - ed.y) * (s[j].agl.y - s[i].agl.y);
      b[tot].c = sqr(st.x - ed.x) + sqr(st.y - ed.y);
      b[tot].l = dist(s[i].s, ed) + s[i - 1].pre;
      b[tot].r = b[tot].l + min(dist(ed, s[i].t), dist(st, s[j].t));
      if (Fabs(b[tot].r - s[i].pre) < eps)
        break;
      else
        j++;
    }
  }
  double l = 0, r = alen;
  int times = 40;
  while (times--) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.7f\n", l);
  return 0;
}
