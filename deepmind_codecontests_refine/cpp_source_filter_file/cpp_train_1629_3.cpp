#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20);
vector<int> g[maxn];
char s[maxn];
int code[maxn];
int cnt[maxn];
bool mark[maxn];
int bg[maxn];
int sz[maxn];
long long ans[maxn];
long long pushed[maxn];
int sign = 1;
void get_ans(int v, int p, int msk) {
  pushed[v] = 0;
  for (int to : g[v]) {
    if (to == p || mark[to]) continue;
    get_ans(to, v, msk ^ (1 << code[to]));
    pushed[v] += pushed[to];
  }
  for (int i = 0; i < 20; ++i) {
    pushed[v] += cnt[msk ^ (1 << i)] * sign;
  }
  pushed[v] += cnt[msk] * sign;
  ans[v] += pushed[v];
}
void dfs_add(int v, int p, int msk) {
  cnt[msk]++;
  for (int to : g[v]) {
    if (to == p || mark[to]) continue;
    dfs_add(to, v, msk ^ (1 << code[to]));
  }
}
void dfs_del(int v, int p, int msk) {
  cnt[msk]--;
  for (int to : g[v]) {
    if (to == p || mark[to]) continue;
    dfs_del(to, v, msk ^ (1 << code[to]));
  }
}
int get_sz(int v, int p) {
  sz[v] = 1;
  bg[v] = 0;
  for (int to : g[v]) {
    if (to == p || mark[to]) continue;
    sz[v] += get_sz(to, v);
    if (sz[to] > sz[bg[v]]) bg[v] = to;
  }
  return sz[v];
}
void centroid(int v) {
  int sez = get_sz(v, -1);
  int center = v;
  while (2 * sz[bg[center]] > sez) center = bg[center];
  mark[center] = 1;
  dfs_add(center, -1, 1 << code[center]);
  sign = 1;
  long long cur_step_ans = 0;
  for (int to : g[center]) {
    if (mark[to]) continue;
    get_ans(to, center, (1 << code[to]));
    cur_step_ans += pushed[to];
  }
  dfs_del(center, -1, 1 << code[center]);
  sign = -1;
  for (int to : g[center]) {
    if (mark[to]) continue;
    dfs_add(to, center, (1 << code[center]) ^ (1 << code[to]));
    get_ans(to, center, (1 << code[to]));
    cur_step_ans += pushed[to];
    for (int i = 0; i < 20; ++i) cur_step_ans += cnt[(1 << i)];
    cur_step_ans += cnt[0];
    dfs_del(to, center, (1 << code[center]) ^ (1 << code[to]));
  }
  ans[center] += cur_step_ans / 2;
  ans[center]++;
  for (int to : g[center]) {
    if (mark[to]) continue;
    centroid(to);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    code[i] = s[i] - 'a';
  }
  centroid(1);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
}
