#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFL = 1e18;
const long long N = 1e5 + 10;
const long long hMod = 239017;
struct node {
  int one, zero;
};
vector<vector<pair<int, int> > > g;
node tree[N * 4], tree2[N * 4];
vector<int> a, name, deep, size_g;
vector<int> a2, name2, deep2, size_g2;
bool met[N * 4];
bool met2[N * 4];
int finish, start, mx = 0, name_kol = 0;
void find_mx(int v, int pr, int k) {
  if (k > mx) {
    finish = v;
    mx = k;
  }
  for (auto next : g[v])
    if (next.first != pr) find_mx(next.first, v, k + 1);
}
void find_diametr() {
  find_mx(1, -1, 0);
  start = finish;
  mx = 0;
  find_mx(start, -1, 0);
}
void dfs(int v, int pr, int k, int sum) {
  name[v] = ++name_kol;
  a[name[v]] = sum % 2;
  deep[name[v]] = k;
  for (auto next : g[v])
    if (next.first != pr) {
      dfs(next.first, v, k + 1, sum + next.second);
      size_g[name[v]] += size_g[name[next.first]];
    }
  size_g[name[v]]++;
}
void dfs2(int v, int pr, int k, int sum) {
  name2[v] = ++name_kol;
  a2[name2[v]] = sum % 2;
  deep2[name2[v]] = k;
  for (auto next : g[v])
    if (next.first != pr) {
      dfs2(next.first, v, k + 1, sum + next.second);
      size_g2[name2[v]] += size_g2[name2[next.first]];
    }
  size_g2[name2[v]]++;
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    if (a[tl] == 0) {
      tree[v].zero = deep[tl];
      tree[v].one = -1;
    } else {
      tree[v].one = deep[tl];
      tree[v].zero = -1;
    }
  } else {
    int mid = (tl + tr) / 2;
    build(v * 2, tl, mid);
    build(v * 2 + 1, mid + 1, tr);
    tree[v].one = max(tree[v * 2].one, tree[v * 2 + 1].one);
    tree[v].zero = max(tree[v * 2].zero, tree[v * 2 + 1].zero);
  }
}
void push(int v, int tl, int tr) {
  if (met[v] == 1 && tl != tr) {
    swap(tree[v * 2].zero, tree[v * 2].one);
    swap(tree[v * 2 + 1].zero, tree[v * 2 + 1].one);
    met[v * 2] = 1;
    met[v * 2 + 1] = 1;
  }
  met[v] = 0;
}
void update(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tl == l && tr == r) {
    met[v] = 1;
    swap(tree[v].one, tree[v].zero);
    push(v, tl, tr);
    return;
  }
  int mid = (tl + tr) / 2;
  if (r <= mid)
    update(v * 2, tl, mid, l, r);
  else if (l > mid)
    update(v * 2 + 1, mid + 1, tr, l, r);
  else {
    update(v * 2, tl, mid, l, mid);
    update(v * 2 + 1, mid + 1, tr, mid + 1, r);
  }
  tree[v].one = max(tree[v * 2].one, tree[v * 2 + 1].one);
  tree[v].zero = max(tree[v * 2].zero, tree[v * 2 + 1].zero);
}
void build2(int v, int tl, int tr) {
  if (tl == tr) {
    if (a2[tl] == 0) {
      tree2[v].zero = deep2[tl];
      tree2[v].one = -1;
    } else {
      tree2[v].one = deep2[tl];
      tree2[v].zero = -1;
    }
  } else {
    int mid = (tl + tr) / 2;
    build2(v * 2, tl, mid);
    build2(v * 2 + 1, mid + 1, tr);
    tree2[v].one = max(tree2[v * 2].one, tree2[v * 2 + 1].one);
    tree2[v].zero = max(tree2[v * 2].zero, tree2[v * 2 + 1].zero);
  }
}
void push2(int v, int tl, int tr) {
  if (met2[v] == 1 && tl != tr) {
    swap(tree2[v * 2].zero, tree2[v * 2].one);
    swap(tree2[v * 2 + 1].zero, tree2[v * 2 + 1].one);
    met2[v * 2] = 1;
    met2[v * 2 + 1] = 1;
  }
  met2[v] = 0;
}
void update2(int v, int tl, int tr, int l, int r) {
  push2(v, tl, tr);
  if (tl == l && tr == r) {
    met2[v] = 1;
    swap(tree2[v].one, tree2[v].zero);
    push2(v, tl, tr);
    return;
  }
  int mid = (tl + tr) / 2;
  if (r <= mid)
    update2(v * 2, tl, mid, l, r);
  else if (l > mid)
    update2(v * 2 + 1, mid + 1, tr, l, r);
  else {
    update2(v * 2, tl, mid, l, mid);
    update2(v * 2 + 1, mid + 1, tr, mid + 1, r);
  }
  tree2[v].one = max(tree2[v * 2].one, tree2[v * 2 + 1].one);
  tree2[v].zero = max(tree2[v * 2].zero, tree2[v * 2 + 1].zero);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  g.resize(n + 1);
  vector<pair<int, int> > road, road2;
  for (int i = 1; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
    road.push_back({x, y});
  }
  find_diametr();
  size_g.resize(n + 1);
  name.resize(n + 1);
  deep.resize(n + 1);
  a.resize(n + 1);
  size_g2.resize(n + 1);
  name2.resize(n + 1);
  deep2.resize(n + 1);
  a2.resize(n + 1);
  dfs(finish, -1, 0, 0);
  name_kol = 0;
  dfs2(start, -1, 0, 0);
  for (int i = 0; i < n - 1; i++) {
    road2.push_back({name2[road[i].first], name2[road[i].second]});
  }
  for (int i = 0; i < n - 1; i++) {
    road[i].first = name[road[i].first];
    road[i].second = name[road[i].second];
  }
  build(1, 1, n);
  build2(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int nom;
    cin >> nom;
    nom--;
    int x = road[nom].first;
    int y = road[nom].second;
    if (deep[x] > deep[y]) swap(x, y);
    update(1, 1, n, y, y + size_g[y] - 1);
    x = road2[nom].first;
    y = road2[nom].second;
    if (deep2[x] > deep2[y]) swap(x, y);
    update2(1, 1, n, y, y + size_g2[y] - 1);
    int ans = max(tree[1].zero, tree2[1].zero);
    cout << ans << "\n";
  }
  return 0;
}
