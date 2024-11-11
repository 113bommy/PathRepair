#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 555;
vector<int> G[maxn];
int saveori[maxn];
char str[3];
int son[maxn];
int siz[maxn];
void dfs1(int s, int fa) {
  siz[s] = 1;
  for (int d : G[s]) {
    if (d == fa) continue;
    saveori[d] ^= saveori[s];
    dfs1(d, s);
    if (siz[d] > siz[son[s]]) son[s] = d;
    siz[s] += siz[d];
  }
}
int nowdep;
int nowid;
int flag;
int maxdep[10 * maxn];
int ans[maxn];
void count(int s, int fa, int dep) {
  ans[nowid] = max(ans[nowid], dep + maxdep[saveori[s]] - nowdep * 2);
  for (int i = 0; i <= 'v' - 'a'; i++) {
    int nowv = 1 << i;
    ans[nowid] = max(ans[nowid], dep + maxdep[saveori[s] ^ nowv] - nowdep * 2);
  }
  for (int d : G[s]) {
    if (d == fa) continue;
    count(d, s, dep + 1);
  }
}
void add(int s, int fa, int dep) {
  maxdep[saveori[s]] = max(maxdep[saveori[s]], dep);
  for (int d : G[s]) {
    if (d == fa || d == flag) continue;
    add(d, s, dep + 1);
  }
}
void cclear(int s, int fa, int dep) {
  maxdep[saveori[s]] = -600 / 3;
  for (int d : G[s]) {
    if (d == fa) continue;
    cclear(d, s, dep + 1);
  }
}
void dfs2(int s, int fa, int kep, int dep) {
  for (int d : G[s]) {
    if (d == fa || d == son[s]) continue;
    dfs2(d, s, 0, dep + 1);
    ans[s] = max(ans[s], ans[d]);
  }
  if (son[s]) {
    dfs2(son[s], s, 1, dep + 1);
    ans[s] = max(ans[s], ans[son[s]]);
    flag = son[s];
  }
  nowid = s;
  nowdep = dep;
  maxdep[saveori[s]] = max(maxdep[saveori[s]], dep);
  for (int d : G[s]) {
    if (d == fa || d == son[s]) continue;
    count(d, s, dep + 1);
    add(d, s, dep + 1);
  }
  ans[s] = max(ans[s], maxdep[saveori[s]] - dep);
  for (int i = 0; i <= 'v' - 'a'; i++) {
    int v = 1 << i;
    ans[s] = max(ans[s], maxdep[saveori[s] ^ v] - dep);
  }
  if (!kep) {
    cclear(s, fa, dep);
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int f;
    scanf("%d %s", &f, str);
    saveori[i] = 1 << (str[0] - 'a');
    G[f].push_back(i);
  }
  for (int i = 0; i <= (1 << ('v' - 'a' + 1)); i++) {
    maxdep[i] = -600 / 3;
  }
  dfs1(1, 1);
  dfs2(1, 1, 1, 1);
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
}
signed main() { solve(); }
