#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const int INF = 2123123123;
const int EPS = 1e-9;
inline int NUM(char c) { return (int)c - 48; }
inline char CHAR(int n) { return (char)(n + 48); }
template <class T>
inline T MAX(T a, T b) {
  if (a > b) return a;
  return b;
}
template <class T>
inline T MIN(T a, T b) {
  if (a < b) return a;
  return b;
}
inline void OPEN(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
long long k, b, n, t, ans;
int main() {
  long long i = 0;
  scanf("%I64d %I64d %I64d %I64d", &k, &b, &n, &t);
  long long x = 1;
  while (x < t) {
    ++i;
    x = x * k + b;
  }
  printf("%I64d\n", MAX(0LL, n - i + 1));
}
