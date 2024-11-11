#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long int m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
const long long int mod = 1000000007;
const long long int N = 3e5, M = N;
vector<int> g[N];
long long int a[N];
long long int mpow(long long int base, long long int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long int)result * base) % mod;
    base = ((long long int)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
void ipgraph(long long int n, long long int m) {
  long long int i, u, v;
  while (m--) {
    cin >> u >> v;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
}
int sgn(long long int n) {
  if (n > 0) {
    return 1;
  } else {
    return -1;
  }
}
long long int max_digit(long long int n) {
  long long int lar = 0;
  while (n) {
    long long int r = n % 10;
    lar = max(r, lar);
    n = n / 10;
  }
  return lar;
}
long long int min_digit(long long int n) {
  long long int lar = 9;
  while (n) {
    long long int r = n % 10;
    lar = min(r, lar);
    n = n / 10;
  }
  return lar;
}
int prime(long long int n) {
  for (long long int i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
void dfs(long long int u, long long int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
int per(long long int n) {
  if ((long long int)sqrt(n) == (double)sqrt(n)) {
    return 1;
  }
  return 0;
}
long long int n, k, z;
long long int dp[100005][6];
long long int ok(vector<long long int>& a, long long int i, long long int kk,
                 long long int zz) {
  if (kk == 0 || i >= n || i < 0) return 0;
  if (dp[i][zz] != -1) return dp[i][zz];
  long long int val = 0;
  if (i < n) val = max(val, a[i] + ok(a, i + 1, kk - 1, zz));
  if (i >= 0 && zz > 0) val = max(val, a[i] + ok(a, i - 1, kk - 1, zz - 1));
  return dp[i][zz] = val;
}
void solve() {
  cin >> n >> k >> z;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  long long int x = a[0] + ok(a, 1, k, z);
  cout << x << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
