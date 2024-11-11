#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const long long _INF = 0x7ffffffffffffffll;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template <class T, class INT>
inline T pow(T x, INT y) {
  T res(1);
  for (T tt(x); y; y /= 2) {
    if (y & 1) res *= tt;
    tt *= tt;
  }
  return res;
}
template <class T, class INT>
inline T pow(T x, INT y, T p) {
  T res(1);
  for (T tt(x); y; y /= 2) {
    if (y & 1) res = res * tt % p;
    tt = tt * tt % p;
  }
  return res;
}
int toInt(string s) {
  int x = 0;
  istringstream sin(s);
  sin >> x;
  return x;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
template <class INT>
inline INT gcd(INT x, INT y) {
  return y ? gcd(y, x % y) : x;
}
template <class INT>
inline int calc_bits(INT x) {
  return x ? (x & 1) + calc_bits(x >> 1) : 0;
}
const int MAXN = 2000 + 10;
int n, a[MAXN], ans = INF, cnt;
string s;
int main(int argc, char* argv[]) {
  cin >> n >> s;
  s = s + s;
  for (int i = 0; i < (n + n); ++i) a[i + 1] = a[i] + (s[i] == 'T');
  cnt = a[n];
  for (int i = 0; i < (n); ++i)
    ans = ans > (cnt - a[i + cnt] + a[i]) ? (cnt - a[i + cnt] + a[i]) : ans;
  cout << ans << endl;
}
