#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string get() {
  char ch[1000000];
  scanf("%s", ch);
  return ch;
}
template <class P, class Q>
inline P smin(P &a, Q b) {
  if (b < a) a = b;
  return a;
}
template <class P, class Q>
inline P smax(P &a, Q b) {
  if (a < b) a = b;
  return a;
}
const int MAX_LG = 21;
const long long maxn = 1e6 + 10;
const long long base = 29;
const long long mod = 1e9 + 9;
const long long INF = 1e9;
const long long maxq = 2e5 + 10;
const long long SQ = sqrt(maxn);
long long cnt[maxn], res;
long long dp[maxn], fact[maxn], rev[maxn];
inline long long power(long long a, long long b) {
  if (!b) return 1;
  return power(a * a % mod, b >> 1) * (b % 2 ? a : 1) % mod;
}
inline void ok(long long &a) {
  if (a < 0) a += mod;
  if (a > mod) a -= mod;
}
inline long long C(long long n, long long r) {
  return fact[n] * rev[r] % mod * rev[n - r] % mod;
}
int32_t main() {
  fact[0] = rev[0] = 1;
  for (long long i = 1; i < maxn; i++)
    rev[i] = power(i, mod - 2) * rev[i - 1] % mod,
    fact[i] = fact[i - 1] * i % mod;
  long long n = in();
  cnt[0] = 1, res = 1;
  for (long long i = 1; i <= n; i++)
    cnt[i] = 2 * cnt[i - 1], ok(cnt[i]), res += cnt[i], ok(res);
  for (long long i = n; i < 2 * n; i++) {
    dp[i] = 2 * C(i, n);
    cnt[i + 1] = (dp[i] + (cnt[i] - dp[i]) * 2) % mod;
    res += cnt[i + 1], ok(res);
  }
  cout << res << "\n";
}
