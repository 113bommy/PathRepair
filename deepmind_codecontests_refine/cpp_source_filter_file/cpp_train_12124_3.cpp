#include <bits/stdc++.h>
using namespace std;
const int maxm = 2 * (int)1e6 + 100;
const int maxn = (int)1e5 + 10;
vector<int> h[maxm], g[maxn];
int val[maxn], l[maxn], r[maxn], ans[maxn], dep[maxn];
vector<int> prime;
int vis[2000];
int n, q, cnt;
void pre() {
  for (int i = 2; i <= 1555; i++) {
    if (vis[i] == 0) {
      prime.push_back(i);
      for (int j = i * i; j <= 1555; j += i) vis[j] = 1;
    }
  }
}
int findx(int val) {
  if (h[val].size()) return h[val][h[val].size() - 1];
  return 0;
}
void insertVal(int x, int v) { h[x].push_back(v); }
void deleteVal(int x) {
  if (h[x].size()) h[x].pop_back();
}
void dfs(int u, int pos, bool all, int nod, int fa) {
  ans[u] = 0;
  int tmp = val[u];
  for (int i = 0; i < prime.size() && prime[i] * prime[i] <= tmp; i++) {
    if (tmp % prime[i] == 0) {
      int v = findx(prime[i]);
      if (dep[ans[u]] < dep[v]) ans[u] = v;
      insertVal(prime[i], u);
      while (tmp % prime[i] == 0) tmp /= prime[i];
    }
  }
  if (tmp > 1) {
    int v = findx(tmp);
    if (dep[ans[u]] < dep[v]) ans[u] = v;
    insertVal(tmp, u);
  }
  if (nod == 0) l[u] = ++cnt;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == fa) continue;
    if (nod == 0) dep[v] = dep[u] + 1;
    if (all || nod == u || l[v] <= pos && pos >= r[v])
      dfs(v, pos, all || nod == u, nod, u);
  }
  if (nod == 0) r[u] = cnt;
  tmp = val[u];
  for (int i = 0; i < prime.size() && prime[i] * prime[i] <= tmp; i++) {
    if (tmp % prime[i] == 0) {
      deleteVal(prime[i]);
      while (tmp % prime[i] == 0) tmp /= prime[i];
    }
  }
  if (tmp > 1) {
    deleteVal(tmp);
  }
}
int main() {
  pre();
  dep[1] = 1;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1, 1, 0, 1);
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int v;
      scanf("%d", &v);
      cout << (ans[v] ? ans[v] : -1) << endl;
    } else {
      int u, v;
      scanf("%d%d", &u, &v);
      val[u] = v;
      dfs(1, l[u], 0, u, 1);
    }
  }
  return 0;
}
