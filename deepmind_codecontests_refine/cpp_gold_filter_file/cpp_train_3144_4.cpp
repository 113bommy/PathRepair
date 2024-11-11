#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7, P2 = 998244353;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n, long long P) {
  long long r = 1 % P;
  for (a %= P; n; a = a * a % P, n >>= 1)
    if (n & 1) r = r * a % P;
  return r;
}
long long inv(long long first) {
  return first <= 1 ? 1 : inv(P % first) * (P - P / first) % P;
}
inline int rd() {
  int first = 0;
  char p = getchar();
  while (p < '0' || p > '9') p = getchar();
  while (p >= '0' && p <= '9') first = first * 10 + p - '0', p = getchar();
  return first;
}
const int N = 1e6 + 50;
const int bas = 1234567, ibas = 989145189;
const int bas2 = 1635947, ibas2 = 184116149;
int n, a[N];
int cnt, s[N], dp[N];
pair<int, int> f[N];
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  cnt = 0;
  int sta1 = 0, sta2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (!cnt)
      sta1 = sta2 = s[++cnt] = a[i];
    else {
      if (a[i] == s[cnt]) {
        sta1 = (sta1 - s[cnt] + P) % P;
        sta1 = (long long)sta1 * ibas % P;
        sta2 = (sta2 - s[cnt] + P2) % P2;
        sta2 = (long long)sta2 * ibas2 % P2;
        --cnt;
      } else {
        sta1 = ((long long)sta1 * bas + a[i]) % P;
        sta2 = ((long long)sta2 * bas2 + a[i]) % P2;
        s[++cnt] = a[i];
      }
    }
    f[i] = pair<int, int>(sta1, sta2);
  }
  long long ans = 0;
  map<pair<int, int>, int> vis;
  vis[{0, 0}] = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis.count(f[i]))
      dp[i] = dp[vis[f[i]]] + 1;
    else
      dp[i] = 0;
    vis[f[i]] = i;
    ans += dp[i];
  }
  printf("%lld\n", ans);
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) work();
}
