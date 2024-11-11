#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct Vertex {
  int head, dfn, low, c, bc;
  bool isspecial;
} v[N];
struct Edge {
  int to, next, w;
  bool isbright;
} e[2 * N];
int eid;
int num, ccid;
int n, m, k, nk;
int sz[N];
long long dp1[N], dp2[N];
vector<pair<int, int> > G[N];
long long c[N];
bool isspecial[N];
long long ans[N];
void init(int n) {
  const Vertex V = {-1, -1, -1, 0, -1, false};
  for (int i = 0; i < n; i++) v[i] = V;
  eid = num = ccid = 0;
}
void add(int x, int y, int w) {
  e[eid] = {y, v[x].head, w, false};
  v[x].head = eid++;
}
void add2(int x, int y, int w) {
  add(x, y, w);
  add(y, x, w);
}
void tarjan(int x, int in_edge) {
  v[x].dfn = v[x].low = num++;
  for (int i = v[x].head; ~i; i = e[i].next) {
    int y = e[i].to;
    if (v[y].dfn == -1) {
      tarjan(y, i);
      v[x].low = min(v[x].low, v[y].low);
      if (v[y].low > v[x].dfn) {
        e[i].isbright = e[i ^ 1].isbright = true;
      }
    } else if (i != (in_edge ^ 1)) {
      v[x].low = min(v[x].low, v[y].dfn);
    }
  }
}
void getbc(int x) {
  v[x].bc = ccid;
  isspecial[ccid] |= v[x].isspecial;
  c[ccid] += v[x].c;
  for (int i = v[x].head; ~i; i = e[i].next) {
    int y = e[i].to;
    if (v[y].bc != -1 || e[i].isbright) continue;
    getbc(y);
  }
}
void getsz(int x, int f) {
  sz[x] = isspecial[x] ? 1 : 0;
  for (auto [y, w] : G[x]) {
    if (f == y) continue;
    getsz(y, x);
    sz[x] += sz[y];
  }
}
long long dfs(int x, int f) {
  long long res = c[x];
  for (auto [y, w] : G[x]) {
    if (y == f) continue;
    long long dp = dfs(y, x);
    long long add = sz[y] == 0 || sz[y] == nk ? dp : max(0ll, dp - w);
    res += add;
  }
  return dp1[x] = res;
}
void reroot(int x, int f, long long zf, int wf) {
  if (f >= 0) {
    long long add =
        nk - sz[x] == 0 || nk - sz[x] == nk ? zf : max(0ll, zf - wf);
    dp2[x] = dp1[x] + add;
  } else {
    dp2[x] = dp1[x];
  }
  for (auto [y, w] : G[x]) {
    if (y == f) continue;
    long long dp = dp1[y];
    long long add = sz[y] == 0 || sz[y] == nk ? dp : max(0ll, dp - w);
    reroot(y, x, dp2[x] - add, w);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  init(n);
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    --a;
    v[a].isspecial = true;
  }
  for (int i = 0; i < n; i++) cin >> v[i].c;
  vector<int> a(m);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    add2(x, y, a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (v[i].dfn == -1) tarjan(i, -1);
  }
  for (int i = 0; i < n; i++) {
    if (v[i].bc == -1) {
      getbc(i);
      ccid++;
    }
  }
  for (int i = 0; i < ccid; i++) {
    nk += isspecial[i];
  }
  for (int i = 0; i < eid; i += 2) {
    if (!e[i].isbright) continue;
    int x = e[i].to, y = e[i ^ 1].to;
    x = v[x].bc;
    y = v[y].bc;
    G[x].push_back({y, e[i].w});
    G[y].push_back({x, e[i].w});
  }
  getsz(0, -1);
  dfs(0, -1);
  reroot(0, -1, 0, 0);
  for (int i = 0; i < n; i++) {
    cout << dp2[v[i].bc] << ' ';
  }
  cout << endl;
  return 0;
}
