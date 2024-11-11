#include <bits/stdc++.h>
using namespace std;
const int Imx = 2147483647;
const long long Lbig = 2e18;
const int mod = 1e9 + 7;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c == ' ' || c == '\n') c = _buff.get();
  return c;
}
struct point {
  int x, y;
  point(int X = 0, int Y = 0) {
    x = X;
    y = Y;
  }
  point operator+(const point &t) { return point(x + t.x, y + t.y); }
  point operator-(const point &t) { return point(x - t.x, y - t.y); }
  point operator-() { return point(-x, -y); }
  int det(const point &t) { return x * t.y - y * t.x; }
  int dot(const point &t) { return x * t.x + y * t.y; }
};
point P[22];
int pn;
void addpoint(point p) {
  if (pn == 0)
    P[pn++] = p, P[pn++] = -p;
  else {
    if ((P[1] - P[0]).det(-p) >= 0) p = -p;
    P[pn] = P[0];
    point Q[3] = {p, -p, p};
    int it0 = 0, it1 = 0;
    point nP[22];
    int nn = 0;
    for (int i = 0; i < pn + 2; i++) {
      nP[nn++] = P[it0] + Q[it1];
      if (it1 == 2 ||
          it0 < pn && (P[it0 + 1] - P[it0]).det(Q[it1 + 1] - Q[it1]) >= 0)
        it0++;
      else
        it1++;
    }
    swap(P, nP);
    swap(pn, nn);
  }
}
struct data {
  long long x, y, v;
  int id;
  void in(int i) {
    x = getnum(), y = getnum(), v = getnum();
    id = i;
  }
} a0[100111], b0[100111], a[100111], b[100111];
int k, n, m;
long long ans[100111];
pair<long long, int> pp[200111];
long long tab[100111];
long long vv[100111], vvn;
int findv(long long x) { return lower_bound(vv, vv + vvn, x) - vv + 1; }
void tabadd(int x, long long v) {
  for (int i = x; i <= 100005; i += i & (-i)) tab[i] += v;
}
long long tabsum(int x) {
  long long ret = 0;
  for (int i = x; i > 0; i -= i & (-i)) ret += tab[i];
  return ret;
}
void solve_query(long long coef) {
  vvn = 0;
  for (int i = 1; i <= n; i++) pp[i] = make_pair(a[i].y, i), vv[vvn++] = a[i].x;
  for (int i = 1; i <= m; i++) pp[n + i] = make_pair(b[i].v, n + i);
  sort(vv, vv + vvn);
  sort(pp + 1, pp + n + m + 1);
  memset(tab, 0, sizeof(tab));
  for (int i = 1; i <= n + m;) {
    int r = i;
    while (pp[i].first == pp[r].first) r++;
    for (int j = i; j < r; j++) {
      int id = pp[j].second;
      if (id <= n) {
        int pos = findv(a[id].x);
        tabadd(pos, a[id].v);
      }
    }
    for (int j = i; j < r; j++) {
      int id = pp[j].second;
      if (id > n) {
        id -= n;
        int pl = findv(b[id].x), pr = findv(b[id].y + 1) - 1;
        long long tmp = tabsum(pr) - tabsum(pl - 1);
        ans[b[id].id] += tmp * coef;
      }
    }
    i = r;
  }
}
void solve(long long p, long long q, long long xl, bool fl, long long xr,
           bool fr, long long B, long long coef) {
  for (int i = 1; i <= n; i++) {
    a[i].v = a0[i].v;
    a[i].x = a0[i].x;
    a[i].y = -a0[i].x * p + a0[i].y * q;
  }
  fl ^= 1;
  fr ^= 1;
  for (int i = 1; i <= m; i++) {
    b[i].x = b0[i].x + xl * b0[i].v + fl;
    b[i].y = b0[i].x + xr * b0[i].v - fr;
    b[i].id = i;
    b[i].v = -(b0[i].x + xl * b0[i].v) * p + (b0[i].y + B * b0[i].v) * q -
             (coef == -1);
  }
  solve_query(coef);
}
int main() {
  k = getnum(), n = getnum(), m = getnum();
  for (int i = 1; i <= k; i++) {
    point p;
    p.x = getnum(), p.y = getnum();
    addpoint(p);
  }
  P[pn] = P[0];
  int mn = P[0].x, mx = P[0].x;
  for (int i = 0; i < pn; i++) mn = min(mn, P[i].x), mx = max(mx, P[i].x);
  for (int i = 1; i <= n; i++) a0[i].in(i);
  for (int i = 1; i <= m; i++) b0[i].in(i);
  for (int i = 0; i < pn; i++) {
    if (P[i].x == P[i + 1].x) continue;
    long long xl, xr, p, q, B, coef;
    if (P[i + 1].x > P[i].x) {
      xl = P[i].x;
      xr = P[i + 1].x;
      q = xr - xl;
      p = P[i + 1].y - P[i].y;
      coef = -1;
      B = P[i].y;
    } else {
      xl = P[i + 1].x;
      xr = P[i].x;
      q = xr - xl;
      p = P[i].y - P[i + 1].y;
      coef = 1;
      B = P[i + 1].y;
    }
    solve(p, q, xl, 1, xr, xr == mx, B, coef);
  }
  for (int i = 1; i <= m; i++) putnum(ans[i]), putchar('\n');
  puts("");
  return 0;
}
