#include <bits/stdc++.h>
using namespace std;
long long int powerFunction(long long int x, long long int y) {
  long long int res = 1;
  long long int p = 1000000007;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool prime[10000001];
long long int P = 1000000007 - 2;
long long int fact[10000001] = {0};
void sieveFunction(long long int maxLimit) {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (long long int i = 2; maxLimit >= i; i++) {
    if (prime[i]) {
      for (long long int j = 2 * i; maxLimit >= j; j += i) prime[j] = false;
    }
  }
}
void factorialFunction(long long int maxLimit) {
  fact[0] = 1;
  for (long long int i = 1; i <= maxLimit; i++)
    fact[i] = (fact[i - 1] * i) % 1000000007;
  return;
}
long long int nCr(long long int n, long long int r) {
  long long int a = fact[n];
  long long int b = powerFunction(fact[n - r], 1000000007 - 2);
  long long int c = powerFunction(fact[r], 1000000007 - 2);
  return (a * (b % 1000000007 * c % 1000000007) % 1000000007) % 1000000007;
}
vector<long long int> adj[300005];
pair<long long int, long long int> pp[300005];
long long int mii = 3e9 + 5;
long long int ans = 0;
long long int tc = 0;
vector<long long int> a(300005);
vector<long long int> b(300005);
vector<long long int> c(300005);
pair<long long int, long long int> dfs(long long int v, long long int p,
                                       long long int mi) {
  long long int one = 0;
  long long int zero = 0;
  mi = min(mi, a[v]);
  if (b[v] != c[v]) {
    if (b[v] == 1)
      one++;
    else
      zero++;
  }
  for (auto it : adj[v]) {
    if (it != p) {
      pair<long long int, long long int> temp = dfs(it, v, mi);
      zero += temp.first;
      one += temp.second;
    }
  }
  if (one >= 1 && zero >= 1) {
    ans += 2 * min(one, zero) * mi;
    tc -= 2 * min(one, zero);
    long long int te = min(one, zero);
    one -= te;
    zero -= te;
  }
  pp[v] = {zero, one};
  return pp[v];
}
signed main() {
  long long int n;
  cin >> n;
  for (long long int i = 1; i < n + 1; i++) {
    cin >> a[i] >> b[i] >> c[i];
    if (c[i] != b[i]) tc++;
  }
  long long int u, v;
  for (long long int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1, mii);
  if (tc > 0)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
}
