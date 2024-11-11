#include <bits/stdc++.h>
using namespace std;
int n, ai, bi, p[3005], q[3005];
vector<int> d;
vector<pair<int, int> > g[3005];
int solve(int v, int par) {
  int ret = 0;
  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i].first;
    if (u != par) {
      ret += solve(u, v) + g[v][i].second;
    }
  }
  return ret;
}
int calc1(int v, int par, int cur) {
  int ret = cur;
  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i].first;
    if (u != par) {
      if (g[v][i].second == 0)
        ret = min(ret, calc1(u, v, cur + 1));
      else
        ret = min(ret, calc1(u, v, cur - 1));
    }
  }
  return ret;
}
int calc2(int v, int par) {
  int ret = 0;
  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i].first;
    if (u != par) {
      ret += calc2(u, v) + (1 - g[v][i].second);
    }
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int edge = 0; edge < n - 1; edge++) {
    scanf("%d %d", &ai, &bi);
    g[ai - 1].push_back(make_pair(bi - 1, 0));
    g[bi - 1].push_back(make_pair(ai - 1, 1));
  }
  int Min = n - 1;
  for (int x = 0; x < n; x++) {
    Min = min(Min, solve(x, -1));
  }
  for (int x = 0; x < n; x++)
    if (g[x].size() >= 2) {
      int sum = 0;
      d.clear();
      for (int i = 0; i < g[x].size(); i++) {
        int cur = solve(g[x][i].first, x);
        p[i] = calc1(g[x][i].first, x, cur) + (1 - g[x][i].second);
        q[i] = calc2(g[x][i].first, x) + g[x][i].second;
        sum += q[i];
        d.push_back(p[i] - q[i]);
      }
      sort(d.begin(), d.end());
      sum += d[0];
      sum += d[1];
      Min = min(Min, sum);
    }
  printf("%d\n", Min);
  return 0;
}
