#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <typename T>
void chmax(T &x, const T &y) {
  if (x < y) x = y;
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const long long N = 2000 + 10;
const long long mod = 1e9 + 7;
long long n, t, dp[1 << 15][16], sta[1 << 15], ok[1 << 15], ans;
struct node {
  long long t, g;
} a[N];
inline long long work(long long x) {
  long long res = 0;
  for (long long i = 0; i < n; i++)
    if ((1 << i) & x) res += a[i + 1].t;
  if (res == t)
    ok[x] = 1;
  else if (res > t)
    ok[x] = 2;
  return res;
}
signed main() {
  n = read(), t = read();
  for (long long i = 1; i <= n; i++) a[i].t = read(), a[i].g = read();
  for (long long i = 1; i < (1 << n); i++) sta[i] = work(i);
  for (long long i = 0; i < n; i++) dp[1 << i][i + 1] = 1;
  long long all = (1 << n) - 1;
  for (long long st = 0; st <= all; st++) {
    if (ok[st] == 2) continue;
    if (ok[st] == 1) {
      for (long long i = 0; i < n; i++)
        if (st & (1 << i)) (ans += dp[st][i + 1]) %= mod;
      continue;
    }
    for (long long i = 0; i < n; i++)
      if ((1 << i) & st)
        for (long long j = 0; j < n; j++)
          if ((!((1 << j) & st)) && a[i + 1].g != a[j + 1].g) {
            (dp[(1 << j) | st][j + 1] += dp[st][i + 1]) %= mod;
          }
  }
  cout << ans;
  return 0;
  ;
}
