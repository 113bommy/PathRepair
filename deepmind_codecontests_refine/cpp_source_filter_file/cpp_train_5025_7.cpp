#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 1e18;
vector<long long> gp[100005];
long long vis[100005];
long long n, a, b, da, db, ans = 0;
long long dfs(long long a, long long val) {
  if (a == b) {
    ans = val;
    return 0;
  }
  if (vis[a] == 1) {
    return 0;
  }
  vis[a] = 1;
  for (auto i : gp[a]) {
    if (vis[i] == 0) {
      dfs(i, val + 1);
    }
  }
  return 0;
}
long long mx[100005], diameter = 0;
long long dfs2(long long i, long long par) {
  mx[i] = 0;
  for (auto j : gp[i]) {
    if (j != par) {
      mx[i] = max(mx[i], dfs2(j, i));
    }
  }
  return mx[i] + 1;
}
long long dfs3(long long i, long long par, long long lvl) {
  vector<long long> ve;
  ve.push_back(lvl);
  ve.push_back(0);
  for (auto j : gp[i]) {
    if (j != par) {
      ve.push_back(mx[j]);
    }
  }
  sort(ve.begin(), ve.end(), greater<long long>());
  diameter = max(diameter, ve[0] + ve[1] + 1);
  for (auto j : gp[i]) {
    if (j != par) {
      dfs3(j, i, lvl + 1);
    }
  }
  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    diameter = 0;
    cin >> n >> a >> b >> da >> db;
    for (long long i = 0; i < n - 1; i++) {
      long long u, v;
      cin >> u >> v;
      gp[u].push_back(v);
      gp[v].push_back(u);
    }
    dfs(a, 0);
    long long dist = ans;
    dfs2(1, 0);
    dfs3(1, 0, 0);
    for (long long i = 0; i < n + 1; i++) {
      gp[i].clear();
      vis[i] = 0;
      mx[i] = 0;
    }
    if (db > 2 * da && dist > da && diameter - 1 > 2 * da) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
  }
  return 0;
}
