#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int n, q;
int f[MAXN];
vector<pair<pair<int, int>, int> > roads, queries;
vector<int> co;
map<int, int> comp;
vector<int> edges[MAXN];
int depth[MAXN];
int parent[MAXN][20];
int chain[MAXN];
int num[MAXN];
int sub[MAXN];
int cnt = 0;
void init(int node = 1, int p = 0) {
  parent[node][0] = p, depth[node] = depth[p] + 1;
  sub[node] = 1;
  for (int g : edges[node]) {
    if (g == p) continue;
    init(g, node);
    sub[node] += sub[g];
  }
}
void hld(int node = 1, int p = 0, int t = 0) {
  num[node] = ++cnt;
  if (t) chain[node] = chain[p];
  for (int g : edges[node]) {
    if (g == p) continue;
    if (sub[g] * 2 > sub[node]) hld(g, node, 1);
  }
  for (int g : edges[node]) {
    if (g == p || sub[g] * 2 > sub[node]) continue;
    hld(g, node, 0);
  }
}
inline void preprocess() {
  for (int g = 1; g <= 19; g++)
    for (int y = 1; y <= n; y++) parent[y][g] = parent[parent[y][g - 1]][g - 1];
}
pair<pair<int, int>, int> block[4 * MAXN];
void update(int start, int end, int i, int node) {
  if (start > i || end < i) return;
  if (start == end) {
    block[node] = pair<pair<int, int>, int>(pair<int, int>(1, 1), f[1]);
    return;
  }
  update(start, (start + end) / 2, i, 2 * node);
  update((start + end) / 2 + 1, end, i, 2 * node + 1);
  int sz1 = ((start + end) / 2) - start + 1,
      sz2 = (end - ((start + end) / 2 + 1) + 1);
  pair<pair<int, int>, int> l = block[2 * node], r = block[2 * node + 1];
  block[node].second =
      (l.second + r.second - (f[l.first.second] + f[r.first.first]) +
       f[l.first.second + r.first.first]);
  block[node].first.first =
      ((l.first.first == sz1) ? (sz1 + r.first.first) : (l.first.first));
  block[node].first.second =
      ((r.first.second == sz2) ? (sz2 + l.first.second) : (r.first.second));
}
int intersection(int a, int b, int c, int d) {
  return min(b, d) - max(a, c) + 1;
}
pair<pair<int, int>, int> query(int start, int end, int i, int j, int node) {
  if (start > j || end < i)
    return pair<pair<int, int>, int>(pair<int, int>(-1, -1), -1);
  if (start >= i && end <= j) return block[node];
  pair<pair<int, int>, int> l = query(start, (start + end) / 2, i, j, 2 * node),
                            r = query((start + end) / 2 + 1, end, i, j,
                                      2 * node + 1);
  if (l.first.first == -1) return r;
  if (r.first.first == -1) return l;
  pair<pair<int, int>, int> ret;
  int sz1 = intersection(i, j, start, (start + end) / 2),
      sz2 = intersection(i, j, (start + end) / 2 + 1, end);
  ret.second = (l.second + r.second - (f[l.first.second] + f[r.first.first]) +
                f[l.first.second + r.first.first]);
  ret.first.first =
      ((l.first.first == sz1) ? (sz1 + r.first.first) : (l.first.first));
  ret.first.second =
      ((r.first.second == sz2) ? (sz2 + l.first.second) : (r.first.second));
  return ret;
}
vector<pair<int, int> > processed[MAXN];
vector<pair<int, int> > processqu[MAXN];
int lca(int a, int b) {
  if (a == b) return a;
  if (depth[a] > depth[b]) swap(a, b);
  for (int g = 19; g >= 0; g--) {
    if (depth[parent[b][g]] >= depth[a]) b = parent[b][g];
  }
  if (a == b) return a;
  for (int g = 19; g >= 0; g--) {
    if (parent[b][g] == parent[a][g]) continue;
    b = parent[b][g], a = parent[a][g];
  }
  return parent[a][0];
}
int gp(int node, int x) {
  for (int g = 19; g >= 0; g--) {
    if (x >= (1 << g)) node = parent[node][g], x -= (1 << g);
  }
  return node;
}
int en = 0, ans = 0;
void solvepath(int a, int b) {
  if (depth[a] < depth[b]) return;
  int up;
  if (depth[chain[a]] <= depth[b])
    up = b;
  else
    up = chain[a];
  pair<pair<int, int>, int> x = query(1, cnt, num[up], num[a], 1);
  int tot = depth[a] - depth[up] + 1;
  if (x.first.first == tot) {
    ans -= f[en];
    ans += f[en + tot];
    en += tot;
  } else {
    ans -= f[en];
    ans += f[en + x.first.second];
    ans += x.second - f[x.first.second];
    en = x.first.first;
  }
  solvepath(parent[up][0], b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> q;
  for (int g = 1; g <= n; g++) chain[g] = g;
  for (int g = 1; g <= n - 1; g++) cin >> f[g];
  for (int g = 0; g < n - 1; g++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back(b);
    edges[b].push_back(a);
    roads.push_back(pair<pair<int, int>, int>(pair<int, int>(a, b), c));
    co.push_back(c);
  }
  init();
  preprocess();
  hld();
  for (int g = 0; g < q; g++) {
    int a, b, c;
    cin >> a >> b >> c;
    queries.push_back(pair<pair<int, int>, int>(pair<int, int>(a, b), c));
    co.push_back(c);
  }
  sort(co.begin(), co.end());
  auto x = unique(co.begin(), co.end());
  co.erase(x, co.end());
  for (int g = 0; g < co.size(); g++) comp[co[g]] = g + 1;
  for (int g = 0; g < roads.size(); g++) {
    roads[g].second = comp[roads[g].second];
    processed[roads[g].second].push_back(roads[g].first);
  }
  for (int g = 0; g < queries.size(); g++) {
    queries[g].second = comp[queries[g].second];
    processqu[queries[g].second].push_back(queries[g].first);
  }
  map<pair<pair<int, int>, int>, int> getans;
  for (int g = co.size(); g > 0; g--) {
    for (pair<int, int> x : processed[g]) {
      if (depth[x.first] > depth[x.second]) swap(x.first, x.second);
      update(1, cnt, num[x.second], 1);
    }
    for (pair<int, int> x : processqu[g]) {
      int k = lca(x.first, x.second);
      if (x.first == k) {
        solvepath(x.second, gp(x.second, depth[x.second] - depth[x.first] - 1));
        getans[pair<pair<int, int>, int>(x, g)] = ans;
        ans = 0;
        en = 0;
        continue;
      }
      if (x.second == k) {
        solvepath(x.first, gp(x.first, depth[x.first] - depth[x.second] - 1));
        getans[pair<pair<int, int>, int>(x, g)] = ans;
        ans = 0;
        en = 0;
        continue;
      }
      int ff = gp(x.first, depth[x.first] - depth[k] - 1);
      solvepath(x.first, ff);
      int s1 = en;
      ff = gp(x.second, depth[x.second] - depth[k] - 1);
      en = 0;
      solvepath(x.second, ff);
      int s2 = en;
      ans -= f[s1], ans -= f[s2];
      ans += f[s1 + s2];
      getans[pair<pair<int, int>, int>(x, g)] = ans;
      ans = 0;
      en = 0;
    }
  }
  for (int g = 0; g < queries.size(); g++) cout << getans[queries[g]] << '\n';
  return 0;
}
