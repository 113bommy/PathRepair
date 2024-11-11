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
void solve(int test) {
  int h = nxt();
  int w = nxt();
  int first[h][w];
  for (int i = 0; i < (int)(h); ++i)
    for (int j = 0; j < (int)(w); ++j) first[i][j] = nxt();
  long long c1 = 0;
  long long c2 = 0;
  for (int i = 0; i < (int)(w); ++i) c1 += sqr(first[0][i] - first[h - 1][i]);
  for (int i = 0; i < (int)(w); ++i)
    c2 += sqr(first[h / 2][i] - first[h / 2 - 1][i]);
  if (c1 < c2)
    puts("YES");
  else
    puts("NO");
}
int main(int argc, char **argv) {
  int t = nxt();
  int c = 0;
  while (t--) {
    solve(++c);
  }
  return 0;
}
