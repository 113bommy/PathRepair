#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 100;
const long long NN = 20 + 10;
const long long inf = 1e15;
long long p[N][NN], h[N], sum[N], ans[N];
pair<long long, long long> dp[N], dp2[N];
vector<pair<long long, long long> > b[N], a[N];
bool pil[N];
void dfs3(long long v, long long p = -1) {
  for (long long i = 0, u, w; i < a[v].size(); i++) {
    u = a[v][i].first;
    if (u != p) {
      dfs3(u, v);
      sum[v] += sum[u];
    }
  }
}
void dfs2(long long v, long long par = -1, long long c = 0) {
  if (par != -1) {
    if (pil[par]) dp2[v] = make_pair(c, par);
    if (dp2[par].first + c > dp2[v].first) {
      dp2[v] = make_pair(dp2[par].first + c, dp2[par].second);
    }
    pair<long long, long long> x, y;
    x = b[par][0];
    y = b[par][1];
    if (x.second == dp[v].second) x = b[par][2];
    if (y.second == dp[v].second) y = b[par][2];
    if (x < y) swap(x, y);
    if (x.first + c > dp2[v].first) {
      dp2[v] = make_pair(x.first + c, x.second);
      if (x.first == y.first) dp2[v].second = par;
    } else if (x.first + c == dp2[v].first) {
      dp2[v].second = par;
    }
  }
  for (long long i = 0; i < a[v].size(); i++) {
    if (a[v][i].first != par) {
      dfs2(a[v][i].first, v, a[v][i].second);
    }
  }
}
void dfs(long long v, long long par = -1) {
  b[v].push_back(make_pair(-2 * inf, v));
  b[v].push_back(make_pair(-2 * inf, v));
  p[v][0] = par;
  for (long long i = 1; i < NN; i++) {
    if (p[v][i - 1] != -1) p[v][i] = p[p[v][i - 1]][i - 1];
  }
  for (long long i = 0, u, w; i < a[v].size(); i++) {
    u = a[v][i].first;
    w = a[v][i].second;
    if (u != par) {
      h[u] = h[v] + 1;
      dfs(u, v);
      if (dp[v].first < dp[u].first + w) {
        dp[v].first = dp[u].first + w;
        dp[v].second = dp[u].second;
      } else if (dp[u].first + w == dp[v].first) {
        dp[v].second = v;
      }
      b[v].push_back(make_pair(dp[u].first + w, dp[u].second));
    }
  }
  sort(b[v].begin(), b[v].end(), greater<pair<long long, long long> >());
}
long long getp(long long v, long long k) {
  for (long long i = 0; i < NN; i++)
    if ((k & (1 << i)) != 0) v = p[v][i];
  return v;
}
long long lca(long long u, long long v) {
  if (h[u] > h[v]) swap(u, v);
  v = getp(v, h[v] - h[u]);
  if (u == v) return u;
  for (long long i = NN - 1; i >= 0; i--) {
    if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
  }
  return p[u][0];
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0, x; i < m; i++) {
    cin >> x;
    x--;
    pil[x] = true;
  }
  for (long long i = 0, u, v, w; i < n - 1; i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    a[u].push_back(make_pair(v, w));
    a[v].push_back(make_pair(u, w));
  }
  for (long long i = 0; i < n; i++) {
    dp[i] = dp2[i] = make_pair(-inf, i);
    if (pil[i]) dp[i].first = dp2[i].first = 0;
  }
  dfs(0);
  dfs2(0);
  for (long long i = 0; i < n; i++) {
    pair<long long, long long> k = max(dp[i], dp2[i]);
    if (dp[i].first == dp2[i].first)
      ans[i] = i;
    else
      ans[i] = k.second;
    if (k.first <= 0) ans[i] = -1;
    if (ans[i] == -1 || !pil[i]) continue;
    long long s = lca(ans[i], i);
    sum[s]--;
    sum[ans[i]]++;
    sum[i]++;
    s = p[s][0];
    if (s != -1) sum[s]--;
  }
  dfs3(0);
  pair<long long, long long> maxi = make_pair(0, 0);
  for (long long i = 0; i < n; i++) {
    if (pil[i]) continue;
    if (sum[i] == maxi.first)
      maxi.second++;
    else if (sum[i] > maxi.first)
      maxi = make_pair(sum[i], 1);
  }
  cout << maxi.first << " " << maxi.second << "\n";
  return 0;
}
