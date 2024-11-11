#include <bits/stdc++.h>
using namespace std;
typedef const char* cstr;
const int oo = (~0u) >> 1;
const long long int ooll = (~0ull) >> 1;
const double inf = 1e+20;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int MOD = 1000000007;
template <typename type>
inline bool cmax(type& a, const type& b) {
  return a < b ? a = b, true : false;
}
template <typename type>
inline bool cmin(type& a, const type& b) {
  return b < a ? a = b, true : false;
}
template <typename type>
inline type sqr(const type& first) {
  return first * first;
}
inline int dbcmp(const double& a, const double& b) {
  return (a > b + eps) - (a < b - eps);
}
inline int sgn(const double& first) { return dbcmp(first, 0); }
template <typename type>
inline type cross(const pair<type, type>& a, const pair<type, type>& b,
                  const pair<type, type>& c) {
  return (b.first - a.first) * (c.second - a.second) -
         (b.second - a.second) * (c.first - a.first);
}
template <typename type>
inline type dot(const pair<type, type>& a, const pair<type, type>& b,
                const pair<type, type>& c) {
  return (b.first - a.first) * (c.first - a.first) +
         (b.second - a.second) * (c.second - a.second);
}
template <typename type>
inline type gcd(type a, type b) {
  if (b)
    while ((a %= b) && (b %= a))
      ;
  return a + b;
}
template <typename type>
inline type lcm(type a, type b) {
  return a * b / gcd(a, b);
}
template <typename type>
inline void bit_inc(vector<type>& st, int first, type inc) {
  while (first < (int((st).size()))) st[first] += inc, first |= first + 1;
}
template <typename type>
inline type bit_sum(const vector<type>& st, int first) {
  type s = 0;
  while (first >= 0) s += st[first], first = (first & (first + 1)) - 1;
  return s;
}
template <typename type>
inline type bit_kth(const vector<type>& st, int k) {
  int first = 0, second = 0, z = 0;
  while ((1 << (++second)) < (int((st).size())))
    ;
  for (int i = (second - 1); i >= 0; --i) {
    if ((first += 1 << i) > (int((st).size())) || z + st[first - 1] > k)
      first -= 1 << i;
    else
      z += st[first - 1];
  }
  return first;
}
inline void make_set(vector<int>& set) {
  for (int i = (0); i < ((int((set).size()))); ++i) set[i] = i;
}
inline int find_set(vector<int>& set, int first) {
  int second = first, z;
  while (second != set[second]) second = set[second];
  while (first != set[first]) z = set[first], set[first] = second, first = z;
  return second;
}
inline bool union_set(vector<int>& set, int a, int b) {
  a = find_set(set, a), b = find_set(set, b);
  return a != b ? set[a] = b, true : false;
}
template <typename type>
inline void merge(type& a, type& b) {
  if ((int((a).size())) < (int((b).size()))) swap(a, b);
  while ((int((b).size()))) a.insert(*b.begin()), b.erase(b.begin());
}
template <typename type>
inline void merge(priority_queue<type>& a, priority_queue<type>& b) {
  if ((int((a).size())) < (int((b).size()))) swap(a, b);
  while ((int((b).size()))) a.push(b.top()), b.pop();
}
struct Initializer {
  Initializer() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  ~Initializer() { cerr; }
} initializer;
long long int get(long long int t, long long int n, long long int first,
                  long long int second) {
  long long int ans = 1 + t * (t + 1) / 2 * 4;
  long long int l = first - t, r = first + t, u = second - t, d = second + t;
  if (l < 1) ans -= sqr(1 - l);
  if (r > n) ans -= sqr(r - n);
  if (u < 1) ans -= sqr(u - 1);
  if (d > n) ans -= sqr(d - n);
  if (first + second <= t)
    ans += (t - (first + second) + 1) * ((t - (first + second) + 1) + 1) / 2;
  if (first + n - second + 1 <= t)
    ans += (t - (first + n - second + 1) + 1) *
           ((t - (first + n - second + 1) + 1) + 1) / 2;
  if (n - first + 1 + second <= t)
    ans += (t - (n - first + 1 + second) + 1) *
           ((t - (n - first + 1 + second) + 1) + 1) / 2;
  if (n - first + 1 + n - second + 1 <= t)
    ans += (t - (n - first + 1 + n - second + 1) + 1) *
           ((t - (n - first + 1 + n - second + 1) + 1) + 1) / 2;
  cerr, cerr;
  return ans;
}
int main() {
  long long int n, first, second, c;
  cin >> n >> first >> second >> c;
  long long int l = -1, r = n;
  while (l + 1 != r) {
    long long int mid = (l + r) >> 1;
    if (get(mid, n, first, second) >= c)
      r = mid;
    else
      l = mid;
  }
  cout << r << '\n';
}
