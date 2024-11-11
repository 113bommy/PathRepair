#include <bits/stdc++.h>
using namespace std;
const long long int INF = (long long int)1e9 + 10;
const long long int INFLL = (long long int)1e18 + 10;
const long double EPS = 1e-8;
const long double EPSLD = 1e-18;
const long long int MOD = 1e9 + 7;
template <class T>
T &chmin(T &a, const T &b) {
  return a = min(a, b);
}
template <class T>
T &chmax(T &a, const T &b) {
  return a = max(a, b);
}
const long double PI = atan(1) * 4.0;
struct L : public vector<complex<long double> > {
  L(const complex<long double> &a, const complex<long double> &b) {
    emplace_back(a);
    emplace_back(b);
  }
};
inline long double det(const complex<long double> &a,
                       const complex<long double> &b) {
  return imag(conj(a) * b);
}
inline long double dot(const complex<long double> &a,
                       const complex<long double> &b) {
  return real(conj(a) * b);
}
long double dtor(long double d) { return d * PI / 180.0; }
int ccw(complex<long double> a, complex<long double> b,
        complex<long double> c) {
  b -= a;
  c -= a;
  if (det(b, c) > EPSLD) return +1;
  if (det(b, c) < -EPSLD) return -1;
  if (dot(b, c) < -EPSLD) return +2;
  if (norm(b) < norm(c) - EPSLD) return -2;
  return 0;
}
bool intersectSP(const L &s, const complex<long double> &p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPSLD;
}
complex<long double> projection(const L &l, const complex<long double> &p) {
  long double t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
  return l[0] + t * (l[1] - l[0]);
}
long double distanceSP(const L &s, const complex<long double> &p) {
  const complex<long double> r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}
complex<long double> crosspoint(const L &l, const L &m) {
  long double a = det(l[1] - l[0], m[1] - m[0]);
  long double b = det(l[1] - l[0], l[1] - m[0]);
  if (abs(a) < EPSLD && abs(a) < EPSLD) return m[0];
  if (abs(a) < EPSLD) assert(false);
  return m[0] + b / a * (m[1] - m[0]);
}
complex<long double> rotate(complex<long double> p, long double t) {
  return p * exp(t * complex<long double>(0, 1));
}
vector<complex<long double> > rotate(vector<complex<long double> > pol,
                                     long double t) {
  for (auto &p : pol) p = rotate(p, t);
  return pol;
}
complex<long double> rotate(complex<long double> p, complex<long double> c,
                            long double t) {
  return rotate(p - c, t) + c;
}
vector<vector<complex<long double> > > convex_cut(
    const vector<complex<long double> > &pol, L l) {
  vector<vector<complex<long double> > > Q(2);
  for (long long int i = (0); i < (long long int)(pol.size()); i++) {
    complex<long double> a = pol[i], b = pol[(i + 1) % pol.size()];
    if (ccw(l[0], l[1], a) != -1) Q[0].emplace_back(a);
    if (ccw(l[0], l[1], a) != 1) Q[1].emplace_back(a);
    if (ccw(l[0], l[1], a) * ccw(l[0], l[1], b) < 0) {
      Q[0].emplace_back(crosspoint(L(a, b), l));
      Q[1].emplace_back(crosspoint(L(a, b), l));
    }
  }
  return Q;
}
long double area(const vector<complex<long double> > &pol) {
  long double a = 0;
  for (long long int i = (0); i < (long long int)(pol.size()); i++)
    a += det(pol[i], pol[(i + 1) % pol.size()]);
  return a / 2;
}
enum { OUT, ON, IN };
int contains(const vector<complex<long double> > pol,
             const complex<long double> p) {
  bool in = false;
  for (long long int i = (0);
       i < (long long int)(((long long int)(pol).size())); i++) {
    complex<long double> a = pol[i] - p, b = pol[(i + 1) % pol.size()] - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) < EPSLD && EPSLD < imag(b))
      if (det(a, b) < -EPSLD) in = !in;
    if (abs(det(a, b)) < EPSLD && dot(a, b) < EPSLD) return ON;
  }
  return in ? IN : OUT;
}
const long long int MAX_N = 100010;
long long int n, m;
long long int x[MAX_N], y[MAX_N];
vector<complex<long double> > p, q;
complex<long double> g = complex<long double>(0.0, 0.0);
long double ans;
int main() {
  scanf("%lld", &n);
  for (long long int i = (0); i < (long long int)(n); i++)
    scanf("%lld %lld", &x[i], &y[i]);
  for (long long int i = (0); i < (long long int)(n); i++)
    p.emplace_back(complex<long double>(x[i], y[i]));
  for (long long int i = (0); i < (long long int)(n); i++) g += p[i];
  g = g * (1.0 / (long double)n);
  for (long long int i = (0); i < (long long int)(n); i++)
    ans += norm(p[i] - g);
  scanf("%lld", &m);
  for (long long int i = (0); i < (long long int)(m); i++)
    scanf("%lld %lld", &x[i], &y[i]);
  for (long long int i = (0); i < (long long int)(m); i++)
    q.emplace_back(complex<long double>(x[i], y[i]));
  reverse((q).begin(), (q).end());
  if (contains(q, g) != IN) {
    long double res = INFLL;
    for (long long int i = (0); i < (long long int)(m); i++)
      chmin(res, distanceSP(L(q[i], q[(i + 1) % q.size()]), g));
    ans += n * res * res;
  }
  printf("%.18lf\n", (double)ans);
  return 0;
}
