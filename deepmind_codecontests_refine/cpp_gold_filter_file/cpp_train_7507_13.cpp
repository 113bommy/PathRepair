#include <bits/stdc++.h>
using namespace std;
int n, p, s, e, d;
vector<int> g[1001];
int in[1001], dia[1001];
bool vis[1001];
struct t {
  int tank, trap, d;
  t(int tank_, int trap_, int d_) : tank(tank_), trap(trap_), d(d_) {}
  bool operator<(const t &rhs) const { return tank < rhs.tank; }
};
vector<t> ans;
void dfs(int i) {
  if (vis[i]) return;
  vis[i] = true;
  if (g[i].size() == 0) {
    if (s != i) ans.push_back(t(s, i, d));
  }
  for (int j : g[i]) {
    d = min(d, dia[i]);
    dfs(j);
  }
}
int main() {
  scanf("%d %d", &n, &p);
  for (int i = 0; i < p; i++) {
    scanf("%d %d %d", &s, &e, &d);
    g[s].push_back(e);
    in[e]++;
    dia[s] = d;
  }
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0 && !vis[i]) {
      d = INT_MAX;
      s = i;
      dfs(i);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (auto x : ans) printf("%d %d %d\n", x.tank, x.trap, x.d);
}
