#include <bits/stdc++.h>
using namespace std;
const int memI = 0x3f3f3f3f;
const long long memLL = 0x3f3f3f3f3f3f3f3fLL;
const int infI = 0x7f7f7f7f;
const long long infLL = 0x7f7f7f7f7f7f7f7fLL;
template <typename T>
inline bool mvMax(T &a, const T &b) {
  return ((a = max(a, b)) == b);
}
template <typename T>
inline bool mvMin(T &a, const T &b) {
  return ((a = min(a, b)) == b);
}
template <typename T>
inline T intPow(T b, T exp) {
  T ret = 1, tmp = b;
  for (; exp; exp /= 2) {
    if (exp % 2) ret *= tmp;
    tmp *= tmp;
  }
  return ret;
}
template <typename T>
inline T intPow(T b, T exp, T mod) {
  T ret = 1, tmp = b % mod;
  for (; exp; exp /= 2) {
    if (exp % 2) (ret *= tmp) %= mod;
    (tmp *= tmp) %= mod;
  }
  return ret;
}
template <typename T>
inline void uniq(T &C) {
  sort(C.begin(), C.end());
  C.resize(unique(C.begin, C.end()) - C.begin());
}
const int maxN = 200010;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  static char s[maxN];
  scanf("%s", s);
  static char g[26];
  for (auto i = (0); i < (26); ++i) {
    g[i] = 'a' + i;
  }
  for (auto _ = (m); _ > 0; --_) {
    char c1, c2;
    while (!islower(c1 = getchar()))
      ;
    while (!islower(c2 = getchar()))
      ;
    for (auto i = (0); i < (26); ++i) {
      if (g[i] == c1) {
        g[i] = c2;
      } else if (g[i] == c2) {
        g[i] = c1;
      }
    }
  }
  for (auto i = (0); i < (n); ++i) {
    s[i] = g[s[i] - 'a'];
  }
  puts(s);
  return 0;
}
