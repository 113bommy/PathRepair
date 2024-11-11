#include <bits/stdc++.h>
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const long double eps = 1e-9;
const double PI = atan(1) * 4;
template <typename T>
inline int sign(const T &a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
template <typename T>
inline void in(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
long long twop(int x) { return 1LL << x; }
template <typename A, typename B>
inline void in(A &x, B &y) {
  in(x);
  in(y);
}
template <typename A, typename B, typename C>
inline void in(A &x, B &y, C &z) {
  in(x);
  in(y);
  in(z);
}
template <typename A, typename B, typename C, typename D>
inline void in(A &x, B &y, C &z, D &d) {
  in(x);
  in(y);
  in(z);
  in(d);
}
template <class T>
void upd(T &a, T b) {
  a = max(a, b);
}
const int maxn = (1 << 22) + 10;
int cnt[maxn];
int dp[maxn];
void solve() {
  int n;
  in(n);
  memset(dp, -1, sizeof(dp));
  for (long long i = 0; i < n; i++) {
    int c;
    in(c);
    dp[c] = c;
    cnt[i] = c;
  }
  for (long long i = 0; i < 22; i++) {
    for (long long j = 0; j < maxn; j++) {
      if (twop(i) & j) {
        dp[j] = max(dp[j], dp[j ^ twop(i)]);
      }
    }
  }
  const int one = twop(22) - 1;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    printf("%d ", dp[one ^ cnt[i]]);
  }
}
int main() {
  solve();
  return 0;
}
