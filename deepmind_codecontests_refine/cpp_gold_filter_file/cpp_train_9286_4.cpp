#include <bits/stdc++.h>
using namespace std;
double PI = 3.141592653589793238462643383279;
const double EPS = 1e-9;
const long long MOD = 1000000007;
const int inf = 1 << 30;
const long long linf = 1LL << 60;
int n;
vector<vector<int>> e;
vector<int> par, dep;
vector<vector<pair<int, int>>> deps;
vector<vector<int>> hoge;
vector<int> val;
vector<int> ans;
vector<int> ch;
void dfs(int v, int p) {
  dep[v] = 0;
  for (int i = 0; i < (int)e[v].size(); i++) {
    if (e[v][i] == p) continue;
    par[e[v][i]] = v;
    dfs(e[v][i], v);
    dep[v] = max(dep[v], dep[e[v][i]] + 1);
    deps[v].push_back(pair<int, int>(dep[e[v][i]] + 1, e[v][i]));
  }
}
void dfs2(int v) {
  if (v) {
    int p = par[v];
    if (deps[p][0].second == v) {
      if (deps[p].size() == 1)
        deps[v].push_back(pair<int, int>(1, p));
      else
        deps[v].push_back(pair<int, int>(deps[p][1].first + 1, p));
    } else {
      deps[v].push_back(pair<int, int>(deps[p][0].first + 1, p));
    }
    sort(deps[v].begin(), deps[v].end(), greater<pair<int, int>>());
  }
  for (int i = 0; i < (int)e[v].size(); i++) {
    if (e[v][i] == par[v]) continue;
    dfs2(e[v][i]);
  }
}
int main() {
  scanf("%d", &n);
  e.resize(n);
  par.resize(n);
  dep.resize(n);
  deps.resize(n);
  hoge.resize(n);
  val.resize(n);
  ans.resize(2 * n + 1);
  ch.resize(n);
  for (int i = 0; i < (int)n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(0, 0);
  for (int i = 0; i < (int)n; i++)
    sort(deps[i].begin(), deps[i].end(), greater<pair<int, int>>());
  dfs2(0);
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)deps[i].size(); j++) {
      pair<int, int> p = deps[i][j];
      hoge[p.first].push_back(i);
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    for (int h : hoge[i]) {
      ans[2 * i + 1] = max(ans[2 * i + 1], val[h] + 1);
    }
    for (int h : hoge[i]) {
      val[h]++;
      ans[2 * i - 1] = max(ans[2 * i - 1], val[h]);
      ans[2 * i] = max(ans[2 * i], val[h]);
      ans[2 * i] = max(ans[2 * i], val[h] + ch[h] - 2);
      if (h) {
        ch[par[h]] = max(ch[par[h]], val[h]);
        ans[2 * i] = max(ans[2 * i], val[h] + val[par[h]] - 2);
      }
    }
  }
  for (int i = n - 2; i >= 1; i--) ans[i] = max(ans[i], ans[i + 2]);
  ans[1]++;
  for (int i = 1; i <= n; i++) {
    printf("%d ", max(ans[i], 1));
  }
  puts("");
}
