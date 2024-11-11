#include <bits/stdc++.h>
using namespace std;
typedef char* cstr;
const int oo = (~0u) >> 1;
const long long int ooll = (~0ull) >> 1;
const double inf = 1e100;
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
inline int sgn(const type& first) {
  return (first > 0) - (first < 0);
}
template <>
inline int sgn(const double& first) {
  return (first > +eps) - (first < -eps);
}
template <typename type>
void inc(vector<type>& st, int first, type inc) {
  while (first < ((int)(st).size()))
    st[first] += inc, first += (first) & (-(first));
}
template <typename type>
type sum(vector<type>& st, int first) {
  type s = 0;
  while (first > 0) s += st[first], first -= (first) & (-(first));
  return s;
}
bool first(long long int a, long long int b) {
  long long int aa = a, bb = b;
  bool result;
  if (a == 0)
    result = false;
  else {
    if (first(b % a, a)) {
      b /= a;
      if (a % 2 == 1)
        result = b % 2 == 0;
      else
        result = b % (a + 1) % 2 == 0;
    } else
      result = true;
  }
  return result;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << (first(a, b) ? "First" : "Second") << endl;
  }
}
