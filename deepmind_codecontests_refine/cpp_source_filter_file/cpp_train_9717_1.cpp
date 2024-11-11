#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
int a, b, c, d, i, j, n, m, k;
const int MAXN = 100003;
vector<int> g[MAXN], nm[MAXN], sm[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
bool bad[100003];
int num[100003];
vector<pair<int, int> > quer[100003];
int ans[100003], lca[100003];
int h[100003];
void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) {
        bad[nm[v][i]] = 1;
      }
    }
  }
}
void find_bridges() {
  timer = 0;
  for (int i = 0; i < n; ++i) used[i] = false;
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs(i);
}
void dfs2(int v, int c) {
  if (num[v] != -1) return;
  num[v] = c;
  for (int _n(((int)((g[v]).size())) - 1), i(0); i <= _n; i++) {
    if (bad[nm[v][i]]) continue;
    dfs2(g[v][i], c);
  }
}
int pr[100003];
pair<int, int> ed[100003];
int p(int a) {
  if (pr[a] == -1)
    return a;
  else
    return pr[a] = p(pr[a]);
}
inline void un(int a, int b) { pr[b] = a; }
void dfs3(int v, int pr = -1) {
  used[v] = 1;
  for (int _n(((int)((sm[v]).size())) - 1), i(0); i <= _n; i++) {
    int w = sm[v][i];
    if (w == pr) continue;
    h[w] = h[v] + 1;
    dfs3(w, v);
    un(v, w);
  }
  for (int _n(((int)((quer[v]).size())) - 1), i(0); i <= _n; i++) {
    if (!used[quer[v][i].first]) continue;
    lca[quer[v][i].second] = p(quer[v][i].second);
  }
}
int main() {
  memset(pr, -1, sizeof(pr));
  scanf("%d%d", &n, &m);
  for (int _n((m)-1), i(0); i <= _n; i++) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    nm[a].push_back(i);
    g[b].push_back(a);
    nm[b].push_back(i);
  }
  find_bridges();
  memset(num, -1, sizeof(num));
  c = 0;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    if (num[i] == -1) dfs2(i, c++);
  }
  for (int _n((n)-1), i(0); i <= _n; i++) {
    for (int _n(((int)((g[i]).size())) - 1), j(0); j <= _n; j++) {
      if (num[i] != num[g[i][j]]) sm[num[i]].push_back(num[g[i][j]]);
    }
    sort((sm[i]).begin(), (sm[i]).end());
    sm[i].resize(unique((sm[i]).begin(), (sm[i]).end()) - sm[i].begin());
  }
  memset((used), 0, sizeof(used));
  scanf("%d", &k);
  for (int _n((k)-1), i(0); i <= _n; i++) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    a = num[a];
    b = num[b];
    lca[i] = -1;
    ed[i] = make_pair(a, b);
    if (a == b) continue;
    quer[a].push_back(make_pair(b, i));
    quer[b].push_back(make_pair(a, i));
  }
  dfs3(0);
  for (int _n((k)-1), i(0); i <= _n; i++) {
    if (lca[i] == -1)
      printf("0\n");
    else
      printf("%d\n", h[ed[i].first] + h[ed[i].second] - 2 * h[lca[i]]);
  }
}
