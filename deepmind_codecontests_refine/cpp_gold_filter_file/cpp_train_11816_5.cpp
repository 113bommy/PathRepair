#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e5 + 10, mod = 1e9 + 7;
long long h, w, n, dp[maxn], f[maxn], first[maxn], res;
pair<int, int> c[maxn];
long long bp(long long a, long long b) {
  if (!b) return 1;
  long long t = bp(a, b / 2);
  t = t * t % mod;
  if (b & 1) t = t * a % mod;
  return t;
}
long long cn(long long a, long long b) {
  return (((f[b] * first[a]) % mod) * first[b - a]) % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> h >> w >> n;
  f[0] = 1;
  for (int i = 1; i < maxn; i++) f[i] = f[i - 1] * i, f[i] %= mod;
  first[maxn - 1] = bp(f[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--)
    first[i] = first[i + 1] * (i + 1), first[i] %= mod;
  for (int i = 0; i < n; i++) cin >> c[i].second >> c[i].first;
  sort(c, c + n);
  for (int i = 0; i < n; i++) {
    long long maj = 0;
    int xi = c[i].first, yi = c[i].second;
    for (int j = 0; j < i; j++) {
      int xj = c[j].first, yj = c[j].second;
      if (xj <= xi && yj <= yi)
        maj = (maj + dp[j] * cn(xi - xj, xi - xj + yi - yj)) % mod;
    }
    dp[i] = cn(xi - 1, xi + yi - 2) - maj;
    res += dp[i] * cn(w - xi, w - xi + h - yi) % mod;
    res %= mod;
  }
  cout << (cn(w - 1, w + h - 2) - res + mod) % mod << endl;
  return 0;
}
