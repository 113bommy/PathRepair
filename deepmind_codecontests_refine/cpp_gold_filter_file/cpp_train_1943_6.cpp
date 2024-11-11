#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long read() {
  long long sum = 0, f = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') ch = getchar(), f = -1;
  while (ch <= '9' && ch >= '0') {
    sum = sum * 10 + ch - '0';
    ch = getchar();
  }
  return sum * f;
}
long long n, k;
long long st[1010];
long long f[1010][1010][2];
long long num;
void re() {
  num = 0;
  char ch = getchar();
  while ((ch < '0' || ch > '9')) ch = getchar();
  while (ch <= '9' && ch >= '0') {
    st[++num] = ch - '0';
    ch = getchar();
  }
}
long long dp(long long v, long long limit, long long last, bool flag) {
  if (!limit && f[v][last][flag] != -1) return f[v][last][flag];
  if (!v) return flag;
  long long end = limit ? st[v] : 9;
  long long u = 0;
  for (long long i = 0; i <= end; i++) {
    bool g = false;
    if (flag || (last && (last - v) <= k)) g = true;
    if (i == 4)
      u = (u + dp(v - 1, limit && st[v] == 4, v, g)) % mod;
    else if (i == 7)
      u = (u + dp(v - 1, limit && st[v] == 7, v, g)) % mod;
    else
      u = (u + dp(v - 1, limit && i == end, last, flag)) % mod;
  }
  if (!limit) f[v][last][flag] = u;
  return u;
}
long long g[1010];
long long solve() {
  re();
  for (long long i = 1; i <= num; i++) g[i] = st[num - i + 1];
  for (long long i = 1; i <= num; i++) st[i] = g[i];
  return dp(num, 1, 0, 0);
}
signed main() {
  memset(f, -1, sizeof(f));
  n = read(), k = read();
  for (long long i = 1; i <= n; i++) {
    long long L = solve();
    long long last = 0;
    long long g = 0;
    for (long long j = num; j >= 1; j--)
      if (st[j] == 4 || st[j] == 7) {
        if (last && last - j <= k) {
          g = 1;
          break;
        }
        last = j;
      }
    L -= g;
    long long R = solve();
    cout << (R - L + mod + mod) % mod << '\n';
  }
  return 0;
}
