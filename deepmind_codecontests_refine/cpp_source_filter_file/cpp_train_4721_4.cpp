#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > cn[100010];
vector<int> lis[100010];
int pt[100010], l[100010], n, k, pp[100010][20], ans[100010], c[100010],
    vis[100010];
void dfslca() {
  int i, j;
  memset(pp, -1, sizeof pp);
  for (i = 0; i < n; i++) pp[i][0] = pt[i];
  for (j = 1; 1 << j < n; j++)
    for (i = 0; i < n; i++) pp[i][j] = pp[pp[i][j - 1]][j - 1];
}
void dfs(int cur, int pi) {
  l[cur] = l[pi] + 1;
  int i;
  for (i = 0; i < (int)cn[cur].size(); i++)
    if (cn[cur][i].first != pi) {
      pt[cn[cur][i].first] = cur;
      lis[cur].push_back(cn[cur][i].first);
      dfs(cn[cur][i].first, cur);
    }
}
int lca(int a, int b) {
  if (l[a] < l[b]) {
    int t = a;
    a = b;
    b = t;
  }
  int i, log;
  for (log = 1; 1 << log <= l[a]; log++)
    ;
  log--;
  for (i = log; i >= 0; i--)
    if (l[a] - (1 << i) >= l[b]) a = pp[a][i];
  if (a == b) return a;
  for (i = log; i >= 0; i--)
    if (pp[a][i] != -1 && pp[a][i] != pp[b][i]) {
      a = pp[a][i];
      b = pp[b][i];
    }
  return pt[a];
}
int ct(int a, int b) {
  int s = 0;
  vis[a] = 1;
  int i;
  for (i = 0; i < (int)cn[a].size(); i++) {
    pair<int, int> t = cn[a][i];
    if (vis[t.first]) continue;
    s += ct(t.first, t.second);
  }
  s += c[a];
  return ans[b] = s;
}
int main() {
  scanf("%d", &n);
  int i;
  for (i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    cn[a].push_back(make_pair(b, i));
    cn[b].push_back(make_pair(a, i));
  }
  memset(ans, 0, sizeof ans);
  memset(c, 0, sizeof c);
  memset(vis, 0, sizeof vis);
  l[1] = 1;
  dfs(1, -1);
  dfslca();
  scanf("%d", &k);
  for (i = 0; i < k; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    int t = lca(a, b);
    c[a]++;
    c[b]++;
    c[t] -= 2;
  }
  ct(1, 0);
  for (i = 1; i < n; i++) printf("%d%c", ans[i], (i == n - 1 ? '\n' : ' '));
  return 0;
}
