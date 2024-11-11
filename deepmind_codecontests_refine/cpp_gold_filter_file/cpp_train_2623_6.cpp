#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, MOD = 1e9 + 7;
double s[N], f[N], S, F, prob_down[N], dp_down[N], ch[N], ans, dp_up[N],
    prob_up[N], sum_down[N];
int n;
vector<int> g[N];
void dfs_down(int v, int p) {
  for (int u : g[v])
    if (u != p) {
      dfs_down(u, v);
      ch[v] += ch[u] + 1;
      prob_down[v] += prob_down[u];
    }
  prob_down[v] += s[v];
  for (int u : g[v])
    if (u != p) {
      dp_down[v] += dp_down[u] + prob_down[u];
      dp_down[v] += s[u] * ch[u];
      sum_down[v] += dp_down[u] + prob_down[u];
      sum_down[v] += s[u] * ch[u];
      dp_down[v] += prob_down[u] * (ch[v] - ch[u] - 1);
    }
  ans += sum_down[v] * f[v];
}
void dfs_up(int v, int p) {
  double P = 0;
  prob_up[v] += s[v];
  for (int u : g[v])
    if (u != p) {
      prob_up[u] += prob_up[v];
      dp_up[u] += dp_up[v] + prob_up[v];
      dp_up[u] += (prob_up[v] - s[v]) * (ch[v] - ch[u] - 1);
      dp_up[u] += s[v] * (n - ch[u] - 2);
      P += prob_down[u];
    }
  for (int u : g[v])
    if (u != p) {
      dp_up[u] += (P - prob_down[u]);
      dp_up[u] += dp_down[v] - dp_down[u] - prob_down[u] - s[u] * ch[u] -
                  prob_down[u] * (ch[v] - ch[u] - 1);
      dp_up[u] -= (P - prob_down[u]) * (ch[u] + 1);
      dp_up[u] += (P - prob_down[u]) * (n - ch[v] - 1);
      prob_up[u] += (P - prob_down[u]);
    }
  for (int u : g[v])
    if (u != p) dfs_up(u, v);
  ans += dp_up[v] * f[v];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int u, v;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &s[i], &f[i]);
    S += s[i];
    F += f[i];
  }
  for (int i = 0; i < n; i++) {
    s[i] = s[i] / S;
    f[i] = f[i] / F;
  }
  dfs_down(0, 0);
  dfs_up(0, 0);
  printf("%.20f\n", ans);
  return 0;
}
