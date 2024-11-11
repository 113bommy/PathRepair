#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 100005;
const long long mod = 1e9 + 7;
bool vis[2005];
long long f[2005];
long long pow_mod(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return res;
}
long long C(int n, int r) {
  long long res = 1;
  res = res * f[n] % mod;
  res = res * pow_mod(f[r], mod - 2) % mod;
  res = res * pow_mod(f[n - r], mod - 2) % mod;
  return res;
}
int main() {
  f[0] = f[1] = 1;
  for (int i = 2; i <= 2000; i++) f[i] = f[i - 1] * i % mod;
  int x;
  int n;
  cin >> n;
  int all = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x != -1)
      vis[i] = vis[x] = 1;
    else
      all++;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      cnt++;
    }
  long long tot = 0;
  for (int i = 1; i <= cnt; i++) {
    if (i & 1)
      tot = (tot + C(cnt, i) * f[cnt - i] % mod) % mod;
    else
      tot = (tot - C(cnt, i) * f[cnt - i] % mod + mod) % mod;
  }
  cout << (f[all] - tot + mod) % mod << endl;
  return 0;
}
