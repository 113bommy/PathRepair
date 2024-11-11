#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
long long n, m, t, nn = 0, vis[300010], cnt[300010], dp[300010], extr = 0;
vector<long long> a[300010], g[300010], gg[300010], tmpa[300010], pth;
vector<pair<long long, long long> > v;
set<long long> st;
bool bada[300010], badc[300010];
map<long long, long long> s;
void dfs(long long pos, long long ty) {
  if ((ty == 0 && bada[pos]) || (ty == 1 && badc[pos])) return;
  if (ty == 0) {
    bada[pos] = true;
    for (int i = 0; i < a[pos].size(); ++i) dfs(a[pos][i], 1);
  } else {
    badc[pos] = true;
    for (int i = 0; i < g[pos].size(); ++i) dfs(g[pos][i], 0);
  }
}
bool dfs2(long long node, long long strPos, long long sPos) {
  long long stPos = sPos - strPos;
  if (bada[node]) return false;
  if (vis[node] > -1e18) return vis[node] == stPos;
  vis[node] = stPos;
  pth.push_back(node);
  vector<long long> trans;
  trans.clear();
  for (int i = 0; i < a[node].size(); ++i) {
    if (s.find(stPos + i) != s.end()) {
      if (s[stPos + i] != a[node][i]) return false;
    } else {
      trans.push_back(i);
      s[stPos + i] = a[node][i];
    }
  }
  for (int i = 0; i < trans.size(); ++i) {
    long long val = a[node][trans[i]];
    for (int j = 0; j < g[val].size(); ++j)
      if (!dfs2(g[val][j], gg[val][j], strPos + trans[i])) return false;
  }
  return true;
}
int main() {
  cin >> n >> m >> t;
  long long x, y;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &x);
    for (int j = 0; j < x; ++j) {
      scanf("%lld", &y);
      a[i].push_back(y);
      g[y].push_back(i);
      st.insert(y);
    }
  }
  for (int i = 1; i <= t; ++i)
    if (st.find(i) == st.end()) ++extr;
  for (int i = 0; i < n; ++i)
    if (!bada[i]) {
      st.clear();
      for (int j = 0; j < a[i].size(); ++j) st.insert(a[i][j]);
      if (st.size() < a[i].size())
        for (auto it : st)
          if (!badc[it]) dfs(it, 1);
    }
  for (int i = 0; i < n; ++i)
    if (!bada[i]) tmpa[nn++] = a[i];
  n = nn;
  for (int i = 0; i < n; ++i) a[i] = tmpa[i];
  for (int i = 0; i < t + 5; ++i) g[i].clear();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < a[i].size(); ++j)
      g[a[i][j]].push_back(i), gg[a[i][j]].push_back(j);
  for (int i = 0; i < n + 5; ++i) vis[i] = -1e18, bada[i] = false;
  for (int i = 0; i < n; ++i)
    if (vis[i] == -1e18) {
      s.clear();
      pth.clear();
      bool stat = dfs2(i, 0, 0);
      if (!stat)
        for (int j = 0; j < pth.size(); ++j) bada[pth[j]] = true;
      else
        ++cnt[(s.rbegin()->first) - (s.begin()->first) + 1];
    }
  for (int i = 1; i <= 300005; ++i)
    if (cnt[i] > 0) v.push_back(make_pair(i, cnt[i]));
  dp[0] = 1;
  for (int i = 1; i <= m; ++i) {
    (dp[i] += dp[i - 1] * extr) %= MOD;
    for (int j = 0; j < v.size(); ++j)
      if (i - v[j].first >= 0)
        (dp[i] += dp[i - v[j].first] * v[j].second) %= MOD;
      else
        break;
  }
  cout << dp[m] << endl;
  return 0;
}
