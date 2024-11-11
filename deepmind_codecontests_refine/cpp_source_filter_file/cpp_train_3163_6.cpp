#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long mod) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long modInverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
long long binomial(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
const long long mod = 1e9 + 7;
const long long N = 1e5 + 9;
void doper() {}
vector<long long> v[N];
long long a[N] = {0};
pair<long long, long long> dfs(long long cur, long long par = -1) {
  pair<long long, long long> ans = {0, 0};
  for (auto i : v[cur]) {
    if (i == par) continue;
    auto res = dfs(i, cur);
    ans.first = max(ans.first, res.first);
    ans.second = max(ans.second, res.second);
  }
  a[cur] += (ans.first - ans.second);
  if (a[cur] < 0)
    ans.first -= a[cur];
  else
    ans.second += a[cur];
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  doper();
  long long n;
  cin >> n;
  long long x, y;
  for (long long i = 1; i < n; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (long long i = 0; i < n; i++) cin >> a[i];
  pair<long long, long long> ans = dfs(1);
  cout << ans.first + ans.second;
}
