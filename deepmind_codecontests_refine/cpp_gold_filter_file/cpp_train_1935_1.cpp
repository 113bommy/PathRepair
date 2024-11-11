#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1);
double sq(double x) { return x * x; }
long long sq(long long x) { return x * x; }
int sign(long long x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
int sign(int x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
double sign(double x) { return abs(x) < EPS ? 0 : x < 0 ? -1 : 1; }
pair<int, int> operator+(const pair<int, int> &l, const pair<int, int> &r) {
  return pair<int, int>(l.first + r.first, l.second + r.second);
}
pair<int, int> operator-(const pair<int, int> &l, const pair<int, int> &r) {
  return pair<int, int>(l.first - r.first, l.second - r.second);
}
long long operator^(const pair<int, int> &l, const pair<int, int> &r) {
  return (long long)l.first * r.second - (long long)l.second * r.first;
}
long long operator/(const pair<int, int> &l, const pair<int, int> &r) {
  return (long long)l.first * r.second - (long long)l.second * r.first;
}
long long operator*(const pair<int, int> &l, const pair<int, int> &r) {
  return (long long)l.first * r.first + (long long)l.second * r.second;
}
pair<int, int> operator*(const pair<int, int> &l, const int &r) {
  return pair<int, int>(l.first * r, l.second * r);
}
pair<int, int> operator-(const pair<int, int> &l) {
  return pair<int, int>(-l.first, -l.second);
}
pair<double, double> operator+(const pair<double, double> &l,
                               const pair<double, double> &r) {
  return pair<double, double>(l.first + r.first, l.second + r.second);
}
pair<double, double> operator-(const pair<double, double> &l,
                               const pair<double, double> &r) {
  return pair<double, double>(l.first - r.first, l.second - r.second);
}
double operator^(const pair<double, double> &l, const pair<double, double> &r) {
  return l.first * r.second - l.second * r.first;
}
double operator/(const pair<double, double> &l, const pair<double, double> &r) {
  return l.first * r.second - l.second * r.first;
}
double operator*(const pair<double, double> &l, const pair<double, double> &r) {
  return l.first * r.first + l.second * r.second;
}
pair<double, double> operator*(const pair<double, double> &l, const double &r) {
  return pair<double, double>(l.first * r, l.second * r);
}
pair<double, double> operator-(const pair<double, double> &l) {
  return pair<double, double>(-l.first, -l.second);
}
double size(pair<double, double> x) { return hypot(x.first, x.second); }
double size2(pair<double, double> x) { return sq(x.first) + sq(x.second); }
long long size2(pair<int, int> x) {
  return sq((long long)x.first) + sq((long long)x.second);
}
double polar(pair<double, double> x) { return atan2(x.second, x.first); }
pair<double, double> unit(double a) {
  return pair<double, double>(cos(a), sin(a));
}
pair<double, double> norm(pair<double, double> a) {
  return a * (1.0 / size(a));
}
pair<double, double> rotate(pair<double, double> v, double a) {
  return unit(a) * v.first + unit(a + PI / 2) * v.second;
}
pair<double, double> r90(pair<double, double> v) {
  return pair<double, double>(-v.second, v.first);
}
void normalize(double &a) {
  while (a < 0) a += 2 * PI;
  while (a >= 2 * PI) a -= 2 * PI;
}
struct circle {
  circle(pair<double, double> O, double r) : O(O), r(r) {}
  circle() {}
  pair<double, double> O;
  double r;
};
int tangent(circle &A, circle &B, pair<double, double> des[4]) {
  int top = 0;
  double d = size(A.O - B.O), a = polar(B.O - A.O), b = PI + a;
  double t = sq(d) - sq(A.r - B.r);
  if (t >= 0) {
    t = sqrt(t);
    double p = atan2(B.r - A.r, t);
    des[top++] = pair<double, double>(a + p + PI / 2, b + p - PI / 2);
    des[top++] = pair<double, double>(a - p - PI / 2, b - p + PI / 2);
  }
  t = sq(d) - sq(A.r + B.r);
  if (t >= 0) {
    t = sqrt(t);
    double p = atan2(B.r + A.r, t);
    des[top++] = pair<double, double>(a + p - PI / 2, b + p - PI / 2);
    des[top++] = pair<double, double>(a - p + PI / 2, b - p + PI / 2);
  }
  return top;
}
int intersect(circle &A, circle &B, pair<double, double> des[2]) {
  double d = size(A.O - B.O), t = (sq(A.r) + sq(d) - sq(B.r)) / 2 / A.r / d,
         u = (sq(B.r) + sq(d) - sq(A.r)) / 2 / B.r / d;
  if (abs(d) < EPS) return 0;
  if (1 - t * t < 0 || 1 - u * u < 0) return 0;
  double a = atan2(sqrt(1 - t * t), t), b = atan2(sqrt(1 - u * u), u),
         p = polar(B.O - A.O), q = PI + p;
  des[0] = pair<double, double>(p + a, q - b);
  des[1] = pair<double, double>(p - a, q + b);
  return 2;
}
int intersect(circle A, pair<double, double> s, pair<double, double> d,
              pair<double, double> des[2]) {
  double c = size2(A.O - s) - sq(A.r), b = d * (s - A.O), a = size2(d);
  if (b * b - a * c < 0) return 0;
  des[0].second = (-b - sqrt(b * b - a * c)) / a;
  des[1].second = (-b + sqrt(b * b - a * c)) / a;
  des[0].first = polar(s + d * des[0].second - A.O);
  des[1].first = polar(s + d * des[1].second - A.O);
  return 2;
}
int intersect(pair<double, double> a, pair<double, double> b,
              pair<double, double> u, pair<double, double> v,
              pair<double, double> &des) {
  if (abs(b ^ v) < EPS) return 0;
  des = pair<double, double>(((a - u) ^ v) / (v ^ b), ((a - u) ^ b) / (v ^ b));
  return 1;
}
double dist(const pair<double, double> &A, const pair<double, double> &p,
            const pair<double, double> &d) {
  if (size(A - p) <= EPS)
    return 0;
  else if (size(d) <= EPS)
    return size(A - p);
  double sina = ((A - p) ^ d) / size(A - p) / size(d);
  double cosa = ((A - p) * d) / size(A - p) / size(d);
  double r = abs(size(A - p) * sina), e = size(A - p) * cosa;
  if (0 < e && e < size(d))
    ;
  else
    r = min(size(A - p), size(A - p - d));
  return r;
}
int get_circle(pair<double, double> a, pair<double, double> b, double R,
               circle des[2]) {
  pair<double, double> m = (a + b) * 0.5, t = (b - a);
  double d = (R * R - size2(m - a));
  if (d < 0) return 0;
  d = sqrt(d);
  pair<double, double> p = norm(pair<double, double>(t.second, -t.first));
  des[0] = circle(m + p * d, R);
  des[1] = circle(m - p * d, R);
  return 2;
}
int get_circle(pair<double, double> p0, pair<double, double> p1,
               pair<double, double> p2, circle &des) {
  pair<double, double> a = (p0 + p1) * 0.5, b = r90(p0 - p1);
  pair<double, double> u = (p0 + p2) * 0.5, v = r90(p0 - p2), R;
  if (!intersect(a, b, u, v, R)) return 0;
  des = circle(a + b * R.first, size(a + b * R.first - p0));
  return 1;
}
struct v3 {
  double x, y, z;
  v3() {}
  v3(double x, double y, double z) : x(x), y(y), z(z) {}
  v3 operator-() const { return v3(-x, -y, -z); }
  v3 operator-(const v3 &l) const { return v3(x - l.x, y - l.y, z - l.z); }
  v3 operator+(const v3 &l) const { return v3(x + l.x, y + l.y, z + l.z); }
  v3 operator*(const double c) const { return v3(x * c, y * c, z * c); }
  double operator*(const v3 &l) const { return x * l.x + y * l.y + z * l.z; }
  v3 operator^(const v3 &l) const {
    return v3(y * l.z - z * l.y, z * l.x - x * l.z, x * l.y - y * l.x);
  }
  double size() { return sqrt(sq(x) + sq(y) + sq(z)); }
  double size2() { return sq(x) + sq(y) + sq(z); }
  v3 norm() {
    double p = size();
    return v3(x / p, y / p, z / p);
  }
  void print() { printf("%lf %lf %lf\n", x, y, z); }
  bool operator<(const v3 &l) const {
    if (abs(x - l.x) >= EPS) return x < l.x;
    if (abs(y - l.y) >= EPS) return y < l.y;
    if (abs(z - l.z) >= EPS) return z < l.z;
    return false;
  }
  bool operator==(const v3 &l) const {
    return abs(x - l.x) < EPS && abs(y - l.y) < EPS && abs(z - l.z) < EPS;
  }
};
struct Quad {
  double a;
  v3 v;
  Quad(double a, v3 v) : a(a), v(v) {}
  Quad operator*(const double &c) const { return Quad(a * c, v * c); }
  Quad operator~() const { return Quad(-a, -v); }
  Quad operator-() const {
    return Quad(a, -v) * (1 / (sq(a) + sq(v.x) + sq(v.y) + sq(v.z)));
  }
  Quad operator*(const Quad &l) const {
    return Quad(a * l.a - v * l.v, l.v * a + v * l.a + (v ^ l.v));
  }
  v3 apply(v3 p) { return ((*this) * Quad(0, p) * -(*this)).v; }
};
double size(v3 a) { return a.size(); }
double size2(v3 a) { return a.size2(); }
v3 norm(v3 a) { return a.norm(); }
v3 unit(double a, double b) {
  return v3(cos(a) * cos(b), sin(a) * cos(b), sin(b));
}
Quad set_rotate(v3 axis, double a) {
  return Quad(cos(a / 2), axis.norm() * sin(a / 2));
}
struct sphere {
  sphere(v3 O, double r) : O(O), r(r) {}
  v3 O;
  double r;
};
int intersect(sphere A, v3 s, v3 d, double des[2]) {
  double c = (A.O - s).size2() - sq(A.r), b = d * (s - A.O), a = d.size2();
  if (b * b - a * c < 0) return 0;
  des[0] = (-b + sqrt(b * b - a * c)) / a;
  des[1] = (-b - sqrt(b * b - a * c)) / a;
  return 2;
}
int intersect(v3 u, v3 v, v3 p, v3 q, v3 &s, v3 &d) {
  if (abs(v * q - 1) < EPS) return 0;
  d = v ^ q;
  double t = v * q;
  s = v * ((u * v - p * q * t) / (1 - t * t)) +
      q * ((u * v * t - p * q) * 1.0 / (t * t - 1));
  return 1;
}
int intersect(v3 u, v3 v, v3 p, v3 q, v3 &s) {
  if (abs(q * v) <= EPS) return 0;
  s = p + q * (((p - u) * v) / (q * v));
  printf("%.10lf\n", (u - s) * v);
  return 1;
}
bool isintersect(pair<double, double> &a, pair<double, double> &b,
                 pair<double, double> &u, pair<double, double> &v) {
  if ((((u - a) ^ (b - a)) < 0) ^ (((v - a) ^ (b - a)) < 0))
    ;
  else
    return false;
  if ((((a - u) ^ (v - u)) < 0) ^ (((b - u) ^ (v - u)) < 0))
    return true;
  else
    return false;
}
double area(circle C, double s, double e) {
  double p = C.O.first, q = C.O.second, r = C.r;
  return (p * r * (sin(e) - sin(s)) + q * r * (cos(s) - cos(e)) +
          r * r * (e - s)) *
         0.5;
}
template <typename T>
void convex_hull(vector<T> &L, vector<T> &R) {
  int mn = 0;
  for (int i = 1; i < L.size(); i++) {
    if (L[mn] < L[i]) mn = i;
  }
  swap(L[mn], L[0]);
  T t = L[0];
  for (int i = 1; i < L.size(); i++) L[i] = L[i] - L[0];
  L[0] = T(0, 0);
  sort(L.begin() + 1, L.end(), [](T l, T r) {
    if (sign(l ^ r) != 0) return sign(l ^ r) < 0;
    return size(l) < size(r);
  });
  for (T c : L) {
    while (R.size() >= 2 &&
           sign((R[R.size() - 2] - R.back()) ^ (c - R.back())) <= 0)
      R.pop_back();
    R.push_back(c);
  }
  for (T &c : R) c = c + t;
}
double area(pair<double, double> A[4], pair<double, double> B[4]) {
  vector<pair<double, double>> L;
  for (int i = 0; i < 3; i++) L.push_back(A[i]);
  for (int i = 0; i < 3; i++) L.push_back(B[i]);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      pair<double, double> R;
      if (!intersect(A[i], A[i + 1] - A[i], B[j], B[j + 1] - B[j], R)) continue;
      if (R.first < -EPS || R.first > 1 + EPS || R.second < -EPS ||
          R.second > 1 + EPS)
        continue;
      L.push_back(A[i] + (A[i + 1] - A[i]) * R.first);
    }
  }
  vector<pair<double, double>> tmp;
  swap(tmp, L);
  for (pair<double, double> c : tmp) {
    bool ch = 1;
    for (int i = 0; ch && i < 3; i++) {
      if (((A[i + 1] - A[i]) ^ (c - A[i])) > EPS) ch = 0;
    }
    for (int i = 0; ch && i < 3; i++) {
      if (((B[i + 1] - B[i]) ^ (c - B[i])) > EPS) ch = 0;
    }
    if (ch) L.push_back(c);
  }
  if (L.size() == 0) return 0;
  sort(L.begin(), L.end());
  L.resize(unique(L.begin(), L.end()) - L.begin());
  vector<pair<double, double>> R;
  convex_hull(L, R);
  double ans = 0;
  R.push_back(R[0]);
  for (int i = 0; i + 1 < R.size(); i++) ans += R[i + 1] ^ R[i];
  return ans;
}
circle make_circle(vector<pair<double, double>> Q) {
  if (Q.size() == 0) return circle(pair<double, double>(0, 0), 0);
  if (Q.size() == 1) return circle(Q[0], 0);
  circle res;
  for (int i = 0; i < Q.size(); i++) {
    swap(Q.back(), Q[i]);
    res = circle((Q[0] + Q[1]) * 0.5, size(Q[0] - Q[1]) / 2);
    bool ch = 1;
    for (pair<double, double> c : Q)
      if (size2(c - res.O) > sq(res.r) + EPS) ch = 0;
    if (ch) return res;
    swap(Q.back(), Q[i]);
  }
  get_circle(Q[0], Q[1], Q[2], res);
  return res;
}
circle smallest_circle(vector<pair<double, double>> &P,
                       vector<pair<double, double>> &Q, int N) {
  circle c = make_circle(Q);
  if (N == 0 || Q.size() >= 3) return c;
  for (int i = 0; i < N; i++) {
    if (size2(c.O - P[i]) > sq(c.r)) {
      Q.push_back(P[i]);
      c = smallest_circle(P, Q, i);
      Q.pop_back();
    }
  }
  return c;
}
void convex_hull(vector<v3> &L, vector<v3> &R, vector<v3> &O, vector<v3> &D,
                 vector<v3> &X) {
  int N = L.size();
  static bool chk[1005][1005];
  static bool in[1005];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) chk[i][j] = 0, in[i] = 0;
  int q1 = 0, q2 = 1;
  queue<pair<int, int>> Q;
  vector<pair<pair<int, int>, int>> F;
  for (int i = 1; i < N; i++)
    if (L[i].z < L[q1].z) q1 = i, q2 = 0;
  for (int i = 0; i < N; i++) {
    if (i == q1) continue;
    if ((norm(L[i] - L[q1]) * v3(0, 0, 1)) <
        (norm(L[q2] - L[q1]) * v3(0, 0, 1)))
      q2 = i;
  }
  Q.push(pair<int, int>(q1, q2));
  chk[q1][q2] = 1;
  while (Q.size()) {
    pair<int, int> f = Q.front();
    Q.pop();
    int a = f.first, b = f.second, c = -1;
    in[a] = in[b] = 1;
    for (int i = 0; i < N; i++) {
      if (i == a || i == b) continue;
      if (c == -1 || ((L[i] - L[a]) ^ (L[c] - L[a])) * (L[b] - L[a]) < 0) c = i;
    }
    if (!chk[c][b]) Q.push(pair<int, int>(c, b)), chk[c][b] = 1;
    if (!chk[a][c]) Q.push(pair<int, int>(a, c)), chk[a][c] = 1;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    F.emplace_back(pair<int, int>(a, b), c);
  }
  sort(F.begin(), F.end());
  F.resize(unique(F.begin(), F.end()) - F.begin());
  for (auto f : F) {
    int a = f.first.first, b = f.first.second, c = f.second;
    O.push_back(L[a]);
    X.push_back(norm(L[a] - L[b]));
    D.push_back(norm((L[a] - L[b]) ^ (L[c] - L[b])));
  }
  for (int i = 0; i < N; i++)
    if (in[i]) R.push_back(L[i]);
}
int convex_tangent(vector<pair<int, int>> &C, pair<int, int> P, int up = 1) {
  auto sign = [&](long long c) { return c > 0 ? up : c == 0 ? 0 : -up; };
  auto local = [&](pair<int, int> P, pair<int, int> a, pair<int, int> b,
                   pair<int, int> c) {
    return sign((a - P) ^ (b - P)) <= 0 && sign((b - P) ^ (c - P)) >= 0;
  };
  assert(C.size() >= 2);
  int N = C.size() - 1, s = 0, e = N, m;
  if (local(P, C[1], C[0], C[N - 1])) return 0;
  while (s + 1 < e) {
    m = (s + e) / 2;
    if (local(P, C[m - 1], C[m], C[m + 1])) return m;
    if (sign((C[s] - P) ^ (C[s + 1] - P)) < 0) {
      if (sign((C[m] - P) ^ (C[m + 1] - P)) > 0)
        e = m;
      else if (sign((C[m] - P) ^ (C[s] - P)) > 0)
        s = m;
      else
        e = m;
    } else {
      if (sign((C[m] - P) ^ (C[m + 1] - P)) < 0)
        s = m;
      else if (sign((C[m] - P) ^ (C[s] - P)) < 0)
        s = m;
      else
        e = m;
    }
  }
  if (s && local(P, C[s - 1], C[s], C[s + 1])) return s;
  if (e != N && local(P, C[e - 1], C[e], C[e + 1])) return e;
  return -1;
}
int cmp_flag = 0, cmp_lo = 0;
struct Convex {
  struct line {
    line(pair<int, int> x) {
      if (!cmp_flag)
        s = x;
      else
        d = x;
    }
    line(pair<int, int> s, pair<int, int> d) : s(s), d(d) {}
    pair<int, int> s, d;
    bool operator<(const line &l) const {
      if (!cmp_flag) return s < l.s;
      return cmp_lo ? d / l.d > 0 : d / l.d < 0;
    }
  };
  int lo;
  set<line> C;
  void add(pair<int, int> p) {
    cmp_flag = 0;
    auto pos = [&](long long x) { return lo ? x >= 0 : x <= 0; };
    auto neg = [&](long long x) { return lo ? x <= 0 : x >= 0; };
    auto e = C.upper_bound(line(p)), d = e;
    if (e != C.end() && d != C.begin()) {
      d--;
      if (pos((e->s - d->s) / (p - d->s))) return;
    }
    if (lo && e == C.end() && C.size() && C.rbegin()->s.first == p.first)
      return;
    if (!lo && e == C.begin() && C.size() && e->s.first == p.first) return;
    while (1) {
      d = C.upper_bound(line(p)), e = d;
      if (d == C.end() || ++e == C.end()) break;
      if (neg((d->s - p) / (e->s - p)))
        C.erase(d);
      else
        break;
    }
    while (1) {
      d = C.upper_bound(line(p)), e = d;
      if (d == C.begin() || --e == C.begin()) break;
      d = e;
      --e;
      if (pos((d->s - p) / (e->s - p)))
        C.erase(d);
      else
        break;
    }
    if (lo && C.size() && C.rbegin()->s.first == p.first) C.erase(--C.end());
    if (!lo && C.size() && C.begin()->s.first == p.first) C.erase(C.begin());
    d = C.upper_bound(line(p));
    if (d != C.begin()) {
      e = prev(d);
      line t = line(e->s, p - e->s);
      C.erase(e);
      C.insert(t);
    }
    if (d == C.end())
      C.insert(line(p, pair<int, int>(0, lo ? 1 : -1)));
    else
      C.insert(line(p, d->s - p));
  }
  long long get_mn(pair<int, int> m) {
    cmp_flag = 1;
    cmp_lo = lo;
    auto d = C.lower_bound(m);
    return (long long)d->s.first * -m.second + (long long)d->s.second * m.first;
  }
};
namespace halfplane_intersection {
const int INF = 1e9;
struct line {
  line(pair<int, int> u, pair<int, int> v) : u(u), v(v) {}
  pair<int, int> u, v;
};
double C(line A, line B) {
  return B.v / A.v == 0 ? 1e18 : ((A.u - B.u) / B.v) / (double)(B.v / A.v);
}
bool V(line A, line B, double cur) {
  double l = (cur - A.u.first) / A.v.first * A.v.second + A.u.second;
  double r = (cur - B.u.first) / B.v.first * B.v.second + B.u.second;
  return l >= r;
}
pair<double, double> W(line A, line B) {
  return (pair<double, double>)A.v * C(A, B) + (pair<double, double>)A.u;
}
void chain(vector<line> &X, int l, int r, int up) {
  vector<line> R;
  sort(X.begin(), X.end(), [&](line l, line r) { return l.v / r.v * up < 0; });
  R.emplace_back(pair<int, int>(l, 0), pair<int, int>(0, up));
  X.emplace_back(pair<int, int>(r, 0), pair<int, int>(0, -up));
  for (line c : X) {
    while (R.size() >= 2 &&
           C(R[R.size() - 2], R.back()) >= C(R[R.size() - 2], c))
      R.pop_back();
    R.push_back(c);
  }
  swap(R, X);
  X.pop_back();
  X.erase(X.begin());
}
int reduce_left(vector<line> &X, vector<line> &Y, double &cur) {
  auto rv = [](vector<line> &t) { reverse(t.begin(), t.end()); };
  rv(X), rv(Y);
  while (X.size() && Y.size()) {
    if (V(X.back(), Y.back(), cur + EPS)) break;
    if (X.back().v / Y.back().v >= 0) return 0;
    cur = W(X.back(), Y.back()).first;
    while (X.size() >= 2 && !V(X[X.size() - 2], X.back(), cur)) X.pop_back();
    while (Y.size() >= 2 && V(Y[Y.size() - 2], Y.back(), cur)) Y.pop_back();
  }
  rv(X);
  rv(Y);
  return 1;
}
int reduce_right(vector<line> &X, vector<line> &Y, double &cur) {
  while (X.size() && Y.size()) {
    if (V(X.back(), Y.back(), cur - EPS)) break;
    if (X.back().v / Y.back().v <= 0) return 0;
    cur = W(X.back(), Y.back()).first;
    while (X.size() >= 2 && !V(X[X.size() - 2], X.back(), cur)) X.pop_back();
    while (Y.size() >= 2 && V(Y[Y.size() - 2], Y.back(), cur)) Y.pop_back();
  }
  return 1;
}
int run(vector<pair<int, int>> &U, vector<pair<int, int>> &V,
        vector<pair<double, double>> &R, int l = -INF, int r = INF,
        int u = -INF, int d = INF) {
  U.emplace_back(0, u);
  V.emplace_back(1, 0);
  U.emplace_back(0, d);
  V.emplace_back(-1, 0);
  vector<line> X, Y;
  int N = V.size();
  for (int i = 0; i < N; i++) {
    if (V[i].first == 0) {
      if (V[i].second > 0)
        r = min(r, U[i].first);
      else
        l = max(l, U[i].first);
    } else if (V[i].first < 0)
      X.emplace_back(U[i], -V[i]);
    else
      Y.emplace_back(U[i], V[i]);
  }
  chain(X, l, r, 1);
  chain(Y, l, r, -1);
  double left = l, right = r;
  if (!reduce_right(X, Y, right)) return 0;
  reduce_left(X, Y, left);
  reverse(X.begin(), X.end());
  vector<line> L;
  if (left == l) L.emplace_back(pair<int, int>(l, 0), pair<int, int>(0, 1));
  for (line c : Y) L.push_back(c);
  if (right == r) L.emplace_back(pair<int, int>(r, 0), pair<int, int>(0, -1));
  for (line c : X) L.push_back(c);
  for (int i = 0; i + 1 < L.size(); i++) R.push_back(W(L[i], L[i + 1]));
  R.push_back(W(L.back(), L[0]));
  R.resize(unique(R.begin(), R.end()) - R.begin());
  return 1;
}
};  // namespace halfplane_intersection
namespace halfplane_intersection2 {
bool cw(pair<double, double> y, pair<double, double> z) { return y / z <= 0; };
bool ccw(pair<double, double> y, pair<double, double> z) { return y / z >= 0; };
void chain(vector<pair<double, double>> &X,
           bool (*f)(pair<double, double>, pair<double, double>), int l,
           int r) {
  vector<pair<double, double>> t;
  sort(X.begin(), X.end());
  for (pair<double, double> c : X) {
    while (t.size() >= 2 && f(t.back() - t[t.size() - 2], c - t[t.size() - 2]))
      t.pop_back();
    t.push_back(c);
  }
  for (int m : {-l, -r}) {
    while (t.size() >= 2 &&
           f(t.back() - t[t.size() - 2], pair<double, double>(1, m)))
      t.pop_back();
    reverse(t.begin(), t.end());
  }
  swap(t, X);
}
pair<double, double> ltop(pair<double, double> u, pair<double, double> v,
                          int rv = -1) {
  return pair<double, double>(v.second / v.first * rv,
                              u.second - u.first * (v.second / v.first));
}
bool tangent(vector<pair<double, double>> &X, vector<pair<double, double>> &Y,
             int l, int r, pair<int, int> R[2]) {
  int ch = 0;
  vector<pair<double, double>> P, Q;
  P.emplace_back(1, -r);
  Q.emplace_back(1, -l);
  for (int i = 0; i + 1 < X.size(); i++) P.push_back(X[i + 1] - X[i]);
  for (int i = 0; i + 1 < Y.size(); i++) Q.push_back(Y[i + 1] - Y[i]);
  P.emplace_back(1, -l), Q.emplace_back(1, -r);
  if ((X[0] - Y.back()) / pair<double, double>(1, -r) <= EPS)
    R[0] = pair<int, int>(-1, Y.size()), ch |= 1;
  int x = 0, y = Y.size() - 1;
  while (x < X.size() && y >= 0) {
    pair<double, double> d = Y[y] - X[x];
    if (d / P[x] >= -EPS && d / P[x + 1] <= EPS && d / Q[y] <= EPS &&
        d / Q[y + 1] >= -EPS)
      R[1] = pair<int, int>(x, y), ch |= 2;
    if (ch != 3 && d / P[x] <= EPS && d / P[x + 1] >= -EPS &&
        d / Q[y] >= -EPS && d / Q[y + 1] <= EPS)
      R[0] = pair<int, int>(x, y), ch |= 1;
    if (ccw(P[x + 1], Q[y]))
      x++;
    else
      y--;
  }
  if ((X.back() - Y[0]) / (pair<double, double>(1, -l)) <= EPS)
    R[1] = pair<int, int>(X.size(), -1), ch |= 2;
  if (ch != 3) printf("%d\n", ch);
  return ch == 3;
}
const int INF = 1e9;
int run(vector<pair<int, int>> &U, vector<pair<int, int>> &V,
        vector<pair<double, double>> &R, int l = -INF, int r = INF,
        int u = -INF, int d = INF) {
  U.emplace_back(0, u);
  V.emplace_back(1, 0);
  U.emplace_back(0, d);
  V.emplace_back(-1, 0);
  vector<pair<double, double>> X, Y;
  int N = V.size();
  for (int i = 0; i < N; i++) {
    if (V[i].first == 0) {
      if (V[i].second > 0)
        r = min(r, U[i].first);
      else
        l = max(l, U[i].first);
      continue;
    }
    if (V[i].first < 0)
      X.push_back(ltop(U[i], V[i], 1));
    else
      Y.push_back(ltop(U[i], V[i], 1));
  }
  chain(X, cw, l, r);
  chain(Y, ccw, r, l);
  pair<int, int> t[2];
  if (!tangent(X, Y, l, r, t)) return 0;
  for (int i = t[0].first; i < t[1].first; i++) {
    if (i == -1)
      R.push_back(ltop(X[0], pair<double, double>(1, -r)));
    else if (i + 1 == X.size())
      R.push_back(ltop(X.back(), pair<double, double>(1, -l)));
    else
      R.push_back(ltop(X[i], X[i + 1] - X[i]));
  }
  if (t[1].second != -1)
    R.push_back(ltop(X[t[1].first], X[t[1].first] - Y[t[1].second]));
  for (int i = t[1].second; i < t[0].second; i++) {
    if (i == -1)
      R.push_back(ltop(Y[0], pair<double, double>(1, -l)));
    else if (i + 1 == Y.size())
      R.push_back(ltop(Y.back(), pair<double, double>(1, -r)));
    else
      R.push_back(ltop(Y[i], Y[i + 1] - Y[i]));
  }
  if (t[0].first != -1)
    R.push_back(ltop(Y[t[0].second], X[t[0].first] - Y[t[0].second]));
  return 2;
}
};  // namespace halfplane_intersection2
double area(pair<double, double> A, pair<double, double> B, double R) {
  auto helper = [](pair<double, double> A, pair<double, double> B, double R) {
    return R * R * atan2(A ^ B, A * B) / 2;
  };
  auto is_valid = [](double x) { return 0 <= x && x <= 1; };
  double ans = 0, rv = 1;
  pair<double, double> C, D, res[2];
  if (size2(A) > size2(B)) swap(A, B), rv = -1;
  if (size2(B) <= R * R)
    ans = (A ^ B) / 2;
  else if (size2(A) <= R * R) {
    if (!intersect(circle(pair<double, double>(0, 0), R), A, B - A, res))
      ans = (A ^ B) / 2;
    else
      C = A +
          (B - A) * (is_valid(res[1].second) ? res[1].second : res[0].second),
      ans = (A ^ C) / 2 + helper(C, B, R);
  } else {
    if (!intersect(circle(pair<double, double>(0, 0), R), A, B - A, res) ||
        res[0].second < 0 && res[1].second < 0 ||
        res[0].second > 1 && res[1].second > 1)
      ans = helper(A, B, R);
    else
      C = A + (B - A) * res[0].second, D = A + (B - A) * res[1].second,
      ans = helper(A, C, R) + (C ^ D) / 2 + helper(D, B, R);
  }
  return ans * rv;
}
const int MX = 400005;
pair<int, int> D[MX];
int sign(pair<int, int> x) { return x < pair<int, int>(0, 0) ? 1 : 0; }
auto cmp = [](pair<int, int> x, pair<int, int> y) {
  return sign(x) != sign(y) ? sign(x) < sign(y) : x / y < 0;
};
const int L = 1000000;
double solve(pair<int, int> *D, int N, pair<int, int> O) {
  sort(D + 1, D + N + 1, cmp);
  for (int i = 1; i <= N; i++) D[N + i] = D[i];
  vector<pair<int, int>> U, V;
  for (int i = 1; i <= N; i++) {
    if (D[i] / D[i + 1] < 0)
      U.push_back(D[i + 1]), V.push_back(D[i] - D[i + 1]);
    else if (D[i] / D[i + 1] == 0)
      return 0;
    else
      U.push_back(D[i]), V.push_back(D[i + 1] - D[i]);
  }
  for (int l = 1, r = 1; l <= N; l++) {
    while (r <= l || r < N + l && D[r] / D[l] > 0) r++;
    if (r != N + l && D[r] / D[l] == 0) return 0;
    if (r - 1 != l) {
      U.push_back(D[r - 1]), V.push_back(D[l] - D[r - 1]);
    }
  }
  vector<pair<double, double>> R;
  if (!halfplane_intersection::run(U, V, R, -L - O.first, L - O.first,
                                   -L - O.second, L - O.second))
    return 0;
  double ans = R.back() / R[0];
  for (int i = 0; i + 1 < R.size(); i++) ans += R[i] / R[i + 1];
  return ans / 2;
}
int main() {
  int TC;
  scanf("%d", &TC);
  for (int tt = 1; tt <= TC; tt++) {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d%d", &D[i].first, &D[i].second);
    for (int i = 2; i <= N; i++) D[i] = D[i] - D[1];
    double ans = solve(D + 1, N - 1, D[1]);
    printf("%.10lf\n", ans);
  }
}
