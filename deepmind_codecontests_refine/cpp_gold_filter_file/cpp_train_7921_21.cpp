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
pair<A, B> operator+=(pair<A, B>& a, const pair<A, B>& b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}
template <typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a, const pair<A, B>& b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a) {
  return make_pair(-a.first, -a.second);
}
template <typename A, typename B>
pair<A, B> operator-=(pair<A, B>& a, const pair<A, B>& b) {
  a.first -= b.first;
  a.second -= b.second;
  return a;
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
bool nprcs(const pair<A, A>& a, const pair<A, A>& c) {
  return ((a % c) >= 0);
}
template <typename A>
bool nprcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c) {
  return nprcs(a - b, a - c);
}
template <typename A>
bool npocs(const pair<A, A>& a, const pair<A, A>& c) {
  return ((a % c) <= 0);
}
template <typename A>
bool npocs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c) {
  return npocs(a - b, a - c);
}
template <typename A>
bool prcs(const pair<A, A>& a, const pair<A, A>& c) {
  return ((a % c) > 0);
}
template <typename A>
bool prcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c) {
  return prcs(a - b, a - c);
}
template <typename A>
bool pocs(const pair<A, A>& a, const pair<A, A>& c) {
  return ((a % c) < 0);
}
template <typename A>
bool pocs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c) {
  return pocs(a - b, a - c);
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
pair<A, A> rot_90(const pair<A, A>& p) {
  return make_pair(-p.second, p.first);
}
template <typename A>
pair<A, A> rot_90(const pair<A, A>& p, const pair<A, A>& c) {
  return c + rot_90(p - c);
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
  pair<A, A> p = b - a;
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
vector<pair<double, double>> circle_intersection(const pair<pair<A, A>, A>& a,
                                                 const pair<pair<A, A>, A>& b) {
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
      return vector<pair<double, double>>(1, baza);
  } else
    return vector<pair<double, double>>();
}
template <typename A, typename B>
pair<A, B> sopr(const pair<A, B>& p) {
  return make_pair(p.first, -p.second);
}
template <typename A>
bool on_segment(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c) {
  return are_codirected(b - a, c - b);
}
template <typename A>
pair<pair<A, A>, A> perpendicular(const pair<A, A>& line,
                                  const pair<A, A>& point) {
  return line_with_normal_vector_through_point(rot_90(line), point);
}
pair<double, double> projection(const pair<pair<double, double>, double>& line,
                                const pair<double, double>& point) {
  pair<pair<double, double>, double> temp = perpendicular(line.first, point);
  return ints(line.first, line.second, temp.first, temp.second);
}
pair<double, double> height(const pair<double, double>& a,
                            const pair<double, double>& b,
                            const pair<double, double>& c) {
  return projection(l_th_2(a, c), b);
}
template <typename T>
vector<int> z_function(const vector<T>& s) {
  int n = ((int)(s.size()));
  vector<int> z(n);
  int l = 0, r = 1;
  for (int i = 1; i < n; ++i) {
    z[i] = max(0, min(r - i, z[i - l]));
    while (i + z[i] < n && (s[i + z[i]] == s[z[i]])) ++z[i];
    if (r < i + z[i]) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}
pair<int, int> euc(const int& m, const int& n) {
  if (n == 0) return pair<int, int>((m >= 0) ? 1 : -1, 0);
  int t = m / n;
  pair<int, int> ans1 = euc(n, m - t * n);
  return pair<int, int>(ans1.second, ans1.first - ans1.second * t);
}
int prod(const int& a, const int& b, const int& M) {
  return ((long long)(a)) * b % M;
}
int sum(const int& a, const int& b, const int& M) {
  int c = a + b;
  return c >= M ? c - M : c;
}
int raz(const int& a, const int& b, const int& M) {
  int c = a - b;
  return c < 0 ? c + M : c;
}
template <typename A>
bool angdis_cmp(const pair<A, A>& a, const pair<A, A>& b) {
  A p;
  if (p = a % b)
    return (p > 0);
  else
    return sq_len(a) < sq_len(b);
}
template <typename T>
int find_min_idx(const vector<T>& v) {
  int ans = 0, n = ((int)(v.size()));
  for (int i = 1; i < n; ++i)
    if (v[i] < v[ans]) ans = i;
  return ans;
}
template <typename T>
vector<int> convex_hull(vector<pair<T, T>>& a) {
  int n = ((int)(a.size()));
  if (n) {
    int mt = find_min_idx(a);
    pair<T, T> d = a[mt];
    for (int i = 0; i < n; ++i) a[i] -= d;
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) idx[i] = i;
    sort(idx.begin(), idx.end(),
         [&](const int& l, const int& r) { return angdis_cmp(a[l], a[r]); });
    vector<int> h(1, idx.front());
    for (auto it = idx.begin() + 1; it != idx.end(); ++it) {
      auto temp = a.begin() + *it;
      if (((int)(h.size())) >= 2) {
        if (are_parallel(a[h.back()], *temp)) h.pop_back();
        while ((((int)(h.size())) >= 3) &&
               npocs(a[h[((int)(h.size())) - 2]], a[h.back()], *temp))
          h.pop_back();
      }
      h.push_back(*it);
    }
    for (int i = 0; i < n; ++i) a[i] += d;
    return h;
  } else
    return vector<int>();
}
int gcd(const int& a, const int& b) { return b ? gcd(b, a % b) : a; }
const int N = 15000001;
vector<int> list_of_primes(int n, const vector<bool>& pr,
                           const vector<int>& prs, const vector<int>& dlt,
                           const vector<int>& ch) {
  unordered_set<int> u;
  while (n > 1) {
    int t = dlt[n];
    u.insert(t);
    n = ch[n];
  }
  vector<int> ans;
  for (auto it = u.begin(); it != u.end(); ++it) ans.push_back(*it);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1)
    cout << m - min(m % 6, 6 - m % 6);
  else if (n == 2) {
    if (m == 2)
      cout << 0;
    else if (m == 3)
      cout << 4;
    else if (m == 7)
      cout << 12;
    else
      cout << 2 * m;
  } else if ((n % 2 == 0) || (m % 2 == 0))
    cout << n * m;
  else
    cout << n * m - 1;
  cout << '\n';
  return 0;
}
