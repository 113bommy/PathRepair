#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
inline bool isDigit(char c) { return '0' <= c && c <= '9'; }
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline bool isSquare(T x) {
  T y = sqrt(x + 0.5);
  return (y * y) == x;
}
template <class T1, class T2>
inline T1 gcd(T1 a, T2 b) {
  return b ? gcd(b, a % b) : a;
}
template <class T1, class T2>
inline T1 eqMin(T1 &x, const T2 &y) {
  if (T1(y) < x) return x = y;
  return x;
}
template <class T1, class T2>
inline T1 eqMax(T1 &x, const T2 &y) {
  if (T1(y) > x) return x = y;
  return x;
}
template <class T1, class T2>
inline T1 min(const T1 &x, const T2 &y) {
  return x < (T1)y ? x : (T1)y;
}
template <class T1, class T2>
inline T1 max(T1 &x, const T2 &y) {
  return x > (T1)y ? x : (T1)y;
}
template <typename T>
inline T getint() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') p = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * p;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T>
auto operator<<(ostream &os, const T &v)
    -> decltype(v.begin(), v.end(), declval<ostream &>()) {
  os << '{';
  bool was = false;
  for (const auto &x : v) {
    if (was) os << ", ";
    was = true;
    os << x;
  }
  os << '}';
  return os;
}
template <size_t sz>
ostream &operator<<(ostream &os, const bitset<sz> &bit) {
  os << '/';
  for (int i = 0; i < sz; i++) os << bit[i];
  os << '\\';
  return os;
}
const double PI = acos(-1);
const double EPS = 1e-8;
const int INF = (int)2e9;
const long long LINF = (long long)2e18;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)2e5 + 10;
int n;
string s, t;
long double sum, total;
long long sumPref[MAXN][26], sumSuf[MAXN][26];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    if (i) {
      for (int j = 0; j < 26; j++) {
        sumPref[i][j] = sumPref[i - 1][j];
      }
    }
    sumPref[i][t[i] - 'A'] += i + 1;
    total += (long long)(i + 1) * (i + 1);
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      sumSuf[i][j] = sumSuf[i + 1][j];
    }
    sumSuf[i][t[i] - 'A'] += n - i;
  }
  for (int i = 0; i < n; i++) {
    sum +=
        sumPref[i][s[i] - 'A'] * (n - i) + sumSuf[i + 1][s[i] - 'A'] * (i + 1);
  }
  cout << fixed << setprecision(10) << sum / total;
}
