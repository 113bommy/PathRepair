#include <bits/stdc++.h>
using namespace std;
long long k;
vector<long long> n(15);
vector<vector<long long>> a(15);
vector<map<long long, long long>> m(15);
vector<long long> sum(15);
map<long long, long long> used1;
map<long long, long long> used2;
vector<pair<long long, long long>> ans(15);
map<long long, vector<long long>> g;
map<long long, long long> p;
map<long long, long long> where;
long long needs;
long long start;
long long sa;
vector<vector<pair<long long, pair<long long, long long>>>> cycles;
vector<long long> masks(1 << 15, -1);
long long dp[1 << 15];
pair<long long, long long> par[1 << 15];
void F(long long v) {
  long long i = v;
  vector<pair<long long, pair<long long, long long>>> ans;
  long long mask = 0;
  while (true) {
    if (!where[i]) return;
    ans.push_back({where[i] - 1, {i, where[p[i]]}});
    mask |= 1 << (where[i] - 1);
    if (p[i] == v) break;
    i = p[i];
  }
  cycles.push_back(ans);
  masks[mask] = cycles.size() - 1;
}
void dfs(long long v) {
  used1[v] = 1;
  for (long long i = 0; i < g[v].size(); i++) {
    if (used2[g[v][i]]) continue;
    if (!used1[g[v][i]]) {
      p[g[v][i]] = v;
      dfs(g[v][i]);
    } else {
      p[g[v][i]] = v;
      F(g[v][i]);
    }
  }
  used2[v] = 1;
}
int32_t main() {
  cin >> k;
  long long s = 0;
  vector<long long> st;
  for (long long i = 0; i < k; i++) {
    cin >> n[i];
    a[i].resize(n[i]);
    for (long long j = 0; j < n[i]; j++) {
      cin >> a[i][j];
      sum[i] += a[i][j];
      m[i][a[i][j]] = 1;
      where[a[i][j]] = i + 1;
      st.push_back(a[i][j]);
    }
    s += sum[i];
  }
  if (s % k) {
    cout << "NO";
    return 0;
  }
  needs = s / k;
  for (long long i = 0; i < k; i++) {
    for (long long j = 0; j < n[i]; j++) {
      if (where[a[i][j]] != where[needs - sum[i] + a[i][j]] ||
          a[i][j] == needs - sum[i] + a[i][j])
        g[a[i][j]].push_back(needs - sum[i] + a[i][j]);
    }
  }
  for (long long i = 0; i < st.size(); i++) {
    if (!used1[st[i]]) dfs(st[i]);
  }
  dp[0] = 1;
  for (long long i = 0; i < (1 << k); i++) {
    for (long long j = i;; j = (j - 1) & i) {
      if (masks[i ^ j] != -1 && dp[j]) {
        dp[i] = 1;
        par[i] = {i ^ j, masks[i ^ j]};
      }
      if (j == 0) break;
    }
  }
  if (!dp[(1 << k) - 1]) {
    cout << "NO\n";
    return 0;
  }
  long long i = (1 << k) - 1;
  vector<pair<long long, long long>> ans(k);
  while (i) {
    auto q = par[i];
    i ^= q.first;
    for (long long j = 0; j < cycles[q.second].size(); j++) {
      ans[cycles[q.second][j].first] = {cycles[q.second][j].second.first,
                                        cycles[q.second][j].second.second};
    }
  }
  vector<long long> h(15);
  for (long long i = 0; i < k; i++) {
    h[ans[i].second]++;
    if (ans[i].second == 2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (long long i = 0; i < k; i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}
