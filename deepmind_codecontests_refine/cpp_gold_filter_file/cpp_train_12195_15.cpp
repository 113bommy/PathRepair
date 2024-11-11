#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
const long long mod = 1e9 + 7;
long long power(long long x, long long y) {
  x = x % mod, y = y % (mod - 1);
  long long ans = 1;
  while (y > 0) {
    if (y & 1) {
      ans = (1ll * x * ans) % mod;
    }
    y >>= 1;
    x = (1ll * x * x) % mod;
  }
  return ans;
}
long long add(long long a, long long b) { return (a % mod + b % mod) % mod; }
long long mul(long long a, long long b) { return (a % mod * b % mod) % mod; }
long long n, k;
vector<long long> red(N);
vector<long long> a(N);
vector<long long> blue(N);
long long reds, blues, ans;
vector<long long> adj[N];
void dfs(long long x, long long par) {
  if (a[x] == 1) red[x]++;
  if (a[x] == 2) blue[x]++;
  for (auto i : adj[x]) {
    if (i != par) {
      dfs(i, x);
      red[x] += red[i];
      blue[x] += blue[i];
    }
  }
  if (red[x] == reds and blue[x] == 0) ans++;
  if (red[x] == 0 and blue[x] == blues) ans++;
}
int32_t main() {
  long long n;
  cin >> n;
  a.resize(n + 1);
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 2)
      blues++;
    else if (a[i] == 1)
      reds++;
  }
  for (long long i = 1; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, -1);
  cout << ans;
}
