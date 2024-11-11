#include <bits/stdc++.h>
namespace myland {
using namespace std;
namespace _abbr {
const double EPS(1e-8);
const double PI(acos(-1.0));
const int INF(0x3f3f3f3f);
const long long INFL(0x3f3f3f3f3f3f3f3fll);
const int MOD(1e9 + 7);
}  // namespace _abbr
using namespace _abbr;
namespace _solve {}
using namespace _solve;
namespace _calculate {
bool odd(long long x) { return x & 1; }
bool even(long long x) { return (x & 1) ^ 1; }
bool posi(long long x) { return x > 0; }
bool nega(long long x) { return x < 0; }
bool zero(long long x) { return x == 0; }
bool prime(long long x) {
  if (x < 2) return 0;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
long long droot(long long x) { return 1 + (x - 1) % 9; }
long long upd(long long a, long long b) { return a % b ? a / b + 1 : a / b; };
long long random(long long a, long long b) {
  return a + rand() * rand() % (b - a + 1);
};
long long bitn(long long x) {
  long long c = 0;
  while (x) c++, x >>= 1;
  return c;
}
template <class T>
T sqr(T x) {
  return x * x;
}
long long qpow(long long a, long long n, long long mod = MOD) {
  long long res(1);
  while (n) {
    if (n & 1) (res *= a) %= mod;
    (a *= a) %= mod;
    n >>= 1;
  }
  return res % mod;
}
template <class T>
void tomin(T& a, T b) {
  if (b < a) a = b;
}
template <class T>
void tomax(T& a, T b) {
  if (b > a) a = b;
}
}  // namespace _calculate
using namespace _calculate;
namespace _simple_algo {
long long stol(const string& s) {
  long long x = 0;
  for (char c : s) x = x * 10 + c - 48;
  return x;
}
string ltos(long long x) {
  string s = "";
  if (x == 0) return "0";
  while (x) s = char(x % 10 + 48) + s, x /= 10;
  return s;
}
bool pal(const string& s) {
  int l = s.size();
  for (int i = 0, j = l - 1; i < j; i++, j--)
    if (s[i] != s[j]) return 0;
  return 1;
}
}  // namespace _simple_algo
using namespace _simple_algo;
namespace _io {
template <class T>
void rd(T& x) {
  cin >> x;
}
long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void rd(int& x) { x = rd(); }
void rd(long long& x) { x = rd(); }
template <class A, class B>
void rd(A& a, B& b) {
  rd(a), rd(b);
}
template <class A, class B>
void rd(pair<A, B>& p) {
  cin >> p.first >> p.second;
}
template <class T>
void wt(const T& x) {
  cout << x << endl;
}
template <class T>
void wt(const T& x, char c) {
  cout << x << c;
}
template <class T>
void wt(const T& x, const string& s) {
  cout << x << s;
}
template <class T>
void wt(const T& x, int rnd) {
  cout << fixed << setprecision(rnd) << x << endl;
}
template <class T>
void wt(const vector<T>& v) {
  for (T x : v) wt(x, ' ');
  wt("");
}
template <class A, class B>
void wt(const pair<A, B>& make_pair) {
  cout << make_pair.first << ' ' << make_pair.second << endl;
}
}  // namespace _io
using namespace _io;
}  // namespace myland
using namespace myland;
int main() {
  int n = rd();
  switch (n) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 12:
    case 30:
    case 35:
    case 43:
    case 46:
    case 52:
    case 64:
    case 70:
      puts("YES");
      break;
    default:
      puts("NO");
      break;
  }
}
