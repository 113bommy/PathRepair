#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e5 + 20;
long long inf = (long long)1e14;
long long mod1 = (long long)1e9 + 9, p = 151, mod2 = (long long)1e9 + 7;
long long n, m, q, par[MAX], sz[MAX];
vector<long long> nums[MAX];
set<long long> un;
long long get(long long u) {
  if (par[u] == u)
    return u;
  else {
    long long v = get(par[u]);
    par[u] = v;
    return v;
  }
}
void unite(long long a, long long b) {
  a = get(a);
  b = get(b);
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a;
  sz[a] += sz[b];
}
void solve() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  if (q == 0) {
    cout << n + m;
    return;
  }
  for (int i = 0; i < q; i++) {
    long long a, b;
    cin >> a >> b;
    nums[b].push_back(a);
    un.insert(b);
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j < nums[i].size(); j++) {
      unite(nums[i][j], nums[i][j - 1]);
    }
  }
  long long ans = 0;
  set<long long> nums;
  for (int i = 1; i <= n; i++) {
    nums.insert(get(i));
  }
  ans += nums.size() - 1;
  nums.clear();
  for (int i = 1; i <= m; i++) {
    if (un.count(i) == 0) ans++;
  }
  cout << ans;
}
int main() {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ios::sync_with_stdio(0);
  long long q;
  q = 1;
  while (q--) solve();
  return 0;
}
