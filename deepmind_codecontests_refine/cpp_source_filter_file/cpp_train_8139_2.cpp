#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1100, mod = 1e9, inf = 1e9 + 7;
int n, m, mn, mx;
bool was[N];
vector<int> vec[N];
long long bin_pow(int x, int y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  if (y % 2 == 0) {
    long long z = bin_pow(x, y / 2);
    return (z * z) % mod;
  }
  return (bin_pow(x, y - 1) * x) % mod;
}
void dfs(int x) {
  was[x] = true;
  mn = min(x, mn);
  mx = max(x, mx);
  for (int i = 0; i < vec[x].size(); i++) {
    if (!was[vec[x][i]]) {
      dfs(vec[x][i]);
    }
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    vec[x].push_back(y);
    vec[y].push_back(x);
  }
  vector<pair<int, int> > p;
  for (int i = 1; i <= n; i++) {
    if (!was[i]) {
      mn = 1e9;
      mx = 0;
      dfs(i);
      p.push_back(make_pair(mn, mx));
    }
  }
  sort(p.begin(), p.end());
  int r = 0, ans = 0;
  for (int i = 0; i < p.size(); i++) {
    if (r > p[i].first) {
      ans++;
    }
    r = p[i].second;
  }
  cout << ans;
  return 0;
}
