#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int MAXN = 1000007;
long long int inv[MAXN];
long long int fact[MAXN];
long long int invfact[MAXN];
long long int mod_pow(long long int a, long long int n) {
  long long int ans = 1;
  while (n) {
    if (n & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return ans;
}
void calc(int m) {
  inv[0] = inv[1] = 1;
  fact[0] = fact[1] = 1;
  invfact[0] = invfact[1] = 1;
  for (int i = 2; i <= m; ++i) {
    inv[i] = (inv[mod % i] * (mod - (mod / i))) % mod;
    fact[i] = (fact[i - 1] * i) % mod;
    invfact[i] = (invfact[i - 1] * inv[i]) % mod;
  }
}
long long int binom(int n, int k) {
  return (1ll * fact[n] * ((invfact[k] * invfact[n - k]) % mod)) % mod;
}
long long int permuta(int n, int k) {
  return (1ll * fact[n] * invfact[n - k]) % mod;
}
long long int cayley(int n, int k) {
  if (n - k - 1 < 0) return (1ll * k * mod_pow(n, mod - 2)) % mod;
  return (1ll * k * mod_pow(n, n - k - 1)) % mod;
}
int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  long long int ans = 0;
  calc(n);
  for (int i = 1; i < n; i++) {
    if (i > m) break;
    long long int cur = 1, cur2 = 1;
    long long int vertex_in_path = permuta(n - 2, i - 1);
    long long int ways_to_form_m = binom(m - 1, i - 1);
    cur = (vertex_in_path * ways_to_form_m) % mod;
    long long int Other_edges = mod_pow(m, n - i - 1);
    long long int Other_trees = cayley(n, i + 1);
    cur2 = (Other_edges * Other_trees) % mod;
    ans = (ans + ((cur * cur2) % mod)) % mod;
  }
  cout << ans << endl;
  return 0;
}
