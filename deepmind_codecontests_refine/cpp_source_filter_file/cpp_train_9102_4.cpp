#include <bits/stdc++.h>
using namespace std;
const int N = 1e+5;
int p_exp[N], n;
bool vis[N];
int main() {
  scanf("%d", &n);
  memset(p_exp, 0, sizeof(p_exp));
  memset(vis, 0, sizeof(vis));
  for (int i = 2; i * i <= n; i++) {
    if (p_exp[i]) continue;
    for (int j = i * i; j <= n; j += i) {
      p_exp[j] = 1;
    }
  }
  vector<pair<int, int> > ans;
  vector<int> g;
  for (int i = n / 2; i > 1; i--) {
    if (p_exp[i]) continue;
    g.clear();
    for (int j = i; j <= n; j += i) {
      if (vis[j]) continue;
      g.push_back(j);
    }
    if (g.size() & 1) swap(g[1], g[g.size() - 1]);
    for (int j = 0; j < g.size() - 1; j += 2) {
      ans.push_back(make_pair(g[j], g[j + 1]));
      vis[g[j]] = vis[g[j + 1]] = 1;
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
