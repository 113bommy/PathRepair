#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
long long n, pa, pb;
long long f[1010][1010];
bool vis[1010][1010];
long long Min(long long x, long long y) { return x < y ? x : y; }
long long Max(long long x, long long y) { return x > y ? x : y; }
long long R() {
  long long ans = 0, f = 1;
  char c = ' ';
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) ans = ans * 10 + c - '0';
  return ans * f;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
long long Ni(long long a) {
  long long x, y;
  exgcd(a, Mod, x, y);
  return (x + Mod) % Mod;
}
long long dp(long long x, long long y) {
  if (x + y >= n) return (x + y + pa * Ni(pb)) % Mod;
  if (vis[x][y]) return f[x][y];
  vis[x][y] = 1;
  f[x][y] = ((pa * dp(x + 1, y) + pb * dp(x, y + x)) % Mod * Ni(pa + pb)) % Mod;
  return f[x][y];
}
int main() {
  n = R();
  pa = R();
  pb = R();
  printf("%lld\n", dp(1, 0));
  return 0;
}
