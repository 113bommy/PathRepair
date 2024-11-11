#include <bits/stdc++.h>
#pragma comment(linker, "/stack:256000000")
#pragma gcc optimize("O3")
#pragma gcc target("sse4")
using namespace std;
mt19937 rng(2391);
mt19937 gnr(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename A>
istream& operator>>(istream& fin, vector<A>& v) {
  for (auto it = v.begin(); it != v.end(); ++it) fin >> *it;
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
pair<A, B>& operator++(pair<A, B>& a) {
  ++a.first;
  ++a.second;
  return a;
}
template <typename A, typename B>
pair<A, B>& operator--(pair<A, B>& a) {
  --a.first;
  --a.second;
  return a;
}
template <typename A>
vector<A>& operator++(vector<A>& a) {
  for (auto it = a.begin(); it != a.end(); ++it) ++*it;
  return a;
}
template <typename A>
vector<A>& operator--(vector<A>& a) {
  for (auto it = a.begin(); it != a.end(); ++it) --*it;
  return a;
}
template <typename A, typename B>
pair<A, B> operator++(pair<A, B>& a, int) {
  pair<A, B> b = a;
  ++a;
  return b;
}
template <typename A, typename B>
pair<A, B> operator--(pair<A, B>& a, int) {
  pair<A, B> b = a;
  --a;
  return b;
}
template <typename A>
vector<A>& operator++(vector<A>& a, int) {
  vector<A> b = a;
  ++a;
  return b;
}
template <typename A>
vector<A>& operator--(vector<A>& a, int) {
  vector<A> b = a;
  --a;
  return b;
}
vector<vector<int>> adjlist_from_edgelist(const vector<pair<int, int>>& e,
                                          const int& n) {
  vector<vector<int>> g(n);
  for (auto it = e.begin(); it != e.end(); ++it) {
    g[it->first].push_back(it->second);
    g[it->second].push_back(it->first);
  }
  return g;
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
pair<double, double> unitvector(const pair<double, double>& a) {
  return a * (1 / len(a));
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
const int LITTLE_BORDER = 400;
struct factorizator {
  int N;
  vector<int> pr;
  vector<int> md;
  vector<int> pw;
  vector<int> without_md;
  factorizator(const int& n) : N(n), md(n), pw(n), without_md(n, 1) {
    for (int i = 2; i < N; ++i) md[i] = i;
    for (int i = 2; i < N; ++i) {
      if (md[i] == i) pr.push_back(i);
      bool worth = true;
      for (int j = 0; worth && (j < ((int)(pr.size()))) && (pr[j] <= md[i]);
           ++j) {
        long long temp = ((long long)(pr[j])) * i;
        if (temp < N)
          md[((int)temp)] = pr[j];
        else
          worth = false;
      }
    }
    for (int i = 2; i < N; ++i) {
      int t = md[i], s = i / t;
      if (md[s] == t) {
        pw[i] = 1 + pw[s];
        without_md[i] = without_md[s];
      } else {
        pw[i] = 1;
        without_md[i] = s;
      }
    }
  }
  void known_factorization(int n, vector<pair<unsigned long long, int>>& v) {
    while (n > 1) {
      v.emplace_back(md[n], pw[n]);
      n = without_md[n];
    }
  }
  vector<pair<unsigned long long, int>> pollardRho(const unsigned long long& n);
  vector<pair<unsigned long long, int>> factor(unsigned long long n);
  template <typename T>
  vector<pair<T, int>> merge(const vector<pair<T, int>>& p1,
                             const vector<pair<T, int>>& p2) {
    vector<pair<T, int>> ans;
    int m = ((int)(p1.size()));
    int n = ((int)(p2.size()));
    int i = 0;
    int j = 0;
    while ((i < m) || (j < n)) {
      if (i < m) {
        if (j < n) {
          if (p1[i].first < p2[j].first)
            ans.push_back(p1[i++]);
          else if (p1[i].first > p2[j].first)
            ans.push_back(p2[j++]);
          else {
            ans.emplace_back(p1[i].first, p1[i].second + p2[j].second);
            ++i;
            ++j;
          }
        } else
          ans.push_back(p1[i++]);
      } else
        ans.push_back(p2[j++]);
    }
    return ans;
  }
};
factorizator fac(LITTLE_BORDER);
unsigned long long experimental_prodll(const unsigned long long& a,
                                       const unsigned long long& b,
                                       const unsigned long long& M,
                                       const int& helper) {
  if (M == 0) return 0;
  unsigned long long q = ((long double)a) * b / M;
  unsigned long long a1 = a * b - q * M;
  unsigned long long a2 = a1;
  int rm = M % helper;
  int ra = a % helper;
  int rb = b % helper;
  int rq = q % helper;
  int r1 = raz(prod(ra, rb, helper), prod(rq, rm, helper), helper);
  int r2 = r1;
  while (true) {
    if (a1 % helper == r1 && a1 < M) return a1;
    a1 -= M;
    r1 = raz(r1, rm, helper);
    a2 += M;
    r2 = sum(r2, rm, helper);
    if (a2 % helper == r2 && a2 < M) return a2;
  }
}
inline int find_helper(const unsigned long long& M) {
  int i = 30;
  while (M % fac.pr[i] == 0) ++i;
  return fac.pr[i];
}
unsigned long long prodll(const unsigned long long& a,
                          const unsigned long long& b,
                          const unsigned long long& M) {
  if (M == 0) return 0;
  unsigned long long helper = find_helper(M);
  return experimental_prodll(a, b, M, helper);
}
unsigned long long sumll(const unsigned long long& a,
                         const unsigned long long& b,
                         const unsigned long long& M) {
  if (a < M - b)
    return a + b;
  else
    return a + b - M;
}
unsigned long long razll(const unsigned long long& a,
                         const unsigned long long& b,
                         const unsigned long long& M) {
  if (a >= b)
    return a - b;
  else
    return a + M - b;
}
template <typename T>
T diff(const T& a, const T& b) {
  return (a > b) ? (a - b) : (b - a);
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
pair<int, int> cool_gcd(const int& a, const int& b) {
  if (b) {
    int c = a / b;
    pair<int, int> ans1 = cool_gcd(b, a - b * c);
    return pair<long long, long long>(ans1.second,
                                      ans1.first - ans1.second * c);
  } else
    return pair<int, int>(1, 0);
}
pair<long long, long long> cool_gcdll(const long long& a, const long long& b) {
  if (b) {
    long long c = a / b;
    pair<long long, long long> ans1 = cool_gcdll(b, a - b * c);
    return pair<long long, long long>(ans1.second,
                                      ans1.first - ans1.second * c);
  } else
    return pair<long long, long long>(1ll, 0ll);
}
template <typename T>
T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long pr_p(const long long& a, const long long& b, const long long& p) {
  if (b < 1000000) return (a * b) % p;
  long long temp = pr_p(a, b >> 1ll, p);
  temp = sumll(temp, temp, p);
  if (b & 1ll)
    return sumll(temp, a, p);
  else
    return temp;
}
long long po_p(const long long& a, const long long& b, const long long& p) {
  if (b < 2) {
    if (b == 0)
      return 1;
    else
      return a;
  }
  long long temp = po_p(a, b >> 1ll, p);
  temp = pr_p(temp, temp, p);
  if (b & 1ll)
    return pr_p(temp, a, p);
  else
    return temp;
}
int pow_mod(const int& a, const int& b, const int& p) {
  if (b < 2) {
    if (b == 0)
      return 1;
    else
      return a;
  }
  int temp = pow_mod(a, b >> 1, p);
  temp = prod(temp, temp, p);
  if (b & 1)
    return prod(temp, a, p);
  else
    return temp;
}
long long pow_modll(const long long& a, const long long& b,
                    const long long& p) {
  if (b < 2) {
    if (b == 0)
      return 1;
    else
      return a;
  }
  long long temp = pow_modll(a, b >> 1ll, p);
  temp = prodll(temp, temp, p);
  if (b & 1ll)
    return prodll(temp, a, p);
  else
    return temp;
}
int inverse(int a, int n) {
  int c = cool_gcd(a, n).first;
  if (c < 0) c += n;
  return c;
}
long long inversell(long long a, long long n) {
  long long c = cool_gcdll(a, n).first;
  if (c < 0) c += n;
  return c;
}
template <typename A>
pair<int, int> equal_elements(const vector<A>& u, const vector<A>& v) {
  pair<int, int> ans(INT_MAX, INT_MAX);
  int m = ((int)(u.size())), n = ((int)(v.size()));
  vector<int> id_u(m);
  for (int i = 1; i < m; ++i) id_u[i] = i;
  vector<int> id_v(n);
  for (int i = 1; i < n; ++i) id_v[i] = i;
  sort(id_u.begin(), id_u.end(),
       [&](const int& x, const int& y) { return u[x] < u[y]; });
  sort(id_v.begin(), id_v.end(),
       [&](const int& x, const int& y) { return v[x] < v[y]; });
  int i = 0;
  int j = 0;
  while ((i < m) && (j < n)) {
    if (u[id_u[i]] < v[id_v[j]])
      ++i;
    else if (v[id_v[j]] < u[id_u[i]])
      ++j;
    else {
      ans = min(ans, pair<int, int>(id_v[j], id_u[i]));
      ++j;
    }
  }
  if (ans.first == INT_MAX)
    return pair<int, int>(-1, -1);
  else
    return pair<int, int>(ans.second, ans.first);
}
long long discr_log(long long a, long long b, long long n) {
  int k = ((int)(sqrt((long double)n)));
  long long a1 = inversell(a, n);
  int l = k + 20;
  long long a2 = po_p(a1, k, n);
  vector<long long> seq1(k), seq2(l);
  seq1.front() = 1;
  for (int i = 1; i < k; ++i) seq1[i] = pr_p(seq1[i - 1], a, n);
  seq2.front() = b;
  for (int i = 1; i < l; ++i) seq2[i] = pr_p(seq2[i - 1], a2, n);
  pair<long long, long long> e = equal_elements(seq1, seq2);
  if (e.first == -1)
    return -1;
  else
    return e.first + e.second * k;
}
long long common_discr_log(long long a, long long b, long long n) {
  const int C = 70;
  a %= n;
  b %= n;
  if (gcd(n, a) != 1) {
    for (int i = 0; i < C; ++i) {
      if (po_p(a, i, n) == b) {
        return i;
      }
    }
    long long multp = po_p(a, C, n);
    long long g = gcd(multp, n);
    if (b % g) {
      return -1;
    } else {
      b /= g;
      n /= g;
      multp /= g;
      long long pop_back = inversell(multp, n);
      b = pr_p(b, pop_back, n);
      long long ans = discr_log(a, b, n);
      if (ans == -1)
        return -1;
      else
        return ans + C;
    }
  } else
    return discr_log(a, b, n);
}
const unsigned long long minimum_composites[] = {1ull,
                                                 2046ull,
                                                 1373652ull,
                                                 25326000ull,
                                                 3215031750ull,
                                                 2152302898746ull,
                                                 3474749660382ull,
                                                 341550071728320ull,
                                                 341550071728320ull,
                                                 3825123056546413050ull,
                                                 3825123056546413050ull,
                                                 18446744073709551615ull};
const int little_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
bool miller_rabin_check(const unsigned long long& n,
                        const unsigned long long& prime,
                        const unsigned long long& odd,
                        const unsigned long long& pot,
                        const unsigned long long& nmo) {
  long long x = pow_modll(prime, odd, n);
  if ((x == nmo) || (x == 1)) return true;
  for (int i = 1; i < pot; ++i) {
    x = prodll(x, x, n);
    if (x == nmo) return true;
    if (x == 1) return false;
  }
  return false;
}
bool is_prime(const unsigned long long& n) {
  if (n <= 2) return (n == 2);
  unsigned long long odd, pot, nmo;
  nmo = n - 1;
  odd = nmo;
  pot = 0;
  while ((odd & 1ll) == 0) {
    odd >>= 1ll;
    ++pot;
  }
  int i = 0;
  while (n > minimum_composites[i]) {
    if (miller_rabin_check(n, little_primes[i], odd, pot, nmo) == false)
      return false;
    ++i;
  }
  return true;
}
vector<pair<unsigned long long, int>> factorizator::pollardRho(
    const unsigned long long& n) {
  if (is_prime(n))
    return vector<pair<unsigned long long, int>>(
        1, pair<unsigned long long, int>(n, 1));
  int step = 1;
  while (true) {
    step <<= 1;
    unsigned long long a = rng();
    unsigned long long b = a;
    unsigned long long d = 1;
    for (int j = 0; j < step; ++j) {
      a = sumll(1, prodll(a, a, n), n);
      b = sumll(1, prodll(b, b, n), n);
      b = sumll(1, prodll(b, b, n), n);
      d = gcd(diff(a, b), n);
      if (d > 1) {
        break;
      }
    }
    if (1 < d && d < n) return merge(pollardRho(d), pollardRho(n / d));
  }
  return vector<pair<unsigned long long, int>>();
}
vector<pair<unsigned long long, int>> factorizator::factor(
    unsigned long long n) {
  vector<pair<unsigned long long, int>> ans;
  for (int i = 0; n >= N && i < ((int)(pr.size())) && pr[i] < LITTLE_BORDER;
       ++i)
    while (n % pr[i] == 0) {
      if (((int)(ans.size())) && ans.back().first == pr[i])
        ++ans.back().second;
      else
        ans.emplace_back(pr[i], 1);
      n /= pr[i];
    }
  if (n < N) {
    known_factorization(n, ans);
    return ans;
  } else
    return merge(ans, pollardRho(n));
}
template <typename T>
T phi(const vector<pair<T, int>>& v) {
  T ans = 1;
  for (int i = 0; i < ((int)(v.size())); ++i) {
    ans *= v[i].first - 1;
    for (int j = 1; j < v[i].second; ++j) ans *= v[i].first;
  }
  return ans;
}
unsigned long long phi(const unsigned long long& n) {
  return phi(fac.factor(n));
}
bool check_primitive_root(const int& ph, const vector<int>& to_check,
                          const int& r, const int& n) {
  for (int i = 0; i < ((int)(to_check.size())); ++i)
    if (pow_mod(r, to_check[i], n) == 1) return false;
  return (pow_mod(r, ph, n) == 1);
}
int primitive_root(const int& n) {
  if (n < 3) return n - 1;
  int p = phi(n);
  vector<pair<unsigned long long, int>> f = fac.factor(p);
  vector<int> to_check(((int)(f.size())));
  for (int i = 0; i < ((int)(f.size())); ++i) to_check[i] = p / f[i].first;
  for (int i = 2; i < n; ++i)
    if (check_primitive_root(p, to_check, i, n)) return i;
  return -1;
}
int unite_mod(const int& a, const int& p, const int& b, const int& q) {
  pair<int, int> c = cool_gcd(p, q);
  int pr = p * q;
  int ans = ((a * c.second * q + b * c.first * p) % pr + pr) % pr;
  return ans;
}
long long unite_modll(const long long& a, const long long& p,
                      const long long& b, const long long& q) {
  pair<long long, long long> c = cool_gcdll(p, q);
  long long pr = p * q;
  long long ans = ((a * c.second * q + b * c.first * p) % pr + pr) % pr;
  return ans;
}
pair<int, int> power_v(int n, const int& p) {
  int ans = 0;
  while (n % p == 0) {
    n /= p;
    ++ans;
  }
  return pair<int, int>(ans, n);
}
int square_root_prime_modulo(int c, int n, const int& pr, const int& k) {
  c %= n;
  if (c) {
    pair<int, int> kek = power_v(c, pr);
    int l = kek.first;
    if (l & 1) return -1;
    if (l > 0) {
      int pwl = 1;
      for (int i = 0; i < l; ++i) pwl *= pr;
      n /= pwl;
      c /= pwl;
      int ans1 = square_root_prime_modulo(c, n, pr, k - l);
      if (ans1 == -1) return -1;
      for (int i = 0; i < (l >> 1); ++i) ans1 *= pr;
      return ans1;
    } else {
      int primitive;
      if (n & 1)
        primitive = primitive_root(n);
      else
        primitive = 5;
      int u = ((int)discr_log(primitive, c, n));
      if (u == -1) return -1;
      if (u & 1) return -1;
      return pow_mod(primitive, u >> 1, n);
    }
  } else
    return 0;
}
int square_root_modulo(const int& c, const int& n) {
  vector<pair<unsigned long long, int>> f = fac.factor(n);
  int a = 0, p = 1;
  for (int i = 0; i < ((int)(f.size())); ++i) {
    int q = 1;
    for (int j = 0; j < f[i].second; ++j) q *= f[i].first;
    int b = square_root_prime_modulo(c, q, f[i].first, f[i].second);
    if (b == -1) return -1;
    a = unite_mod(a, p, b, q);
    p *= q;
  }
  return a;
}
namespace BGF {
inline int cntd(unsigned x) {
  int ans = 0;
  while (x) {
    if (x & 1) ++ans;
    x >>= 1;
  }
  return ans;
}
inline long long cntdll(unsigned long long x) {
  long long ans = 0;
  while (x) {
    if (x & 1) ++ans;
    x >>= 1;
  }
  return ans;
}
inline int clzd(unsigned x) {
  int ans = 32;
  while (x) {
    --ans;
    x >>= 1;
  }
  return ans;
}
inline long long clzdll(unsigned long long x) {
  long long ans = 64;
  while (x) {
    --ans;
    x >>= 1;
  }
  return ans;
}
inline int ctzd(unsigned x) {
  if (x == 0) return 32;
  int ans = 0;
  while ((x & 1) == 0) {
    ++ans;
    x >>= 1;
  }
  return ans;
}
inline long long ctzdll(unsigned long long x) {
  if (x == 0) return 64;
  long long ans = 0;
  while ((x & 1) == 0) {
    ++ans;
    x >>= 1;
  }
  return ans;
}
}  // namespace BGF
namespace BGF {
const unsigned BHC = 65535u;
const unsigned long long BHCL = 65535ull;
const unsigned BHN = 65536u;
const unsigned BHL = 16u;
const unsigned LH = 4294901760u;
const unsigned RH = 65535u;
const unsigned long long BHLL1 = 16ull;
const unsigned long long BHLL2 = 32ull;
const unsigned long long BHLL3 = 48ull;
const unsigned long long LHL = 18446744069414584320ull;
const unsigned long long RHL = 4294967295ull;
int CNT[BHN];
int CLZ[BHN];
int CTZ[BHN];
inline void initialize() {
  CNT[0] = 0;
  CLZ[0] = BHL + BHL;
  CTZ[0] = BHL;
  for (unsigned i = 1; i < BHN; ++i) {
    CNT[i] = cntd(i);
    CLZ[i] = clzd(i);
    CTZ[i] = ctzd(i);
  }
}
inline int cntc(const unsigned& x) {
  return CNT[x & BHC] + CNT[(x >> BHL) & BHC];
}
inline long long cntcll(const unsigned long long& x) {
  return CNT[x & BHCL] + CNT[(x >> BHLL1) & BHCL] + CNT[(x >> BHLL2) & BHCL] +
         CNT[(x >> BHLL3) & BHCL];
}
inline int clzc(const unsigned& x) {
  if (x & LH)
    return CLZ[x >> BHL] - BHL;
  else
    return CLZ[x];
}
inline long long clzcll(const unsigned long long& x) {
  if (x & LHL)
    return clzc(x >> BHLL2);
  else
    return clzc(x) + BHLL2;
}
inline int ctzc(const unsigned& x) {
  if (x & RH)
    return CTZ[x & RH];
  else
    return CTZ[x >> BHL] + BHL;
}
inline long long ctzcll(const unsigned long long& x) {
  if (x & RHL)
    return ctzc(x);
  else
    return ctzc(x >> BHLL2) + BHLL2;
}
}  // namespace BGF
const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "output.txt";
void rel(long long& a, const long long& b) {
  if (a > b) a = b;
}
int another_main() {
  const int INF = 1e9 + 1;
  const long long SINF = 1e12 + 2;
  const long long SSINF = 1e18 + 2;
  const int MINF = -INF;
  int t;
  cin >> t;
  for (int I = 0; I < t; ++I) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> u;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      u.emplace_back(x, -MINF);
    }
    for (int i = 0; i < m; ++i) {
      pair<int, int> p;
      cin >> p;
      u.push_back(pair<int, int>(p.first, -p.second));
    }
    sort(u.begin(), u.end());
    vector<pair<int, int>> w;
    for (pair<int, int> p : u) {
      p.second = -p.second;
      while (((int)(w.size())) &&
             (w.back().second >= p.first && w.back().second >= p.second))
        w.pop_back();
      w.push_back(p);
    }
    int q = 0;
    int mxp = MINF;
    vector<long long> L, R;
    vector<int> into(1);
    vector<pair<int, int>> z;
    for (pair<int, int> p : w)
      if (p.second == MINF) {
        mxp = max(mxp, p.first);
        ++into[q];
      } else {
        z.push_back(p);
        if (mxp != MINF)
          L.push_back(p.first - mxp);
        else
          L.push_back(SINF);
        ++q;
        into.emplace_back();
      }
    R.resize(q);
    int mnp = INF;
    for (int i = ((int)(w.size())) - 1; i >= 0; --i) {
      pair<int, int> p = w[i];
      if (p.second == MINF)
        mnp = min(mnp, p.first);
      else {
        --q;
        if (mnp != INF)
          R[q] = mnp - p.second;
        else
          R[q] = SINF;
      }
    }
    q = ((int)(L.size()));
    vector<vector<long long>> dp(4, vector<long long>(q + 1, SSINF));
    for (int j = 0; j < 4; ++j) dp[j][0] = 0;
    for (int i = 0; i < q; ++i) {
      if (into[i] == 0) {
        if (i) {
          rel(dp[0][i + 1],
              ((long long)z[i].first - z[i - 1].first) + dp[0][i]);
          rel(dp[1][i + 1],
              2ll * ((long long)z[i].first - z[i - 1].first) + dp[1][i]);
          rel(dp[2][i + 1], dp[2][i]);
          rel(dp[3][i + 1], dp[3][i]);
        }
      }
      rel(dp[2][i + 1], 2 * R[i] + dp[0][i]);
      rel(dp[2][i + 1], 2 * R[i] + dp[1][i]);
      rel(dp[3][i + 1], R[i] + dp[0][i]);
      rel(dp[3][i + 1], R[i] + dp[1][i]);
      if (into[i]) {
        rel(dp[1][i + 1], 2 * L[i] + dp[0][i]);
        rel(dp[1][i + 1], 2 * L[i] + dp[1][i]);
        rel(dp[0][i + 1], L[i] + dp[0][i]);
        rel(dp[0][i + 1], L[i] + dp[1][i]);
        rel(dp[2][i + 1], 2 * R[i] + dp[0][i]);
        rel(dp[2][i + 1], 2 * R[i] + dp[1][i]);
        rel(dp[2][i + 1], 2 * R[i] + dp[2][i]);
        rel(dp[2][i + 1], 2 * R[i] + dp[3][i]);
        rel(dp[3][i + 1], R[i] + dp[0][i]);
        rel(dp[3][i + 1], R[i] + dp[1][i]);
        rel(dp[3][i + 1], R[i] + dp[2][i]);
        rel(dp[3][i + 1], R[i] + dp[3][i]);
        if (into[i] == 1) {
          rel(dp[0][i + 1], L[i] + dp[2][i]);
          rel(dp[1][i + 1], 2 * L[i] + dp[3][i]);
        } else {
          rel(dp[0][i + 1], L[i] + dp[3][i]);
        }
      }
      i = i;
    }
    long long ans = SSINF;
    for (int i = 0; i < 4; ++i) ans = min(ans, dp[i][q]);
    cout << ans << '\n';
  }
  return 0;
}
int main() {
  BGF::initialize();
  int AMR = another_main();
  return AMR;
}
