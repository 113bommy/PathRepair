#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ke[100111];
void readGraph() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    ke[u].push_back(v);
    ke[v].push_back(u);
  }
}
int h[100111];
int in[100111];
int out[100111];
int t[100111];
int par[100111][18];
int timer;
void buildLCA(int u, int parent) {
  par[u][0] = parent;
  for (int i = 1; i <= 18 - 1; i++) par[u][i] = par[par[u][i - 1]][i - 1];
}
void dfs1(int u, int parent = 0) {
  h[u] = h[parent] + 1;
  buildLCA(u, parent);
  in[u] = timer;
  t[timer] = u;
  timer++;
  for (int cs = 0; cs <= ke[u].size() - 1; cs++) {
    int v = ke[u][cs];
    if (v == parent) continue;
    dfs1(v, u);
  }
  out[u] = timer;
  if (0 == 1) {
    printf("Node: %2d | in= %2d | out= %2d\n", u, in[u], out[u]);
  }
}
void solve1() {
  h[0] = -1;
  timer = 1;
  dfs1(1);
  h[0] = 0;
  if (0 == 1) {
    for (int i = 1; i <= timer; i++) printf("TIMER[%2d]= %2d\n", i, t[i]);
  }
  in[0] = 0;
  out[0] = timer;
}
int m;
int mid[100111];
bool is_parent(int u, int v) { return in[u] <= in[v] && out[v] <= out[u]; }
int LCA(int u, int v) {
  for (int i = 18 - 1; i >= 0; i--) {
    if (!is_parent(par[u][i], v)) u = par[u][i];
  }
  if (!is_parent(u, v)) u = par[u][0];
  return u;
}
int LCA_Move(int u, int dist) {
  for (int i = 18 - 1; i >= 0; i--) {
    if ((dist & (1 << i)) > 0) u = par[u][i];
  }
  return u;
}
vector<int> u_query[100111];
vector<int> v_query[100111];
void readQuery() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (h[u] > h[v]) swap(u, v);
    int w = LCA(u, v);
    int dist = (h[u] + h[v] - 2 * h[w]) / 2;
    if (h[u] == h[v]) dist--;
    mid[i] = LCA_Move(v, dist);
    u_query[u].push_back(i);
    v_query[v].push_back(i);
    if (0 == 1) {
      printf("U= %2d | V= %2d | W= %2d| mid= %2d\n", u, v, w, mid[i]);
    }
  }
}
int dm[100111 * 4];
int addAll[100111 * 4];
void update(int stt) { dm[stt] = max(dm[2 * stt], dm[2 * stt + 1]); }
void build(int stt, int lo, int ro) {
  if (0 == 1) {
    printf("BUILD: STT= %2d || lo= %2d || ro= %2d\n", stt, lo, ro);
  }
  if (lo == ro) {
    dm[stt] = h[t[lo]];
    addAll[stt] = 0;
    return;
  }
  int co = (lo + ro) / 2;
  build(stt * 2, lo, co);
  build(stt * 2 + 1, co + 1, ro);
  addAll[stt] = 0;
  update(stt);
}
int res[100111];
void initRes() {
  for (int i = 1; i <= m; i++) res[i] = 0;
}
void push(int stt) {
  dm[stt * 2] += addAll[stt];
  addAll[stt * 2] += addAll[stt];
  dm[stt * 2 + 1] += addAll[stt];
  addAll[stt * 2 + 1] += addAll[stt];
  addAll[stt] = 0;
}
int get(int l, int r, int stt = 1, int lo = 1, int ro = n) {
  if (0 == 1) {
    printf("GET: l= %2d | r= %2d | stt= %2d | lo= %2d | ro= %2d\n", l, r, stt,
           lo, ro);
  }
  if (l > r) return 0;
  if (l <= lo && ro <= r) return dm[stt];
  if (l > ro) return 0;
  if (r < lo) return 0;
  push(stt);
  int co = (lo + ro) / 2;
  int valueL = get(l, r, stt * 2, lo, co);
  int valueR = get(l, r, stt * 2 + 1, co + 1, ro);
  return max(valueL, valueR);
}
void put(int l, int r, int value, int stt = 1, int lo = 1, int ro = n) {
  if (0 == 1) {
    printf("PUT: l= %2d | r= %2d | value= %2d | stt= %2d | lo= %2d | ro= %2d\n",
           l, r, value, stt, lo, ro);
  }
  if (l <= lo && ro <= r) {
    dm[stt] += value;
    addAll[stt] += value;
    return;
  }
  if (l > ro) return;
  if (r < lo) return;
  push(stt);
  int co = (lo + ro) / 2;
  put(l, r, value, stt * 2, lo, co);
  put(l, r, value, stt * 2 + 1, co + 1, ro);
  update(stt);
}
void dfs2(int u) {
  if (0 == 1) {
    printf("DFS: U= %2d\n", u);
  }
  for (int i = 0; i <= (int)u_query[u].size() - 1; i++) {
    int id = u_query[u][i];
    res[id] = max(res[id], get(1, in[mid[id]] - 1));
    res[id] = max(res[id], get(out[mid[id]], n));
  }
  for (int i = 0; i <= (int)(v_query[u].size() - 1); i++) {
    int id = v_query[u][i];
    res[id] = max(res[id], get(in[mid[id]], out[mid[id]] - 1));
  }
  for (int i = 0; i <= ke[u].size() - 1; i++) {
    int v = ke[u][i];
    if (h[v] <= h[u]) continue;
    put(1, n, 1);
    put(in[v] + 1, out[v] - 1, -2);
    dfs2(v);
    put(in[v] + 1, out[v] - 1, 2);
    put(1, n, -1);
  }
}
void solve2() {
  initRes();
  build(1, 1, n);
  dfs2(1);
}
void printfResArray() {
  for (int i = 1; i <= m; i++) printf("%d\n", res[i]);
}
int main() {
  if (0 == 1) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  readGraph();
  solve1();
  readQuery();
  solve2();
  printfResArray();
  return 0;
}
