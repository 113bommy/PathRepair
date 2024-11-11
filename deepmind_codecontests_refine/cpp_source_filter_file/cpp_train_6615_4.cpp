#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T first, T second) {
  while (second > 0) {
    first %= second;
    swap(first, second);
  }
  return first;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class _T>
inline _T sqr(const _T &first) {
  return first * first;
}
template <class _T>
inline string tostr(const _T &a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795L;
template <typename T>
inline void input(T &a) {
  static int ed;
  a = 0;
  while (!isdigit(ed = getchar()) && ed != '-') {
  }
  char neg = 0;
  if (ed == '-') {
    neg = 1;
    ed = getchar();
  }
  while (isdigit(ed)) {
    a = 10 * a + ed - '0';
    ed = getchar();
  }
  if (neg) a = -a;
}
template <typename T = int>
inline T nxt() {
  T res;
  input(res);
  return res;
}
void myassert(bool v) { assert(v); }
mt19937 generator;
bool check(int v) {
  if (v < 2) return false;
  for (int i = 2; i * i <= v; ++i) {
    if (v % i == 0) {
      return false;
    }
  }
  return true;
}
long long pw(long long a, long long n, long long m) {
  long long res = 1;
  while (n) {
    if (n & 1ll) {
      res = res * a % m;
    }
    a = a * a % m;
    n >>= 1;
  }
  return res;
}
long long inv(long long a, long long p) {
  long long res = 1;
  while (a > 1) {
    res = res * (p - p / a) % p;
    a = p % a;
  }
  return res;
}
long long mod = 1000003;
struct M {
  long long a[101][101];
  M() { memset((a), 0, sizeof(a)); }
  static M E() {
    M res;
    for (int i = 0; i < (int)(101); ++i) res.a[i][i] = 1;
    return res;
  }
  M operator*(const M &r) const {
    M res;
    for (int i = 0; i < (int)(101); ++i)
      for (int j = 0; j < (int)(101); ++j) {
        for (int k = 0; k < (int)(101); ++k) res.a[i][j] += a[i][k] * r.a[k][j];
        res.a[i][j] %= mod;
      }
    return res;
  }
};
M pw(M first, int n) {
  M res = M::E();
  while (n) {
    if (n & 1) {
      res = res * first;
    }
    first = first * first;
    n >>= 1;
  }
  return res;
}
void solve(int test) {
  int n = nxt();
  int h = nxt();
  int w = nxt();
  M t;
  for (int i = 0; i <= w; ++i) {
    for (int j = 0; j <= h; ++j) {
      if (j == 0) {
        t.a[0][i] += 1;
      } else {
        if (i + 1 <= w) {
          t.a[i + 1][i] += 1;
        }
      }
    }
  }
  t = pw(t, n);
  long long ans = 0;
  for (int i = 0; i < (int)(w + 1); ++i) ans += t.a[i][0];
  ans %= mod;
  cout << ans << "\n";
}
int main(int argc, char **argv) {
  int t = 1;
  int c = 0;
  while (t--) {
    solve(++c);
  }
  return 0;
}
