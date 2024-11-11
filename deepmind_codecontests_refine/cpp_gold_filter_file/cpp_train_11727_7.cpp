#include <bits/stdc++.h>
using namespace std;
template <typename A>
istream& operator>>(istream& fin, vector<A>& v) {
  int n = ((int)(v.size()));
  for (int i = 0; i < n; ++i) fin >> v[i];
  return fin;
}
template <typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& p) {
  fin >> p.first >> p.second;
  return fin;
}
template <typename A, typename B>
pair<A, B> operator+(const pair<A, B>& a, const pair<A, B>& b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a, const pair<A, B>& b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a) {
  return make_pair(-a.first, -a.second);
}
template <typename A>
A operator*(const pair<A, A>& p, const pair<A, A>& q) {
  return p.first * q.first + p.second * q.second;
}
template <typename A>
pair<A, A> operator*(const pair<A, A>& p, const A& q) {
  return make_pair(p.first * q, p.second * q);
}
template <typename A>
A operator%(const pair<A, A>& p, const pair<A, A>& q) {
  return p.first * q.second - p.second * q.first;
}
template <typename A>
A sq_len(const pair<A, A>& p) {
  return p * p;
}
template <typename A>
A sq_dist(const pair<A, A>& p, const pair<A, A>& q) {
  return sq_len(p - q);
}
template <typename A>
double len(const pair<A, A>& p) {
  return sqrt(sq_len(p));
}
template <typename A>
double dist(const pair<A, A>& p, const pair<A, A>& q) {
  return len(p - q);
}
template <typename A>
bool is_rhombus(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c,
                const pair<A, A>& d) {
  A x = sq_dist(a, b);
  A y = sq_dist(b, c);
  A z = sq_dist(c, d);
  A t = sq_dist(d, a);
  return ((x == y) && (y == z) && (z == t));
}
template <typename A>
bool is_rectangle(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c,
                  const pair<A, A>& d) {
  pair<A, A> x = a - b, y = b - c, z = c - d, t = d - a;
  return ((x * y == 0) && (y * z == 0) && (z * t == 0) && (t * x == 0));
}
template <typename A>
bool are_parallel(const pair<A, A>& a, const pair<A, A>& b) {
  return (a % b == 0);
}
template <typename A>
bool are_orthogonal(const pair<A, A>& a, const pair<A, A>& b) {
  return (a * b == 0);
}
template <typename A>
bool are_codirected(const pair<A, A>& a, const pair<A, A>& b) {
  return (are_parallel(a, b) && (a * b >= 0));
}
template <typename A>
bool is_parallelogram(const pair<A, A>& a, const pair<A, A>& b,
                      const pair<A, A>& c, const pair<A, A>& d) {
  return ((a - b) == (d - c));
}
template <typename A>
bool is_trapezoid(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c,
                  const pair<A, A>& d) {
  pair<A, A> x = a - b, z = d - c;
  return are_codirected(x, z);
}
template <typename A>
bool is_convex_polygon(const pair<A, A>& a, const pair<A, A>& b,
                       const pair<A, A>& c, const pair<A, A>& d) {
  pair<A, A> x = a - b, y = b - c, z = c - d, t = d - a;
  A p = x % y, q = y % z, r = z % t, s = t % x;
  return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
          ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}
template <typename A>
bool npcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c) {
  return (((b - a) % (b - c)) >= 0);
}
template <typename A>
bool different_sides(const pair<A, A>& a, const pair<A, A>& b,
                     const pair<A, A>& c, const pair<A, A>& d) {
  pair<A, A> x = b - a;
  A p = x % (c - b), q = x % (d - b);
  return (((p >= 0) && (q <= 0)) || ((p <= 0) && (q >= 0)));
}
template <typename A>
bool sharply_different_sides(const pair<A, A>& a, const pair<A, A>& b,
                             const pair<A, A>& c, const pair<A, A>& d) {
  pair<A, A> x = b - a;
  A p = x % (c - b), q = x % (d - b);
  return (((p > 0) && (q < 0)) || ((p < 0) && (q > 0)));
}
template <typename A>
pair<A, A> rot_90(const pair<A, A> p) {
  return make_pair(-p.second, p.first);
}
template <typename A>
bool intersecting_segments(const pair<A, A>& a, const pair<A, A>& b,
                           const pair<A, A>& c, const pair<A, A>& d) {
  return different_sides(a, b, c, d) && different_sides(c, d, a, b);
}
template <typename A>
bool sharply_intersecting_segments(const pair<A, A>& a, const pair<A, A>& b,
                                   const pair<A, A>& c, const pair<A, A>& d) {
  return sharply_different_sides(a, b, c, d) &&
         sharply_different_sides(c, d, a, b);
}
template <typename A>
pair<pair<A, A>, A> line_with_normal_vector_through_point(
    const pair<A, A>& normal, const pair<A, A>& point) {
  return make_pair(normal, -(normal * point));
}
template <typename A>
pair<pair<A, A>, A> serper(const pair<A, A>& a, const pair<A, A>& b) {
  pair<double, double> p = b - a;
  return make_pair(p + p, -(p * (a + b)));
}
pair<double, double> ints(const pair<double, double>& p, const double& a,
                          const pair<double, double>& q, const double& b) {
  double D = p % q;
  double E =
      pair<double, double>(-a, p.second) % pair<double, double>(-b, q.second);
  double F =
      pair<double, double>(p.first, -a) % pair<double, double>(q.first, -b);
  return pair<double, double>(E / D, F / D);
}
pair<double, double> circumcenter(const pair<double, double>& x,
                                  const pair<double, double>& y,
                                  const pair<double, double>& z) {
  auto p1 = serper(x, y), p2 = serper(x, z);
  return ints(p1.first, p1.second, p2.first, p2.second);
}
template <typename A>
pair<pair<A, A>, A> l_th_2(const pair<A, A>& p, const pair<A, A>& q) {
  return make_pair(make_pair(q.second - p.second, p.first - q.first), -p % q);
}
template <typename A>
vector<pair<double, double> > circle_intersection(
    const pair<pair<A, A>, A>& a, const pair<pair<A, A>, A>& b) {
  pair<A, A> c = b.first - a.first;
  A rr1 = a.second * a.second, rr2 = b.second * b.second, cc = c * c,
    rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
    D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
  if (D >= 0) {
    double E = (((double)(rr1 - rr2)) / cc + 1) / 2;
    pair<double, double> baza =
        pair<double, double>(a.first.first, a.first.second) +
        pair<double, double>(c.first, c.second) * E;
    if (D) {
      double lll = sqrt((double)(D)) / (2 * cc);
      pair<A, A> cr = rot_90(c);
      pair<double, double> pmm =
          pair<double, double>(cr.first, cr.second) * lll;
      return {baza + pmm, baza - pmm};
    } else
      return vector<pair<double, double> >(1, baza);
  } else
    return vector<pair<double, double> >();
}
template <typename A, typename B>
pair<A, B> sopr(const pair<A, B>& p) {
  return make_pair(p.first, -p.second);
}
template <typename A>
bool on_segment(const pair<A, A> a, const pair<A, A> b, const pair<A, A> c) {
  return are_codirected(b - a, c - b);
}
vector<bool> A_BC(const string& s) {
  int n = ((int)(s.size()));
  vector<bool> ans(n);
  for (int i = 0; i < n; ++i) ans[i] = (s[i] != 'A');
  return ans;
}
vector<int> last_As(const vector<bool>& s) {
  int n = ((int)(s.size()));
  vector<int> ans(n + 1);
  for (int i = 0; i < n; ++i) ans[i + 1] = (s[i] ? 0 : ans[i] + 1);
  return ans;
}
vector<int> pref_Bs(const vector<bool>& s) {
  int n = ((int)(s.size()));
  vector<int> ans(n + 1);
  for (int i = 0; i < n; ++i) ans[i + 1] = (s[i] ? ans[i] + 1 : ans[i]);
  return ans;
}
pair<int, int> infa(const vector<int>& A, const vector<int>& B, const int& a,
                    const int& b) {
  pair<int, int> ans;
  ans.first = min(A[b], b - a);
  ans.second = B[b - ans.first] - B[a];
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  getline(cin, s);
  getline(cin, t);
  vector<bool> S = A_BC(s), T = A_BC(t);
  vector<int> A1 = last_As(S), B1 = pref_Bs(S), A2 = last_As(T),
              B2 = pref_Bs(T);
  int N;
  cin >> N;
  for (int I = 0; I < N; ++I) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    pair<int, int> p1 = infa(A1, B1, a - 1, b), p2 = infa(A2, B2, c - 1, d);
    cout << ((((p1.second ^ p2.second) & 1) || (p1.second > p2.second) ||
              (p1.first < p2.first) ||
              ((p1.second == p2.second) && ((p1.first - p2.first) % 3)) ||
              ((p1.second == 0) && (p2.second) && (p1.first == p2.first)))
                 ? '0'
                 : '1');
  }
  cout << '\n';
  return 0;
}
