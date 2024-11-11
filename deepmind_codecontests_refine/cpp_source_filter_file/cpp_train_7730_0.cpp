#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int vis[300005], lwn[300005];
vector<int> stk;
int f[300005];
int bln[300005];
int Find(int a) {
  if (bln[a] == a) return a;
  return bln[a] = Find(bln[a]);
}
int t;
void dfs(int a, int p) {
  stk.push_back(a);
  bln[a] = a;
  vis[a] = lwn[a] = ++t;
  int cnt = 0;
  for (int i = 0; i < v[a].size(); i++) {
    int first = v[a][i];
    if (first != p || cnt == 1) {
      if (vis[first] == 0) {
        dfs(first, a);
        if (lwn[first] > vis[a]) {
          int fa = Find(first);
          f[first] = Find(a);
          while (stk.back() != first) {
            bln[stk.back()] = fa;
            stk.pop_back();
          }
          bln[stk.back()] = fa;
          stk.pop_back();
        }
        lwn[a] = min(lwn[a], lwn[first]);
      } else {
        lwn[a] = min(lwn[a], vis[first]);
      }
    } else {
      cnt++;
    }
  }
}
int c[300005];
int w[300005];
vector<pair<int, int> > v2[300005];
long long val[300005];
long long dp[300005];
int need[300005];
int ori[300005];
int k;
void dfs2(int first, int f) {
  dp[first] = val[first];
  ori[first] = need[first];
  for (auto it : v2[first]) {
    if (it.first != f) {
      dfs2(it.first, first);
      if (need[it.first] == 0)
        dp[first] += dp[it.first];
      else if (need[first] == k) {
        dp[first] += dp[it.first];
      } else {
        dp[first] += max(dp[it.first] - it.second, 0ll);
      }
    }
  }
  for (auto it : v2[first]) {
    if (it.first != f) {
      need[first] += need[it.first];
    }
  }
}
void dfs3(int first, int f, long long sum, long long edgeval) {
  if (need[first] == 0 || need[first] == k)
    dp[first] += sum;
  else
    dp[first] += max(0ll, sum - edgeval);
  for (auto it : v2[first]) {
    if (it.first != f) {
      if (need[it.first] == 0)
        dfs3(it.first, first, dp[first] - dp[it.first], it.second);
      else if (need[it.first] == k) {
        dfs3(it.first, first, dp[first] - dp[it.first], it.second);
      } else {
        dfs3(it.first, first, dp[first] - max(dp[it.first] - it.second, 0ll),
             it.second);
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> mark;
  for (int i = 0; i < k; i++) {
    int first;
    scanf("%d", &first);
    mark.push_back(first);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  v.resize(n + 1);
  for (int i = 0; i < m; i++) {
    scanf("%d", &w[i]);
  }
  pair<int, int> edge[300005];
  for (int i = 0; i < m; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    v[first].push_back(second);
    v[second].push_back(first);
    edge[i] = make_pair(first, second);
  }
  dfs(1, 0);
  while (!stk.empty()) {
    bln[Find(stk.back())] = 1;
    stk.pop_back();
  }
  for (int i = 0; i < m; i++) {
    if (Find(edge[i].first) != Find(edge[i].second)) {
      v2[Find(edge[i].first)].push_back(make_pair(Find(edge[i].second), w[i]));
      v2[Find(edge[i].second)].push_back(make_pair(Find(edge[i].first), w[i]));
    }
  }
  for (int i = 1; i <= n; i++) {
    val[Find(i)] += c[i];
  }
  for (auto it : mark) {
    need[Find(it)]++;
  }
  dfs2(1, 0);
  dfs3(1, 0, 0, 0);
  for (int i = 1; i <= n; i++) {
    printf("%lld ", dp[Find(i)]);
  }
  printf("\n");
}
