#include <bits/stdc++.h>
using namespace std;
long long modexp(long long a, long long n, long long mod) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = ((ans % mod) * (a % mod)) % mod;
    a = ((a % mod) * (a % mod)) % mod;
    n /= 2;
  }
  return ans % mod;
}
long long vis[100005] = {0}, cnt = 0;
vector<long long> v[100004];
void dfs(long long id) {
  long long i, j, k;
  vis[id] = 1;
  cnt++;
  for (i = 0; i < v[id].size(); i++) {
    if (vis[v[id][i]]) continue;
    dfs(v[id][i]);
  }
  return;
}
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = gcdExtended((b % a), a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modinv(long long a, long long m) {
  long long x, y;
  long long g = gcdExtended(a, m, &x, &y);
  long long res = ((x % m) + m) % m;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j = 1, k, x = 0, y = 0, t, p, h, z, n, m;
  long long mod;
  cin >> n >> m >> mod;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  vector<long long> v1;
  x = 0;
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt = 0;
      x++;
      dfs(i);
      v1.push_back(cnt);
    }
  }
  if (x - 2 >= 0) j = modexp(n, x - 2, mod) % mod;
  for (i = 0; i < v1.size(); i++) {
    j = ((j % mod) * (v1[i] % mod)) % mod;
  }
  if (x == 1 && j > 1) j = 1;
  cout << j << "\n";
  return 0;
}
