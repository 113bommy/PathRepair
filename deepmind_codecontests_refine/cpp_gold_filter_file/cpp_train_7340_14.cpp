#include <bits/stdc++.h>
using namespace std;
template <class T>
void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void chkmin(T &a, T b) {
  if (a > b) a = b;
}
const int inf = 0x3f3f3f3f;
vector<int> v[100010], qu, w;
int p[100010][20];
int dt[100010], dp[100010], fs[100010], ep[100010];
int n, H, T, q, m;
bool vis[100010];
int tot, head[100010], nxt[100010], to[100010], prv[100010];
bool imp[100010], ok[100010];
void dfs(int k, int pa = 0) {
  p[k][0] = pa;
  dt[k] = ++T;
  dp[k] = dp[pa] + 1;
  for (int i = 1; i <= H; i++) p[k][i] = p[p[k][i - 1]][i - 1];
  for (int i = 0; i < v[k].size(); i++) {
    if (v[k][i] == pa) continue;
    dfs(v[k][i], k);
  }
  fs[k] = ++T;
  return;
}
int lca(int first, int second) {
  if (dp[first] < dp[second]) swap(first, second);
  for (int i = H; i >= 0; i--) {
    if (dp[first] - (1 << i) >= dp[second]) first = p[first][i];
  }
  if (first == second) return first;
  for (int i = H; i >= 0; i--) {
    if (p[first][i] != p[second][i]) first = p[first][i], second = p[second][i];
  }
  return p[first][0];
}
bool cmp(int first, int second) { return dt[first] < dt[second]; }
bool cmp1(int first, int second) { return fs[first] < fs[second]; }
void add_edge(int first, int second) {
  tot++;
  nxt[tot] = head[first], to[tot] = second, head[first] = tot;
  return;
}
int build() {
  sort(qu.begin(), qu.end(), cmp1);
  int sz = qu.size(), first, second;
  for (int i = 0; i < sz; i++) w.push_back(qu[i]), vis[qu[i]] = 1;
  for (int i = 1; i < sz; i++) {
    int first = lca(qu[i], qu[i - 1]);
    if (vis[first]) continue;
    w.push_back(first);
    vis[first] = 1;
  }
  sort(w.begin(), w.end(), cmp);
  sz = w.size();
  first = w[0];
  prv[first] = 0;
  for (int i = 1; i < sz; i++) {
    second = w[i];
    while (fs[second] > fs[first]) first = prv[first];
    add_edge(first, second);
    prv[second] = first;
    first = second;
  }
  return w[0];
}
int calc(int k) {
  int g = 0;
  ep[k] = 0;
  ok[k] = 0;
  for (int i = head[k]; i; i = nxt[i]) {
    calc(to[i]);
    ep[k] += ep[to[i]];
    if (ok[to[i]]) g++;
  }
  if (imp[k]) {
    ok[k] = 1;
    ep[k] += g;
  } else {
    if (g > 1)
      ep[k]++;
    else if (g == 1)
      ok[k] = 1;
  }
  return ep[k];
}
int main() {
  int first, second;
  scanf("%d", &n);
  if (n == 1)
    H = 0;
  else
    H = 32 - __builtin_clz(n - 1);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &first, &second);
    v[first].push_back(second);
    v[second].push_back(first);
  }
  dfs(1);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d", &m);
    qu.clear();
    for (int i = 1; i <= m; i++) {
      scanf("%d", &first);
      imp[first] = 1;
      qu.push_back(first);
    }
    bool flag = 0;
    for (int i = 0; i < qu.size(); i++)
      if (imp[p[qu[i]][0]]) {
        flag = 1;
        break;
      }
    if (flag)
      puts("-1");
    else
      printf("%d\n", calc(build()));
    for (int i = 0; i < qu.size(); i++) imp[qu[i]] = 0;
    for (int i = 0; i < w.size(); i++)
      ok[w[i]] = 0, vis[w[i]] = 0, head[w[i]] = 0;
    w.clear();
    tot = 0;
  }
  return 0;
}
