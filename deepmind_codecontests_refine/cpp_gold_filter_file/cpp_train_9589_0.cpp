#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxlog = 20;
int n, LL;
long long SS;
int w[maxn];
int l[maxn];
long long s[maxn];
int pa[maxn][maxlog];
pair<int, long long> val[maxn];
int ans;
vector<int> adj[maxn];
int getP(int u, int k) {
  for (int i = 20; i >= 0; i--) {
    if (k >= (1 << i)) {
      u = pa[u][i];
      k -= (1 << i);
    }
  }
  return u;
}
int findP(int v, int u) {
  int res = -1;
  int le = 0, ri = n;
  while (le <= ri) {
    int m = (le + ri) >> 1;
    int p = getP(u, m);
    int L = l[u] - ((!p) ? 0 : l[pa[p][0]]);
    long long S = s[u] - ((!p) ? 0 : s[pa[p][0]]);
    if (val[v].first + L > LL || val[v].second + S > SS) {
      ri = m - 1;
    } else {
      le = m + 1;
      res = m;
    }
  }
  return res;
}
void dfs(int u, int p) {
  if (~p)
    s[u] = s[p] + w[u];
  else
    s[u] = w[u];
  pa[u][0] = (~p ? p : 0);
  for (int i = (1); i < (20); i++) {
    pa[u][i] = pa[pa[u][i - 1]][i - 1];
  }
  for (auto v : adj[u]) {
    if (v == p) continue;
    l[v] = l[u] + 1;
    dfs(v, u);
  }
  ans++;
  val[u] = make_pair(1, w[u]);
  int cur = -1;
  int found = -1;
  for (auto v : adj[u]) {
    int now = findP(v, u);
    if (now > cur) {
      cur = now;
      found = v;
    }
  }
  if (~found) {
    ans--;
    val[u] = make_pair(val[found].first + 1, val[found].second + w[u]);
    assert(val[u].first <= LL && val[u].second <= SS);
  }
}
int main() {
  cin >> n >> LL >> SS;
  for (int i = (0); i < (n); i++) {
    cin >> w[i];
    if (w[i] > SS) {
      cout << -1;
      return 0;
    }
  }
  for (int i = (0); i < (n - 1); i++) {
    int x;
    cin >> x;
    x--;
    adj[x].push_back(i + 1);
  }
  l[0] = 1;
  dfs(0, -1);
  cout << ans;
  return 0;
}
