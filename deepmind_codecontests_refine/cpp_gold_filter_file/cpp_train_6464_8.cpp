#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > g[100020];
bool us[100020];
double tot = 0;
double cnt[100020];
double t[100020];
double s[100020];
void dfs(int v) {
  t[v] = 0;
  cnt[v] = 1;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int u = g[v][i].first;
    if (!us[u]) {
      t[v] += (g[v][i].second * 2);
      us[u] = 1;
      dfs(u);
      t[v] += t[u];
      cnt[v] += cnt[u];
    }
  }
}
void solve(int v, int comeup, double agg = 0.0) {
  tot += agg;
  vector<pair<pair<double, double>, int> > vp;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int u = g[v][i].first;
    if (!us[u]) {
      us[u] = 1;
      double tt = t[u] + 2.0 * g[v][i].second;
      vp.push_back(make_pair(make_pair(cnt[u] / (tt), tt), u));
    }
  }
  sort(vp.rbegin(), vp.rend());
  double ag = 0.0;
  for (int i = 0; i + (1 - comeup) < (int)vp.size(); ++i) {
    solve(vp[i].second, 1,
          agg + ag + (vp[i].first.second - t[vp[i].second]) / 2.0);
    ag += vp[i].first.second;
  }
  if (!comeup) {
    if (vp.size() > 0) {
      int i = vp.size() - 1;
      solve(vp[i].second, 0,
            agg + ag + (vp[i].first.second - t[vp[i].second]) / 2.0);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b, l;
    scanf("%d %d %d", &a, &b, &l);
    g[a].push_back(make_pair(b, l));
    g[b].push_back(make_pair(a, l));
  }
  memset(us, 0, sizeof(us));
  us[1] = 1;
  dfs(1);
  memset(us, 0, sizeof(us));
  us[1] = 1;
  solve(1, 0);
  printf("%.10lf\n", tot / (n - 1));
  return 0;
}
