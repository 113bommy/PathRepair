#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 88;
const int inf = 1e9 + 88;
const int logn = 22;
const int maxa = 3e6 + 88;
const char sgl[5] = {'a', 'e', 'i', 'o', 'u'};
const char sep = 'a' - 1;
const double eps = 1e-9;
int readint() {
  int cur;
  scanf("%d", &cur);
  return cur;
}
int s[maxn], t[maxn], comp[maxn];
vector<int> order, ans;
vector<int> g[maxn], rg[maxn];
bool used[maxn];
int timer = 0;
void dfs(int v) {
  used[v] = true;
  for (int i = 0; i < g[v].size(); i++)
    if (!used[g[v][i]]) dfs(g[v][i]);
  order.push_back(v);
}
void dfs2(int v) {
  comp[v] = timer;
  for (int i = 0; i < rg[v].size(); i++)
    if (comp[rg[v][i]] == -1) dfs2(rg[v][i]);
}
void solve() {
  int n = readint(), i, j, m = readint();
  int sl = readint();
  for (i = 0; i < sl; i++) {
    s[i] = readint();
    s[i]--;
  }
  for (i = 1; i < n; i++) {
    int l = readint();
    for (j = 0; j < l; j++) {
      t[j] = readint();
      t[j]--;
    }
    int cnt = 0;
    for (j = 0; j < min(sl, l); j++)
      if (t[j] != s[j])
        break;
      else
        cnt++;
    if (cnt == l && cnt < sl) {
      printf("No");
      return;
    }
    if (cnt != sl) {
      if (s[cnt] > t[cnt]) {
        g[t[cnt] + m].push_back(t[cnt]);
        g[s[cnt]].push_back(s[cnt] + m);
      } else {
        g[s[cnt]].push_back(t[cnt]);
        g[t[cnt] + m].push_back(s[cnt] + m);
      }
    }
    for (j = 0; j < l; j++) s[j] = t[j];
    sl = l;
  }
  for (i = 0; i < 2 * m; i++) {
    comp[i] = -1;
    for (j = 0; j < g[i].size(); j++) rg[g[i][j]].push_back(i);
  }
  for (i = 0; i < 2 * m; i++)
    if (!used[i]) dfs(i);
  for (i = 2 * m - 1; i >= 0; i--)
    if (comp[order[i]] == -1) dfs2(order[i]), timer++;
  for (i = 0; i < m; i++)
    if (comp[i] == comp[i + m]) {
      printf("No");
      return;
    }
  printf("Yes\n");
  for (i = 0; i < m; i++)
    if (comp[i] < comp[i + m]) ans.push_back(i + 1);
  printf("%d\n", ans.size());
  for (i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}
int main() {
  solve();
  return 0;
}
