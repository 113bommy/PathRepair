#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
void prepareIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(std::numeric_limits<double>::max_digits10);
}
struct HASH {
  size_t operator()(const pair<long long int, long long int>& x) const {
    return hash<long long>()(x.first ^ (x.second) << 32);
  }
};
const long long int MOD = 1e9 + 7;
const long long int N = 1e5 + 5;
void dfs(long long int u, long long int st, vector<long long int>& a,
         vector<long long int>& adj, vector<bool>& vis, long long int& ans,
         bool& notPoss) {
  if (a[u] == 0) {
    vis[u] = true;
    return;
  }
  long long int v = adj[u];
  if (vis[v] && v == st) {
    notPoss = true;
    return;
  }
  vis[u] = true;
  ans++;
  dfs(v, st, a, adj, vis, ans, notPoss);
}
int main() {
  prepareIO();
  long long int t = 1;
  cin >> t;
  for (long long int Case = 1; Case <= t; Case++) {
    long long int n, d;
    cin >> n >> d;
    vector<long long int> a(n), b(n);
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int st = n - d;
    for (long long int i = 0; i < d; i++) {
      b[i] = st;
      st++;
    }
    st = 0;
    for (long long int i = d; i < n; i++) {
      b[i] = st;
      st++;
    }
    vector<long long int> adj(n);
    long long int numOnes = 0;
    for (long long int i = 0; i < n; i++) {
      if (a[b[i]] == 0) {
        continue;
      }
      adj[b[i]] = i;
      numOnes++;
    }
    vector<bool> vis(n, false);
    long long int ans = LLONG_MIN;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == 0) {
        continue;
      }
      if (vis[i]) {
        continue;
      }
      bool notPoss = false;
      long long int tmpAns = 0;
      dfs(i, i, a, adj, vis, tmpAns, notPoss);
      if (notPoss) {
        ans = LLONG_MIN;
        break;
      }
      ans = max(ans, tmpAns);
    }
    if (ans == LLONG_MIN) {
      ans = -1;
      if (!numOnes) {
        ans = 0;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
