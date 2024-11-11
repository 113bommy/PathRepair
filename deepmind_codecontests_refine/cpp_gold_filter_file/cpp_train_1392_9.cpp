#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, q, k;
string s;
map<string, int> rec;
int tots;
set<int> num[MAXN];
map<int, int> cnt_n[MAXN];
int a[MAXN];
int lsh[MAXN];
vector<int> g[MAXN];
int x, y;
struct Query {
  int k, op;
  int x;
};
vector<Query> quest[MAXN];
int sum;
int maxi;
int Maxstep;
int deep[MAXN];
int root[MAXN];
int cnt_root;
int wson[MAXN];
int size[MAXN];
int dp[MAXN][35];
int cnt = 0;
void dfs1(int x, int fa) {
  size[x] = 1;
  int maxi = 0;
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v == fa) {
      continue;
    }
    deep[v] = deep[x] + 1;
    dp[v][0] = x;
    for (int j = 1; j <= Maxstep; j++) {
      dp[v][j] = dp[dp[v][j - 1]][j - 1];
    }
    dfs1(v, x);
    size[x] += size[v];
    if (maxi < size[v]) {
      wson[x] = v;
      maxi = size[v];
    }
  }
}
int ans[MAXN];
void add(int x, int f, int son, int dep) {
  num[dep].insert(a[x]);
  cnt_n[dep][a[x]]++;
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v == f || v == son) {
      continue;
    }
    add(v, x, son, dep + 1);
  }
}
void detel(int x, int f, int son, int dep) {
  cnt_n[dep][a[x]]--;
  if (cnt_n[dep][a[x]] == 0) {
    num[dep].erase(a[x]);
  }
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v == f || v == son) {
      continue;
    }
    detel(v, x, son, dep + 1);
  }
}
void dfs(int x, int f, int check) {
  for (int i = 0; i < g[x].size(); i++) {
    int v = g[x][i];
    if (v == f || v == wson[x]) {
      continue;
    }
    dfs(v, x, 0);
  }
  if (wson[x]) {
    dfs(wson[x], x, 1);
  }
  add(x, f, wson[x], deep[x]);
  for (int i = 0; i < quest[x].size(); i++) {
    ans[quest[x][i].op] = num[deep[x] + quest[x][i].k].size();
  }
  if (!check) {
    detel(x, f, 0, deep[x]);
  }
}
int h;
signed main() {
  scanf("%d", &n);
  Maxstep = int(log(n) / log(2)) + 1;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (!rec[s]) {
      rec[s] = ++cnt;
    }
    a[i] = rec[s];
    scanf("%d", &x);
    if (x) {
      g[x].push_back(i);
    } else {
      root[++cnt_root] = i;
    }
  }
  for (int i = 1; i <= cnt_root; i++) {
    deep[root[i]] = 1;
    dfs1(root[i], 0);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d", &x, &k);
    Query mss;
    mss.k = k;
    mss.op = i;
    quest[x].push_back(mss);
  }
  for (int i = 1; i <= cnt_root; i++) {
    dfs(root[i], 0, 0);
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
}
