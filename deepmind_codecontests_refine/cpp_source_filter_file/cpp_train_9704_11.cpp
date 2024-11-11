#include <bits/stdc++.h>
using namespace std;
long long mod1 = 1000000007ll;
long long mod2 = 998244353ll;
vector<vector<long long> > v(200001), w(200001);
bool vis[200001];
long long ans1 = 0, ans2 = 0, k;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y) {
  if (y == 0) return 1;
  long long p = power(x, y / 2);
  p = (p * p) % mod1;
  if (y % 2) return (p * x) % mod1;
  return p;
}
long long dfs1(long long in) {
  vis[in] = true;
  long long k = 1;
  for (long long i = 0; i < v[in].size(); i++) {
    if (!vis[v[in][i]]) {
      long long r = dfs1(v[in][i]);
      if (r % 2) ans1 += w[in][i];
      k += r;
    }
  }
  return k;
}
long long dfs2(long long in) {
  vis[in] = true;
  long long x = 1;
  for (long long i = 0; i < v[in].size(); i++) {
    if (!vis[v[in][i]]) {
      long long r = dfs2(v[in][i]);
      ans2 += (w[in][i] * min(2 * k - r, r));
      x += r;
    }
  }
  return x;
}
void solve() {
  cin >> k;
  memset(vis, false, sizeof(vis));
  ans1 = 0;
  ans2 = 0;
  for (long long i = 1; i < 2 * k; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    v[x].push_back(y);
    v[y].push_back(x);
    w[x].push_back(z);
    w[y].push_back(z);
  }
  dfs1(1);
  memset(vis, false, sizeof(vis));
  dfs2(1);
  for (long long i = 1; i < 2 * k; i++) {
    v[i].clear();
    w[i].clear();
  }
  cout << ans1 << " " << ans2 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
