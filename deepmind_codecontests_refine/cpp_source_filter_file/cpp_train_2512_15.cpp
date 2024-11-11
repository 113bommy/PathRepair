#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long mod = 1000000007;
long long fact[1000010];
long long inver[1000010];
long long invfact[1000010];
long long pow(long long x, long long y) {
  if (!y) return 1;
  long long ret = pow(x, y / 2);
  ret = ret * ret % mod;
  if (y % 2) ret = ret * x % mod;
  return ret;
}
long long inv(long long x) { return pow(x, mod - 2); }
void prep() {
  fact[0] = 1;
  invfact[0] = 1;
  for (int i = 1; i <= int(100005); i++) {
    fact[i] = fact[i - 1] * i % mod;
    inver[i] = inv(i);
    invfact[i] = invfact[i - 1] * inver[i] % mod;
  }
}
long long combi(long long p, long long q) {
  if (q > p) return 0;
  long long ret = fact[p];
  ret = ret * invfact[q] % mod;
  ret = ret * invfact[p - q] % mod;
  return ret;
}
long long n, m, a, b;
long long dist[1000010];
void cal() {
  for (int i = 1; i <= int(min(n - 1, m)); i++) {
    if (i == n - 1)
      dist[i] = fact[n - 2];
    else if (i == 1)
      dist[i] = pow(n, n - i - 2) * 2 % mod * combi(n - 2, i - 1) % mod *
                fact[i - 1] % mod;
    else {
      long long c1 = pow(n, n - i - 2) * (n - 2) % mod * combi(n - 3, i - 2) %
                     mod * fact[i - 1] % mod;
      long long c2 = pow(n, n - i - 2) * 2 % mod * combi(n - 2, i - 1) % mod *
                     fact[i - 1] % mod;
      dist[i] = c1 + c2;
    }
  }
}
int main() {
  prep();
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> a >> b;
  cal();
  long long ans = 0;
  for (int i = 1; i <= int(min(m, n - 1)); i++) {
    long long add =
        dist[i] * combi(m - 1, m - i) % mod * pow(m, n - 1 - i) % mod;
    ans = (ans + add) % mod;
  }
  cout << ans << endl;
}
