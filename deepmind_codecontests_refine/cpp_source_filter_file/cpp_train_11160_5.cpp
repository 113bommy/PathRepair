#include <bits/stdc++.h>
using namespace std;
int MAGIC = 400;
const int mod = 1000000007;
const int MAX = 500005;
int n;
int a[MAX];
int p[MAX];
int fact[MAX];
vector<int> g[MAX];
int canPut[MAX], root[MAX];
vector<pair<int, int> > edges[MAX];
int frst[MAX], lst[MAX];
int find(int u) { return p[u] = u == p[u] ? u : find(p[u]); }
void pzdc() {
  cout << 0;
  exit(0);
}
int tin[MAX], tout[MAX], timer, P[MAX];
void dfs(int u, int p = -1) {
  P[u] = p;
  tin[u] = timer++;
  for (auto v : g[u])
    if (v != u && v != p) dfs(v, u);
  tout[u] = timer - 1;
}
bool isIn(int u, int v) { return tin[v] >= tin[u] && tout[v] <= tout[u]; }
vector<int> getPath(int from, int to) {
  vector<int> v;
  while (!isIn(from, to)) {
    v.push_back(from);
    from = P[from];
  }
  vector<int> v2;
  while (to != from) {
    v2.push_back(to);
    to = P[to];
  }
  v2.push_back(to);
  reverse(v2.begin(), v2.end());
  for (auto first : v2) v.push_back(first);
  return v;
}
void upd(int &a, int b) {
  if (a == -1 || a == b)
    a = b;
  else
    pzdc();
}
void merge(int u, int v, int de) {
  int U = find(u), V = find(v);
  if (U == V) pzdc();
  p[V] = U;
  if (v == frst[de] || u == lst[de]) pzdc();
  if (root[u] == false) pzdc();
  if (canPut[v] == false) pzdc();
  root[u] = false;
  canPut[v] = false;
}
int main() {
  ios_base::sync_with_stdio(0);
  fact[0] = 1;
  for (int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * (long long)i) % mod;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    if (a[i] == i) pzdc();
  }
  memset(frst, -1, sizeof frst);
  memset(lst, -1, sizeof lst);
  int totLen = 0;
  for (int i = 0; i < n; i++)
    if (a[i] != -1) {
      auto p = getPath(i, a[i]);
      totLen += (int)(p.size()) * 2;
      if (totLen > 2 * n - 2) pzdc();
      for (int i = 0; i < (int)(p.size()) - 2; i++)
        edges[p[i + 1]].push_back({p[i], p[i + 2]});
      upd(frst[p[0]], p[1]);
      upd(lst[p.back()], p[(int)(p.size()) - 2]);
    }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (auto u : g[i]) {
      canPut[u] = root[u] = 1;
      p[u] = u;
    }
    for (auto first : edges[i]) merge(first.first, first.second, i);
    for (auto u : g[i]) cnt += find(u) == u;
    cnt -= lst[i] != -1;
    cnt -= frst[i] != -1;
    cnt += lst[i] != -1 && frst[i] != -1 && find(lst[i]) == find(frst[i]);
    if (cnt > 0 && lst[i] != -1 && frst[i] != -1 &&
        find(lst[i]) == find(frst[i]))
      pzdc();
    ans = (ans * (long long)fact[cnt]) % mod;
  }
  cout << ans;
}
