#include <bits/stdc++.h>
using namespace std;
typedef char* cstr;
const int oo = (~0u) >> 1;
const long long int ooll = (~0ull) >> 1;
const double inf = 1e8;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <typename type>
inline bool cmax(type& a, const type& b) {
  return a < b ? a = b, true : false;
}
template <typename type>
inline bool cmin(type& a, const type& b) {
  return a > b ? a = b, true : false;
}
template <typename type>
inline type sqr(const type& first) {
  return first * first;
}
template <typename type>
inline int sgn(const type& first) {
  return (first > 0) - (first < 0);
}
template <>
inline int sgn(const double& first) {
  return (first > +eps) - (first < -eps);
}
template <typename type>
inline type lb(type first) {
  return first & (-first);
}
template <typename type>
inline void bit_inc(vector<type>& st, int first, type inc) {
  while (first < ((int)(st).size())) st[first] += inc, first += lb(first);
}
template <typename type>
inline type bit_sum(const vector<type>& st, int first) {
  type s = 0;
  while (first > 0) s += st[first], first -= lb(first);
  return s;
}
inline void make_set(vector<int>& set, int size) {
  set.resize(size);
  for (int i = 0; i < (size); ++i) set[i] = i;
}
inline int find_set(vector<int>& set, int first) {
  if (set[first] != first) set[first] = find_set(set, set[first]);
  return set[first];
}
inline bool union_set(vector<int>& set, int a, int b) {
  a = find_set(set, a), b = find_set(set, b);
  return a == b ? false : set[a] = b, true;
}
int main() {
  int n, r;
  cin >> n >> r;
  int ans = n;
  int a;
  for (int i = 0; i < (r); ++i) {
    int get = 0, s = 0;
    int max = r, min = i;
    for (;;) {
      if (max == 1 && min == 0 && s == n) {
        if (cmin(ans, get)) a = i;
        break;
      }
      if (min <= 0) break;
      int nmin = max - min, nmax = min;
      if (nmin > nmax) {
        get++;
        max = nmin, min = nmax;
      } else
        max = nmax, min = nmin;
      s++;
    }
  }
  if (ans == n)
    cout << "IMPOSSIBLE" << endl;
  else {
    cout << ans << endl;
    vector<char> s(n);
    int max = r, min = a;
    int i = n - 1;
    s[i] = 'T';
    for (;;) {
      if (max == 1 && min == 0) break;
      int nmin = max - min, nmax = min;
      if (nmin > nmax) {
        if (i) s[i - 1] = s[i];
        max = nmin, min = nmax;
      } else {
        if (i) s[i - 1] = 'T' + 'B' - s[i];
        max = nmax, min = nmin;
      }
      i--;
    }
    if (s[0] != 'T')
      for (int i = 0; i < (n); ++i) s[i] = 'T' + 'B' - s[i];
    for (int i = 0; i < (n); ++i) cout << s[i];
    cout << endl;
  }
}
