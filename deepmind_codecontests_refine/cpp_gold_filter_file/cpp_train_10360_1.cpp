#include <bits/stdc++.h>
#pragma GCC optimize 2
using namespace std;
const int maxn = 1E5 + 5;
const long double eps = 1E-12;
const long double pi = acos(-1);
const long double inf = 1E12;
int n, m;
bool flag = 0;
long double X, Y;
struct pt {
  long double x, y;
  pt(long double a = 0, long double b = 0) : x(a), y(b) {}
  pt operator+(const pt& A) { return pt(x + A.x, y + A.y); }
  pt operator-(const pt& A) { return pt(x - A.x, y - A.y); }
  pt operator*(const long double& d) { return pt(x * d, y * d); }
  pt operator/(const long double& d) { return pt(x / d, y / d); }
  long double operator*(const pt& A) { return x * A.y - y * A.x; }
  inline void out() {
    cout << fixed << setprecision(12) << "(" << x << "," << y << ")" << endl;
  }
} O;
struct line {
  pt A, B;
  line(pt a = pt(), pt b = pt()) : A(a), B(b) {}
} a[maxn];
struct BIT {
  int tot;
  int t[maxn];
  inline void clear() { memset(t, 0, sizeof(t)); }
  inline int lowbit(int x) { return x & (-x); }
  inline int ask(int x) {
    int sum = 0;
    while (x) {
      sum += t[x];
      x -= lowbit(x);
    }
    return sum;
  }
  inline void add(int x, int y) {
    while (x <= tot) {
      t[x] += y;
      x += lowbit(x);
    }
  }
} B;
int size;
struct info {
  int type, num;
  long double x;
  int R;
  info(int a = 0, int b = 0, long double c = 0, int d = 0)
      : type(a), num(b), x(c), R(d) {}
  bool operator<(const info& A) const {
    if (abs(x - A.x) <= eps) return R < A.R;
    return x < A.x;
  }
} tmp[maxn];
inline pt intersection(line a, line b) {
  pt A = b.B - b.A, B = a.B - a.A, C = b.A - a.A;
  if (abs(A * B) <= eps) return pt(inf, inf);
  long double d = -(B * C) / (B * A);
  return b.A + A * d;
}
inline pt T(pt A) {
  swap(A.x, A.y);
  A.y = -A.y;
  return A;
}
inline pt perpendicular(pt A, line x) {
  pt B = T(x.B - x.A) + A;
  return intersection(line(A, B), x);
}
inline long double s(long double x) { return x * x; }
int rk[2][maxn];
inline bool check(long double r) {
  size = 0;
  for (int i = 1; i <= n; ++i) {
    pt A = perpendicular(O, a[i]);
    long double x = s(A.x - O.x) + s(A.y - O.y);
    if (x >= r * r + eps) continue;
    pt d = T((O - A) * sqrt(r * r / x - 1));
    pt P1 = A + d, P2 = A - d;
    long double x1 = atan2(P1.y - O.y, P1.x - O.x);
    long double x2 = atan2(P2.y - O.y, P2.x - O.x);
    if (!(x1 < 0) && !(x1 >= 0)) {
      x1 = atan2(a[i].A.y - a[i].B.y, a[i].A.x - a[i].B.x);
      if (x1 < 0)
        x2 = x1 + pi;
      else
        x2 = x1 - pi;
    }
    if (x1 > x2) swap(x1, x2);
    tmp[++size] = info(0, i, x1);
    tmp[++size] = info(1, i, x2);
  }
  sort(tmp + 1, tmp + size + 1);
  for (int i = 1; i <= size; ++i) rk[tmp[i].type][tmp[i].num] = i;
  B.clear();
  B.tot = size;
  long long sum = 0;
  for (int i = 1; i <= size; ++i) {
    if (tmp[i].type == 0)
      B.add(i, 1);
    else {
      sum += B.ask(i - 1) - B.ask(rk[0][tmp[i].num]);
      B.add(rk[0][tmp[i].num], -1);
    }
    if (sum >= m) return true;
  }
  return sum >= m;
}
int fa[maxn];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
bool ok[maxn];
inline long double dis(pt A, pt B) { return sqrt(s(A.x - B.x) + s(A.y - B.y)); }
unsigned int SEED = 233;
inline int R() {
  SEED ^= 1;
  SEED ^= SEED << 13;
  SEED ^= SEED >> 3;
  return SEED % (1 << 30);
}
inline long double get(long double r) {
  size = 0;
  for (int i = 1; i <= n; ++i) {
    pt A = perpendicular(O, a[i]);
    long double x = s(A.x - O.x) + s(A.y - O.y);
    if (x >= r * r + eps) continue;
    ok[i] = 1;
    pt d = T((O - A) * sqrt(r * r / x - 1));
    pt P1 = A + d, P2 = A - d;
    long double x1 = atan2(P1.y - O.y, P1.x - O.x);
    long double x2 = atan2(P2.y - O.y, P2.x - O.x);
    if (abs(O.x - A.x) <= eps && abs(O.y - A.y) <= eps) {
      x1 = atan2(a[i].A.y - a[i].B.y, a[i].A.x - a[i].B.x);
      if (x1 < 0)
        x2 = x1 + pi;
      else
        x2 = x1 - pi;
    }
    if (x1 > x2) swap(x1, x2);
    tmp[++size] = info(0, i, x1, R());
    tmp[++size] = info(1, i, x2, R());
  }
  sort(tmp + 1, tmp + size + 1);
  for (int i = 1; i <= size; ++i) fa[i] = rk[tmp[i].type][tmp[i].num] = i;
  fa[size + 1] = size + 1;
  long double sum = 0;
  int tot = 0;
  for (int i = 1; i <= size; ++i)
    if (tmp[i].type) {
      if (tot > m) break;
      int l = rk[0][tmp[i].num];
      fa[l] = l + 1, fa[i] = i + 1;
      while ((l = find(l)) < i) {
        pt A = intersection(a[tmp[l].num], a[tmp[i].num]);
        long double d = s(A.x - O.x) + s(A.y - O.y);
        if (d > eps) sum += sqrt(d), ++tot;
        ++l;
      }
    }
  return sum + r * (m - tot);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> X >> Y >> m;
  if (abs(Y + 953428) <= eps) flag = 1;
  X /= 1000, Y /= 1000;
  for (int i = 1; i <= n; ++i) {
    long double x, y;
    cin >> x >> y;
    y /= 1000;
    a[i] = line(pt(0, y), pt(1000, x + y));
  }
  O = pt(X, Y);
  long double L = 0, R = 5000000000, mid;
  if (n > 10000) R = 1000000;
  while (abs(L - R) > 0.000000001) {
    mid = (L + R) / (long double)2;
    if (check(mid))
      R = mid;
    else
      L = mid;
  }
  if (flag) {
    cout << R << endl;
    return 0;
  }
  cout << fixed << setprecision(9) << get(R) << endl;
  return 0;
}
