#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int par[1];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void join(int x, int y) { par[find(x)] = y; }
long long mod_expo(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (!a) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
const int N = 1005;
long long c[N][N], b[N], a[N];
char s[N];
map<long long, int> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  int i, j, k;
  cin >> m >> n;
  for (i = 0; i < n; ++i) {
    cin >> s;
    for (j = 0; j < m; ++j) {
      a[j] |= ((s[j] - '0') << i);
    }
  }
  for (i = 0; i < m; ++i) {
    ++mp[a[i]];
  }
  for (i = 0; i <= m; ++i) {
    c[i][0] = 1;
  }
  for (i = 1; i <= m; ++i) {
    for (j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
  b[0] = 1;
  for (i = 1; i <= m; ++i) {
    for (j = 0; j < i; ++j) {
      b[i] = (b[i] + b[j] * c[i - 1][j]) % MOD;
    }
  }
  long long ans = 1;
  for (pair<long long, long long> x : mp) {
    ans = (ans * b[x.second]) % MOD;
  }
  cout << ans << "\n";
  return 0;
}
