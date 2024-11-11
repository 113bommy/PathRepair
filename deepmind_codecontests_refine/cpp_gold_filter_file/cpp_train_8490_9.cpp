#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 2e9;
const long long infl = 1e18 + 100000;
long long gcd(long long a, long long b) { return (a == 0 ? b : gcd(b % a, a)); }
long long binpow(long long a, int n) {
  return n == 0 ? 1 : n & 1 ? a * binpow(a, n - 1) : binpow(a * a, n / 2);
}
long long binpowmod(long long a, int n, int m = MOD) {
  return n == 0  ? 1
         : n & 1 ? (a % m) * binpowmod(a % m, n - 1, m) % m
                 : binpowmod(a * a % m, n / 2, m) % m;
}
const int maxn = 2e5 + 10;
vector<int> g[maxn];
bool was[maxn];
long long w[maxn], ch[maxn], last[maxn], ans[maxn], to[maxn];
vector<long long> ds, pt;
void dfs(int v, long long path = 0) {
  was[v] = 1;
  ds.push_back(v);
  pt.push_back(path);
  for (int x : g[v]) {
    if (!was[x]) {
      dfs(x, path + to[x]);
      if (path + to[x] > w[x]) {
        int lst = upper_bound(pt.begin(), pt.end(), path + to[x] - w[x] - 1) -
                  pt.begin();
        last[ds[lst - 1]]--;
      }
      ans[v] += ans[x] + 1;
      last[v] += last[x];
    }
  }
  ds.erase(--ds.end());
  pt.erase(--pt.end());
}
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) cin >> w[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(i + 1);
    to[i + 1] = b;
  }
  dfs(1);
  for (int i = 1; i < n + 1; i++) cout << ans[i] + last[i] << ' ';
  return 0;
}
