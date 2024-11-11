#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
int mul(int a, int b) { return 1ll * a * b % P; }
int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 202020;
int n, m;
int ans[N], belong[N], st[N], vis[N];
vector<pair<int, int> > v[N], g[N];
int F;
int ne[N], ele[N];
bool used[N];
vector<int> q;
void dfs(int u) {
  if (st[u]) F = u;
  vis[u] = 1;
  for (auto v : g[u])
    if (!vis[v.first]) dfs(v.first);
}
void dfs2(int u) {
  if (F) return;
  vis[u] = 2;
  for (auto v : g[u])
    if (ans[v.second] == -1 && !used[v.second]) {
      if (F) return;
      ne[u] = v.first, ele[u] = v.second;
      used[v.second] = 1;
      if (vis[v.first] == 2) {
        F = v.first;
        return;
      }
      dfs2(v.first);
    }
}
bool find(int u) {
  F = 0;
  dfs(u);
  if (F) {
    q.clear();
    q.push_back(u);
    return 1;
  }
  F = 0;
  dfs2(u);
  if (!F) return 0;
  for (int u = F; vis[u] == 2; u = ne[u]) {
    q.push_back(u);
    vis[u] = 3;
    ans[ele[u]] = (belong[ele[u]] == ne[u]);
  }
  return 1;
}
void gao() {
  for (int i = (0); i < ((int)q.size()); i++) {
    int u = q[i];
    for (auto v : g[u])
      if (vis[v.first] != 3) {
        vis[v.first] = 3;
        if (ans[v.second] == -1) ans[v.second] = (belong[v.second] == v.first);
        q.push_back(v.first);
      }
  }
}
bool solve() {
  for (int i = (1); i < (n + 1); i++)
    if (!vis[i]) {
      if (!find(i)) return 0;
      gao();
    }
  for (int i = (1); i < (m + 1); i++)
    if (ans[i] == -1) ans[i] = 0;
  return 1;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n >> m;
  fill_n(ans + 1, m, -1);
  for (int i = (1); i < (n + 1); i++) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      v[abs(x)].push_back(make_pair(i, x > 0));
    }
  }
  for (int i = (1); i < (m + 1); i++) {
    if ((int)v[i].size() == 0) {
      ans[i] = 0;
    } else if ((int)v[i].size() == 1) {
      ans[i] = v[i][0].second;
      st[v[i][0].first] = 1;
    } else {
      if (v[i][0].second == v[i][1].second) {
        ans[i] = v[i][0].second;
        st[v[i][0].first] = st[v[i][1].first] = 1;
      } else {
        int st = v[i][0].first, ed = v[i][1].first;
        g[st].push_back(make_pair(ed, i));
        g[ed].push_back(make_pair(st, i));
        belong[i] = v[i][0].second ? st : ed;
      }
    }
  }
  if (solve()) {
    cout << "YES"
         << "\n";
    for (int i = (1); i < (m + 1); i++) cout << ans[i];
    cout << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}
