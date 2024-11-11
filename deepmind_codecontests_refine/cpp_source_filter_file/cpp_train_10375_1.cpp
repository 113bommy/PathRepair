#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, f[N], mx, id, sum, st[N], en[N], cnt, used[2 * N], lz[N], par[N];
vector<int> graph[N];
bool vis[N];
pair<int, int> it[8 * N];
void dfs(int u, int p) {
  for (int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v != p) {
      f[v] = f[u] + 1;
      dfs(v, u);
    }
  }
  if (f[u] > mx) {
    mx = f[u];
    id = u;
  }
}
void bluedfs(int u, int p) {
  st[u] = cnt;
  used[cnt] = u;
  cnt++;
  for (int i = 0; i < graph[u].size(); i++) {
    int v = graph[u][i];
    if (v != p) {
      par[v] = u;
      f[v] = f[u] + 1;
      bluedfs(v, u);
    }
  }
  en[u] = cnt++;
}
void build_tree(int k, int l, int r) {
  if (l == r) {
    it[k].first = f[used[l]];
    it[k].second = used[l];
    return;
  }
  int mid = (l + r) / 2;
  build_tree(k * 2, l, mid);
  build_tree(k * 2 + 1, mid + 1, r);
  it[k] = max(it[k * 2], it[k * 2 + 1]);
}
void lzupdate(int k, int l, int r) {
  it[k].first += lz[k];
  if (l != r) {
    lz[k * 2] += lz[k];
    lz[k * 2 + 1] += lz[k];
  }
  lz[k] = 0;
}
void update(int k, int l, int r, int L, int R) {
  lzupdate(k, l, r);
  if (r < L || R < l || L > R) return;
  if (L <= l && r <= R) {
    it[k].first--;
    if (l != r) {
      lz[k * 2] += -1;
      lz[k * 2 + 1] += -1;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(k * 2, l, mid, L, R);
  update(k * 2 + 1, mid + 1, r, L, R);
  it[k] = max(it[k * 2], it[k * 2 + 1]);
}
pair<int, int> get(int k, int l, int r, int L, int R) {
  lzupdate(k, l, r);
  if (r < L || R < l || L > R) return {-1, -1};
  if (L <= l && r <= R) return {it[k].first, it[k].second};
  int mid = (l + r) / 2;
  pair<int, int> val = {-2, -2};
  pair<int, int> val1 = get(k * 2, l, mid, L, R);
  pair<int, int> val2 = get(k * 2 + 1, mid + 1, r, L, R);
  val = max(val1, val2);
  return val;
}
void run(int u) {
  if (vis[u] == 1) return;
  vis[u] = 1;
  update(1, 1, 2 * n, st[u], en[u]);
  sum++;
  if (par[u] == u) return;
  run(par[u]);
}
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  cout << "1 ";
  cin >> n;
  int u, v;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  f[1] = 1;
  dfs(1, 1);
  cnt = 1;
  par[id] = id;
  f[id] = 1;
  bluedfs(id, id);
  build_tree(1, 1, 2 * n);
  run(id);
  for (int i = 2; i <= n; i++) {
    pair<int, int> val = get(1, 1, 2 * n, 1, 2 * n);
    update(1, 1, 2 * n, st[val.second], en[val.second]);
    run(val.second);
    cout << sum << " ";
  }
}
