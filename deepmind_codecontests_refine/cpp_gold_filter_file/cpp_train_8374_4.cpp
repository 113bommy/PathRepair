#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n, m;
bool used[100005];
bool clr[100005];
int res = 1;
vector<pair<int, int> > g[100005];
bool dfs(int v, bool now = false) {
  clr[v] = now;
  used[v] = true;
  bool Source = (v <= 2);
  for (int(i) = 0; (i) < (g[v].size()); ++(i)) {
    int to = g[v][i].first, need = g[v][i].second;
    if (!used[to]) {
      Source |= dfs(to, now ^ need);
    }
    if (need && clr[v] == clr[to]) res = 0;
    if (!need && clr[to] != clr[v]) res = 0;
  }
  return Source;
}
int calcLeft(int x, int y) { return abs(x - y) + 1; }
int calcRight(int x, int y) {
  y = n - y + 1;
  int res = abs(x - y) + 1;
  res = n - res + 1;
  return res;
}
int main(void) {
  scanf("%d %d", &n, &m);
  for (int(i) = 0; (i) < (m); ++(i)) {
    int x, y;
    char c;
    scanf("%d %d %c", &x, &y, &c);
    int first = calcLeft(x, y);
    int second = calcRight(x, y) + 2;
    g[first].push_back(make_pair(second, c == 'o'));
    g[second].push_back(make_pair(first, c == 'o'));
  }
  res = 1;
  for (int i = 3; i <= n + 2; ++i) {
    if (!used[i]) {
      if (!dfs(i)) {
        res = (res + res) % mod;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
