#include <bits/stdc++.h>
using namespace std;
struct LiChaoTree {
  int size;
  vector<pair<long long, long long> > seg;
  vector<long long> x;
  LiChaoTree() {}
  LiChaoTree(int size) {
    this->size = size;
    seg.resize(1 << (size + 1));
    x.resize(1 << size);
  }
  void init() {
    for (int i = 0; i < (1 << (size + 1)); i++) seg[i] = make_pair(0, 1e18);
    for (int i = 0; i < (1 << size); i++) x[i] = i;
  }
  long long calc(pair<long long, long long> f, long long x) {
    return f.first * x + f.second;
  }
  long long query(int i) {
    long long X = x[i], ret = 1e18;
    i += (1 << size);
    while (i >= 1) {
      ret = min(ret, calc(seg[i], X));
      i /= 2;
    }
    return ret;
  }
  void add(int k, int l, int r, pair<long long, long long> f) {
    int m = (l + r) / 2;
    if (calc(f, x[m]) < calc(seg[k], x[m])) swap(seg[k], f);
    bool L = (calc(f, x[l]) < calc(seg[k], x[l])),
         R = (calc(f, x[r]) < calc(seg[k], x[r]));
    if (L == R) return;
    if (L) add(k * 2, l, m, f);
    if (R) add(k * 2 + 1, m + 1, r, f);
  }
  void addSegment(int a, int b, int k, int l, int r,
                  pair<long long, long long> f) {
    if (b < l || r < a) return;
    if (a <= l && r <= b) {
      add(k, l, r, f);
      return;
    }
    addSegment(a, b, k * 2, l, (l + r) / 2, f);
    addSegment(a, b, k * 2 + 1, (l + r) / 2 + 1, r, f);
  }
  void addSegment(int a, int b, long long p, long long q) {
    addSegment(a, b, 1, 0, (1 << size) - 1, make_pair(p, q));
  }
  void addLine(long long p, long long q) {
    return addSegment(0, (1 << size) - 1, p, q);
  }
};
long long n;
long long a[150005];
vector<int> G[200005];
int size[200005];
bool used[200005];
long long depth[200005];
long long len[200005];
long long down[200005], up[200005];
vector<long long> lvec;
LiChaoTree lct;
long long ans;
int sizedfs(int v, int pre) {
  int ret = 1;
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == pre) continue;
    if (used[G[v][i]]) continue;
    ret += sizedfs(G[v][i], v);
  }
  return size[v] = ret;
}
int centdfs(int v, int pre, int sz) {
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == pre) continue;
    if (used[G[v][i]]) continue;
    if (size[G[v][i]] > sz / 2) return centdfs(G[v][i], v, sz);
  }
  return v;
}
void predfs(long long v, long long p, long long d, long long l, long long s) {
  l += a[v];
  depth[v] = d, len[v] = l;
  s += depth[v] * a[v];
  down[v] += s;
  up[v] = (depth[v] + 1) * len[v] - down[v];
  ans = max(ans, up[v]);
  ans = max(ans, down[v] + len[v]);
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == p) continue;
    if (used[G[v][i]]) continue;
    predfs(G[v][i], v, d + 1, l, s);
  }
}
void predfs2(long long v, long long p, long long r) {
  len[v] -= a[r];
  depth[v]++;
  lvec.push_back(len[v]);
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == p) continue;
    if (used[G[v][i]]) continue;
    predfs2(G[v][i], v, r);
  }
}
void adddfs(long long v, long long p) {
  lct.addLine(-depth[v], -up[v]);
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == p) continue;
    if (used[G[v][i]]) continue;
    adddfs(G[v][i], v);
  }
}
void querydfs(long long v, long long p) {
  long long pos = lower_bound(lvec.begin(), lvec.end(), len[v]) - lvec.begin();
  ans = max(ans, -lct.query(pos) + down[v]);
  for (int i = 0; i < G[v].size(); i++) {
    if (G[v][i] == p) continue;
    if (used[G[v][i]]) continue;
    querydfs(G[v][i], v);
  }
}
void solve(int v, int sz) {
  sizedfs(v, -1);
  long long c = size[v];
  v = centdfs(v, -1, sz);
  lvec.clear();
  predfs(v, -1, 0, 0, 0);
  predfs2(v, -1, v);
  long long logc = 0;
  for (; c; c /= 2) logc++;
  lct = LiChaoTree(logc);
  sort(lvec.begin(), lvec.end());
  lvec.erase(unique(lvec.begin(), lvec.end()), lvec.end());
  while (lvec.size() < (1 << logc)) lvec.push_back(lvec.back() + 1);
  lct.init();
  for (int i = 0; i < lct.x.size(); i++) lct.x[i] = lvec[i];
  for (int i = 0; i < G[v].size(); i++) {
    if (used[G[v][i]]) continue;
    querydfs(G[v][i], v);
    adddfs(G[v][i], v);
  }
  lct.init();
  for (int i = 0; i < lct.x.size(); i++) lct.x[i] = lvec[i];
  for (int i = (int)G[v].size() - 1; i >= 0; i--) {
    if (used[G[v][i]]) continue;
    querydfs(G[v][i], v);
    adddfs(G[v][i], v);
  }
  used[v] = true;
  for (int i = 0; i < G[v].size(); i++) {
    if (used[G[v][i]]) continue;
    solve(G[v][i], size[G[v][i]]);
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int u, v;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  solve(1, n);
  cout << ans << endl;
  return 0;
}
