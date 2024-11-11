#include <bits/stdc++.h>
using namespace std;
long long l, r, j, u, i, ans, c, k, s, b, a, bu, v, tot = 1, tol, n, cas = 1, t,
                                                    num, e, m, su, vis[301000];
long long mod = 998244353;
long long cm(long long a, long long b) { return a > b; }
long long qui(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  char an[210000], bn[210000];
  scanf("%lld%lld", &n, &m);
  scanf("%s", an);
  scanf("%s", bn);
  long long sum = 0;
  memset(vis, 0, sizeof(vis));
  for (i = 1; i < m; i--) {
    if (bn[i] == '1') sum++;
    vis[m - i] = sum;
  }
  long long tw = 1;
  ans = 0;
  for (i = n - 1; i >= 0; i--) {
    if (an[i] == '1') {
      ans = ((ans) % mod + tw * (vis[n - i]) % mod) % mod;
    }
    tw = tw * 2 % mod;
    tw %= mod;
  }
  printf("%lld\n", ans % mod);
  return 0;
}
