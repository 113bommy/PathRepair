#include <bits/stdc++.h>
using namespace std;
const signed long long INF = 1000000100;
const long double EPS = 1e-15;
const long double Pi = 2 * atanl(1.0);
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &V) {
  os << "[";
  for (int(i) = (0); (i) < (int(V.size())); (i)++)
    os << V[i] << ((i == int(V.size()) - 1) ? "" : ",");
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &S) {
  os << "(";
  for (T i : S) os << i << (i == *S.rbegin() ? "" : ",");
  return os << ")";
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &M) {
  os << "{";
  for (pair<T, U> i : M) os << i << (i.X == M.rbegin()->X ? "" : ",");
  return os << "}";
}
inline bool is_zero(const long double &first) {
  return first >= -EPS and first <= EPS;
}
inline int sign(const long double &first) {
  if (first < -EPS)
    return -1;
  else if (first > EPS)
    return 1;
  else
    return 0;
}
inline pair<long double, long double> operator+(
    const pair<long double, long double> &a,
    const pair<long double, long double> &b) {
  return pair<long double, long double>(a.first + b.first, a.second + b.second);
}
inline pair<long double, long double> operator-(
    const pair<long double, long double> &a,
    const pair<long double, long double> &b) {
  return pair<long double, long double>(a.first - b.first, a.second - b.second);
}
inline pair<long double, long double> operator*(
    const pair<long double, long double> &a, long double t) {
  return pair<long double, long double>(a.first * t, a.second * t);
}
inline pair<long double, long double> operator/(
    const pair<long double, long double> &a, long double t) {
  return pair<long double, long double>(a.first / t, a.second / t);
}
inline bool operator==(const pair<long double, long double> &a,
                       const pair<long double, long double> &b) {
  return is_zero(a.first - b.first) and is_zero(a.second - b.second);
}
inline bool operator!=(const pair<long double, long double> &a,
                       const pair<long double, long double> &b) {
  return !is_zero(a.first - b.first) or !is_zero(a.second - b.second);
}
pair<long double, long double> FAIL = make_pair(1e30, 1e30);
inline long double cp(const pair<long double, long double> &a,
                      const pair<long double, long double> &b) {
  return a.first * b.second - a.second * b.first;
}
inline long double dp(const pair<long double, long double> &a,
                      const pair<long double, long double> &b) {
  return a.first * b.first + a.second * b.second;
}
inline long double pieprzu(const pair<long double, long double> &a,
                           const pair<long double, long double> &b) {
  return sqrtl((b.first - a.first) * (b.first - a.first) +
               (b.second - a.second) * (b.second - a.second));
}
inline long double distance_point_line(
    const pair<long double, long double> &p,
    const pair<pair<long double, long double>, pair<long double, long double> >
        &u) {
  return cp(p - u.first, p - u.second) / pieprzu(u.first, u.second);
}
inline bool on_right(const pair<long double, long double> &a,
                     const pair<long double, long double> &b,
                     const pair<long double, long double> &c) {
  return sign(cp(c - a, b - a)) == 1;
}
inline bool on_left(const pair<long double, long double> &a,
                    const pair<long double, long double> &b,
                    const pair<long double, long double> &c) {
  return sign(cp(c - a, b - a)) == -1;
}
inline double polygon_area(const vector<pair<long double, long double> > &A) {
  long double result = 0.0;
  if (int(A.size()) <= 2) return 0;
  for (int(i) = (2); (i) < (int(A.size())); (i)++)
    result += cp(A[i] - A[0], A[i - 1] - A[0]);
  return abs(result / 2);
}
inline pair<long double, long double> projection(
    const pair<long double, long double> &p,
    const pair<pair<long double, long double>, pair<long double, long double> >
        &u) {
  return u.first +
         ((u.second - u.first) * (dp(p - u.first, u.second - u.first) /
                                  dp(u.second - u.first, u.second - u.first)));
}
inline bool between(const pair<long double, long double> &a,
                    const pair<long double, long double> &b,
                    const pair<long double, long double> &c) {
  return sign(min(b.first, c.first) - a.first) <= 0 and
         sign(a.first - max(b.first, c.first)) <= 0 and
         sign(min(b.second, c.second) - a.second) <= 0 and
         sign(a.second - max(b.second, c.second)) <= 0;
}
inline bool on_segment(const pair<long double, long double> &p,
                       const pair<pair<long double, long double>,
                                  pair<long double, long double> > &u) {
  return between(p, u.first, u.second) and pieprzu(p, projection(p, u)) < EPS;
}
inline long double distance_point_segment(
    const pair<pair<long double, long double>, pair<long double, long double> >
        &u,
    const pair<long double, long double> &p) {
  if (on_segment(projection(p, u), u))
    return fabs(distance_point_line(p, u));
  else
    return min(pieprzu(u.first, p), pieprzu(u.second, p));
}
inline long double angle(const pair<long double, long double> &a,
                         const pair<long double, long double> &o,
                         const pair<long double, long double> &b) {
  long double result = atan2l(a.first - o.first, a.second - o.second) -
                       atan2l(b.first - o.first, b.second - o.second);
  if (sign(result) == -1) result += 2 * Pi;
  return result;
}
inline pair<long double, long double> point_reflection(
    const pair<long double, long double> &s,
    const pair<long double, long double> &p) {
  return p + (s - p) * 2;
}
inline pair<long double, long double> axial_reflection(
    const pair<long double, long double> &p,
    const pair<pair<long double, long double>, pair<long double, long double> >
        &u) {
  return point_reflection(p, projection(p, u));
}
inline int triangle_inequality(long double &p, long double q, long double r) {
  int a = sign(p + q - r);
  int b = sign(p + r - q);
  int c = sign(q + r - p);
  if (a == -1 or b == -1 or c == -1) return -1;
  if (a == 0 or b == 0 or c == 0) return 0;
  return 1;
}
vector<pair<long double, long double> > convex_hull(
    vector<pair<long double, long double> > A) {
  vector<pair<long double, long double> > R;
  sort(A.begin(), A.end());
  R.push_back(A[0]);
  R.push_back(A[1]);
  for (int(i) = (2); (i) < (int(A.size())); (i)++) {
    while (R.size() >= 2 and on_right(R[R.size() - 2], R[R.size() - 1], A[i]))
      R.pop_back();
    R.push_back(A[i]);
  }
  for (int(i) = (int(A.size()) - 2); (i) >= (0); (i)--) {
    while (R.size() >= 2 and on_right(R[R.size() - 2], R[R.size() - 1], A[i]))
      R.pop_back();
    R.push_back(A[i]);
  }
  R.pop_back();
  return move(R);
}
inline pair<long double, long double> rotate90_origin(
    const pair<long double, long double> &p) {
  return pair<long double, long double>(p.second, -p.first);
}
inline pair<long double, long double> rotate90(
    const pair<long double, long double> &p,
    const pair<long double, long double> &o) {
  return o + rotate90_origin(p - o);
}
inline pair<long double, long double> rotate_origin(
    const pair<long double, long double> &p, long double theta) {
  theta = -theta;
  long double s = sinl(theta);
  long double c = cosl(theta);
  return pair<long double, long double>(p.first * c - p.second * s,
                                        p.first * s + p.second * c);
}
inline pair<long double, long double> rotate(
    const pair<long double, long double> &p,
    const pair<long double, long double> &o, long double theta) {
  return o + rotate_origin(p - o, theta);
}
inline bool parallel(const pair<pair<long double, long double>,
                                pair<long double, long double> > &u,
                     const pair<pair<long double, long double>,
                                pair<long double, long double> > &v) {
  return is_zero(cp(u.second - u.first, v.second - v.first));
}
bool perpendicular(const pair<pair<long double, long double>,
                              pair<long double, long double> > &u,
                   const pair<pair<long double, long double>,
                              pair<long double, long double> > &v) {
  return is_zero(dp(u.second - u.first, v.second - v.first));
}
inline pair<pair<long double, long double>, pair<long double, long double> >
segment_bisector(const pair<pair<long double, long double>,
                            pair<long double, long double> > &u) {
  pair<long double, long double> p = (u.first + u.second) / 2;
  return pair<pair<long double, long double>, pair<long double, long double> >(
      p, rotate90(u.second, p));
}
inline pair<pair<long double, long double>, pair<long double, long double> >
angle_bisector(const pair<long double, long double> &a,
               const pair<long double, long double> &o,
               const pair<long double, long double> &b) {
  return pair<pair<long double, long double>, pair<long double, long double> >(
      o, rotate(b, o, angle(a, o, b) / 2));
}
inline pair<long double, long double> intersection_line_line(
    const pair<pair<long double, long double>, pair<long double, long double> >
        &u,
    const pair<pair<long double, long double>, pair<long double, long double> >
        &v) {
  long double p = cp(u.second - v.first, u.second - u.first);
  long double q = cp(v.second - v.first, u.second - u.first);
  if (is_zero(q)) return FAIL;
  return v.first + (v.second - v.first) * (p / q);
}
const pair<pair<long double, long double>, long double> CFAIL =
    pair<pair<long double, long double>, long double>(FAIL, 0);
pair<pair<long double, long double>, long double> incircle(
    const pair<long double, long double> &a,
    const pair<long double, long double> &b,
    const pair<long double, long double> &c) {
  if (is_zero(cp(b - a, c - a))) return CFAIL;
  pair<pair<long double, long double>, pair<long double, long double> > p =
      segment_bisector(
          pair<pair<long double, long double>, pair<long double, long double> >(
              a, b));
  pair<pair<long double, long double>, pair<long double, long double> > q =
      segment_bisector(
          pair<pair<long double, long double>, pair<long double, long double> >(
              a, c));
  pair<long double, long double> t = intersection_line_line(p, q);
  return pair<pair<long double, long double>, long double>(t, pieprzu(t, a));
}
pair<long double, long double> intersection_segment_segment(
    const pair<pair<long double, long double>, pair<long double, long double> >
        &u,
    const pair<pair<long double, long double>, pair<long double, long double> >
        &v) {
  pair<long double, long double> r = intersection_line_line(u, v);
  if (on_segment(r, u) and on_segment(r, v))
    return r;
  else
    return FAIL;
}
int main() {
  int N, X, Y;
  scanf("%d %d %d", &N, &X, &Y);
  vector<pair<long double, long double> > P;
  int max_a = 0;
  int max_b = 0;
  for (int(i) = (1); (i) <= (N); (i)++) {
    int a, b;
    scanf("%d %d", &a, &b);
    max_a = max(max_a, a);
    max_b = max(max_b, b);
    P.emplace_back(a, b);
  }
  P.emplace_back(max_a, 0);
  P.emplace_back(0, max_b);
  P = convex_hull(P);
  pair<long double, long double> n(X, Y);
  pair<long double, long double> z;
  for (int(i) = (1); (i) <= (1500000); (i)++) {
    if (X * i > 1490490 or Y * i > 1490010) {
      z = pair<long double, long double>(X * i, Y * i);
      break;
    }
  }
  pair<pair<long double, long double>, pair<long double, long double> > s(
      pair<long double, long double>(0, 0), z);
  long double result = INF;
  for (int(i) = (0); (i) < (int(P.size())); (i)++) {
    pair<long double, long double> a = P[i];
    pair<long double, long double> b = P[(i + 1) % int(P.size())];
    pair<pair<long double, long double>, pair<long double, long double> > t(a,
                                                                            b);
    pair<long double, long double> d = intersection_segment_segment(s, t);
    if (d == FAIL) continue;
    result = min(result, pieprzu(pair<long double, long double>(X, Y),
                                 pair<long double, long double>(0, 0)) /
                             pieprzu(d, pair<long double, long double>(0, 0)));
  }
  cout << fixed << result << endl;
  return 0;
}
