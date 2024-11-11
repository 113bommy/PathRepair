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
int dbcmp(const double& a, const double& b) {
  return (a > b + eps) - (a < b - eps);
}
int sgn(const double& first) { return dbcmp(first, 0); }
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
  while (first < ((int)(st).size())) st[first] += inc, first |= first + 1;
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
  while ((1 << (++second)) < ((int)(st).size()))
    ;
  for (int i = (second - 1); i >= 0; --i) {
    if ((first += 1 << i) > ((int)(st).size()) || z + st[first - 1] > k)
      first -= 1 << i;
    else
      z += st[first - 1];
  }
  return first;
}
inline void make_set(vector<int>& set) {
  for (int i = (0); i < (((int)(set).size())); ++i) set[i] = i;
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
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > cnt(2);
  for (int i = (0); i < (n); ++i) {
    int t;
    cin >> t, --t;
    int first, second;
    cin >> first >> second;
    cnt[t].first += first, cnt[t].second += second;
  }
  for (int i = (0); i < (2); ++i)
    puts(cnt[i].first >= cnt[i].second ? "LIVE" : "DEAD");
}
