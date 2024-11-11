#include <bits/stdc++.h>
using namespace std;
enum { WHITE = 0, GRAY, BLACK };
enum { UNVISITED = -1 };
struct pt2 {
  double x, y;
  pt2(double x = 0, double y = 0) : x(x), y(y) {}
  double dist(const pt2& o = pt2()) const { return hypot(x - o.x, y - o.y); }
  double length() const { return hypot(x, y); }
  pt2 rotate(double rad) {
    pt2 ans;
    double c = cos(rad), s = sin(rad);
    ans.x = x * c - y * s;
    ans.y = x * s + y * c;
    return ans;
  }
  void add(const pt2& o) {
    x += o.x;
    y += o.y;
  }
  pt2 operator*(double s) const {
    pt2 ans;
    ans.x = x * s;
    ans.y = y * s;
    return ans;
  }
  pt2 operator-(const pt2& o) const {
    pt2 ans;
    ans.x = x - o.x;
    ans.y = y - o.y;
    return ans;
  }
  pt2 operator-() const {
    pt2 ans;
    ans.x = -x;
    ans.y = -y;
    return ans;
  }
  bool operator==(const pt2& o) const {
    return (fabs((x) - (o.x)) < 1e-9) && (fabs((y) - (o.y)) < 1e-9);
  }
  bool operator<(const pt2& o) const {
    if (!(fabs((x) - (o.x)) < 1e-9)) return ((x) + 1e-9 < (o.x));
    return ((y) + 1e-9 < (o.y));
  }
  pt2 unit() const {
    auto len = dist(pt2());
    return pt2(x / len, y / len);
  }
};
pt2 operator*(double s, const pt2& v) { return v * s; }
ostream& operator<<(ostream& os, const pt2& P) {
  return os << "(" << P.x << ", " << P.y << ")";
}
double D(const pt2& P, const pt2& Q, const pt2& R) {
  double tmp =
      P.x * Q.y + P.y * R.x + Q.x * R.y - (R.x * Q.y + R.y * P.x + Q.x * P.y);
  return ((tmp) + 1e-9 < (0)) ? -1 : (((0) + 1e-9 < (tmp)) ? 1 : 0);
}
struct pt3 {
  double x, y, z;
  pt3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  double dist(const pt3& o = pt3()) const {
    return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y) +
                (z - o.z) * (z - o.z));
  }
};
struct line2 {
  double a, b, c;
  void fix() {
    auto k = !(fabs((a) - (0)) < 1e-9) ? a : b;
    a /= k;
    b /= k;
    c /= k;
  }
  line2(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) { fix(); }
  line2(const pt2& P, const pt2& Q) {
    a = P.y - Q.y;
    b = Q.x - P.x;
    c = P.x * Q.y - P.y * Q.x;
    fix();
  }
  double x(double y) const { return -(b * y + c) / a; }
  double y(double x) const { return -(a * x + c) / b; }
  bool operator==(const line2& o) const {
    return (fabs((a) - (o.a)) < 1e-9) && (fabs((b) - (o.b)) < 1e-9) &&
           (fabs((c) - (o.c)) < 1e-9);
  }
  bool parallel(const line2& o) const {
    return (fabs((a) - (o.a)) < 1e-9) && (fabs((b) - (o.b)) < 1e-9) &&
           !(fabs((c) - (o.c)) < 1e-9);
  }
  double dist(const pt2& p) const {
    return fabs(a * p.x + b * p.y + c) / hypot(a, b);
  }
  pt2 closest(const pt2& p) const {
    auto den = a * a + b * b;
    return pt2((b * (b * p.x - a * p.y) - a * c) / den,
               (a * (-b * p.x + a * p.y) - b * c) / den);
  }
};
pt2 intersection(const line2& r, const line2& s) {
  auto det = r.a * s.b - r.b * s.a;
  return pt2((-r.c * s.b + s.c * r.b) / det, (-s.c * r.a + r.c * s.a) / det);
}
struct lineseg2 {
  pt2 A, B;
  lineseg2(const pt2& A = pt2(), const pt2& B = pt2()) : A(A), B(B) {}
  bool contains(const pt2& P) const {
    if ((fabs((A.x) - (B.x)) < 1e-9))
      return (!((P.y) + 1e-9 < (min(A.y, B.y)))) &&
             (!((max(A.y, B.y)) + 1e-9 < (P.y)));
    return (!((P.x) + 1e-9 < (min(A.x, B.x)))) &&
           (!((max(A.x, B.x)) + 1e-9 < (P.x)));
  }
  pt2 closest(const pt2& P) const {
    line2 r(A, B);
    auto Q = r.closest(P);
    if (contains(Q)) return Q;
    return ((P.dist(A)) + 1e-9 < (P.dist(B))) ? A : B;
  }
  bool intersects(const lineseg2& o) const {
    auto d1 = D(A, B, o.A);
    auto d2 = D(A, B, o.B);
    if (((fabs((d1) - (0)) < 1e-9) && contains(o.A)) ||
        ((fabs((d2) - (0)) < 1e-9) && contains(o.B)))
      return true;
    auto d3 = D(o.A, o.B, A);
    auto d4 = D(o.A, o.B, B);
    if (((fabs((d3) - (0)) < 1e-9) && o.contains(A)) ||
        ((fabs((d4) - (0)) < 1e-9) && o.contains(B)))
      return true;
    return ((d1 * d2) + 1e-9 < (0)) && ((d3 * d4) + 1e-9 < (0));
  }
};
bool inside(const vector<lineseg2>& ls, const pt2& P) {
  for (auto& l : ls)
    if (((D(l.A, l.B, P)) + 1e-9 < (0))) return false;
  return true;
}
int pass = 1;
const double pi = acos(-1);
const double tau = 2.0 * pi;
const double deg2rad = pi / 180.0;
const complex<float> imunit = complex<float>(0, 1);
const double un = 1.0 / sqrt(2.0);
map<string, pt2> vec = {{"N", pt2(0, 1)},  {"NE", pt2(un, un)},
                        {"E", pt2(1, 0)},  {"SE", pt2(un, -un)},
                        {"S", pt2(0, -1)}, {"SW", pt2(-un, -un)},
                        {"W", pt2(-1, 0)}, {"NW", pt2(-un, un)}};
int N;
complex<float> x[2][(1 << 19)];
void precomp() {
  for (int i = 0, ENDD = N - 1; i <= ENDD; i++) {
    auto arg = imunit * complex<float>(i * tau / N);
    x[0][i] = exp(arg), x[1][i] = exp(-arg);
  }
}
void fft(int n, complex<float> a[], int inv = 0) {
  if (n == 1) return;
  static complex<float> aux[(1 << 19)];
  int n2 = n >> 1, fac = N / n;
  for (int k = 0, ENDD = n2 - 1; k <= ENDD; k++)
    aux[k] = a[k << 1], aux[n2 + k] = a[(k << 1) + 1];
  memcpy(a, aux, sizeof(complex<float>) * n);
  fft(n2, a, inv);
  fft(n2, a + n2, inv);
  for (int k = 0, ENDD = n2 - 1; k <= ENDD; k++) {
    aux[k] = a[k] + x[inv][k * fac] * a[n2 + k];
    aux[n2 + k] = a[k] + x[inv][(n2 + k) * fac] * a[n2 + k];
  }
  memcpy(a, aux, sizeof(complex<float>) * n);
}
void ifft(int n, complex<float> a[]) {
  fft(n, a, 1);
  for (int i = 0, ENDD = n - 1; i <= ENDD; i++) a[i] /= n;
}
int n, m, k;
string S, T;
int cnt[(1 << 19)] = {};
void solve(char c) {
  vector<complex<float> > Tp(N, 0);
  for (int i = 0, ENDD = m - 1; i <= ENDD; i++)
    Tp[m - 1 - i] = (T[i] == c ? 1 : 0);
  fft(N, &Tp[0]);
  vector<int> ev(n, 0);
  int sum = 0;
  for (int i = 0, ENDD = n - 1; i <= ENDD; i++)
    if (S[i] == c) {
      int l = i - k, r = i + k + 1;
      if (l < 0)
        sum++;
      else
        ev[l]++;
      if (r < n) ev[r]--;
    }
  vector<complex<float> > Sp(N, 0);
  for (int i = 0, ENDD = n - 1; i <= ENDD; i++) {
    sum += ev[i];
    if (sum) Sp[i] = 1;
  }
  fft(N, &Sp[0]);
  for (int i = 0, ENDD = N - 1; i <= ENDD; i++) Sp[i] *= Tp[i];
  ifft(N, &Sp[0]);
  for (int i = 1, ENDD = n; i <= ENDD; i++) cnt[i] += int(Sp[i].real() + 0.5);
}
int main() {
  cin >> n >> m >> k;
  cin >> S;
  cin >> T;
  N = 1;
  while (N < n + m) N <<= 1;
  precomp();
  solve('A');
  solve('T');
  solve('C');
  solve('G');
  int ans = 0;
  for (int i = 0, ENDD = n - 1; i <= ENDD; i++)
    if (cnt[i] == m) ans++;
  cout << ans << endl;
  return 0;
}
