#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 800050, MAX = 100000;
struct point {
  long double x, y;
  point(long double xx = 0, long double yy = 0) { x = xx, y = yy; }
};
struct line {
  point a, dir;
  line(point aa, point dd) { a = aa, dir = dd; }
};
int n;
point A[N];
point operator*(point A, long double x) { return point(A.x * x, A.y * x); }
point operator+(point A, point B) { return point(A.x + B.x, A.y + B.y); }
point operator-(point A, point B) { return point(A.x - B.x, A.y - B.y); }
long double cross(point A, point B) { return A.x * B.y - A.y * B.x; }
long double len(point A) { return sqrt(A.x * A.x + A.y * A.y); }
long double dis(line l, point a) {
  return 2 * cross(l.dir, a - l.a) / len(l.dir);
}
long double dis(point a, line l) {
  return 2 * cross(l.dir, a - l.a) / len(l.dir);
}
point intersec(line a, line b) {
  long double h1 = dis(a.a, b), h2 = dis(a.a + a.dir, b);
  return a.a + a.dir * (h1 / (h1 - h2));
}
bool operator<(point a, point b) {
  return fabs(a.x - b.x) <= 1e-5 ? a.y < b.y : a.x < b.x;
}
inline bool in(int x) { return 0 <= x && x <= MAX; }
inline void init() {
  int m, x, y, d, xx, yy;
  int dd;
  read(m);
  n = 0;
  while (m--) {
    read(x), read(y), read(d);
    if (in(x + d))
      A[++n] = point(x + d, y);
    else {
      dd = x + d - MAX;
      xx = x + d, yy = y;
      A[++n] = point(MAX, min(yy + dd, MAX));
      A[++n] = point(MAX, max(yy - dd, 0));
    }
    if (in(x - d))
      A[++n] = point(x - d, y);
    else {
      dd = 0 - (x - d);
      xx = x - d, yy = y;
      A[++n] = point(0, min(yy + dd, MAX));
      A[++n] = point(0, max(yy - dd, 0));
    }
    if (in(y + d))
      A[++n] = point(x, y + d);
    else {
      dd = y + d - MAX;
      xx = x, yy = y + d;
      A[++n] = point(min(xx + dd, MAX), MAX);
      A[++n] = point(max(xx - dd, 0), MAX);
    }
    if (in(y - d))
      A[++n] = point(x, y - d);
    else {
      dd = 0 - (y - d);
      xx = x, yy = y - d;
      A[++n] = point(min(xx + dd, MAX), 0);
      A[++n] = point(max(xx - dd, 0), 0);
    }
  }
}
point stk[N << 1];
int len1, len2;
point ansa, ansb, ansc;
long double R, r;
point O;
inline void upd(point a, point b, point c) {
  if (fabs(cross(a - b, a - c)) < 1e-5) return;
  O = intersec(line((a + b) * 0.5, point(-a.y + b.y, a.x - b.x)),
               line((c + b) * 0.5, point(-c.y + b.y, c.x - b.x)));
  r = len(a - O);
  if (r <= R) return;
  for (int i = 1; i <= len2; ++i)
    if (len(stk[i] - O) - r > 1e-5) return;
  R = r, ansa = a, ansb = b, ansc = c;
}
int main() {
  int i, j, k;
  init();
  sort(A + 1, A + n + 1);
  stk[len1 = 1] = A[1];
  for (i = 2; i <= n; ++i) {
    while (len1 > 1 &&
           cross(stk[len1] - stk[len1 - 1], A[i] - stk[len1 - 1]) <= 0)
      --len1;
    stk[++len1] = A[i];
  }
  len2 = len1;
  stk[++len2] = A[n - 1];
  for (i = n - 2; i; --i) {
    while (len2 > len1 &&
           cross(stk[len2] - stk[len2 - 1], A[i] - stk[len2 - 1]) <= 0)
      --len2;
    stk[++len2] = A[i];
  }
  for (i = 1; i <= len2 - 2; ++i) upd(stk[i], stk[i + 1], stk[i + 2]);
  cout << ((int)ansa.x) << ' ' << ((int)ansa.y) << '\n';
  cout << ((int)ansb.x) << ' ' << ((int)ansb.y) << '\n';
  cout << ((int)ansc.x) << ' ' << ((int)ansc.y) << '\n';
  return 0;
}
