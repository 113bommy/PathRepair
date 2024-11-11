#include <bits/stdc++.h>
using namespace std;
int inf = 2e9;
int mod = 1e9 + 7;
long long int linf = 100000000ll * 10000;
const int maxn = 1e6 + 20;
long long int fact[maxn];
inline long long int pw(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
inline long long int comb(int n, int k) {
  if (k > n || k < 0) return 0;
  long long int res = fact[n] * pw(fact[n - k], mod - 2) % mod;
  res = res * pw(fact[k], mod - 2) % mod;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m >> mod;
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  long long int ans = pw(n, m);
  for (int s = 1; s <= n; s++) {
    long long int tmp = pw(m, s) * pw(m - 1, n - s) % mod;
    tmp = tmp * comb(n, s - 1) % mod;
    ans += tmp;
  }
  ans %= mod;
  cout << ans;
  return 0;
}
