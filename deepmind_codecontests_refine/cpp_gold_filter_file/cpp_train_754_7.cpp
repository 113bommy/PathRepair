#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
const int N = 2 * 5e5 + 5;
int n, m, q;
int par[N], sub[N];
int p[N];
struct edge {
  int l, r, tag = 0;
} elist[N];
vi g[N];
int dp[19][500005];
const int lg = 19;
int position[N];
int in[N], out[N], tym = 0;
int what[N];
void setPar(int u, int dad) {
  dp[0][u] = dad;
  for (int i = 1; i < lg; ++i) {
    dp[i][u] = dp[i - 1][dp[i - 1][u]];
  }
}
void dfs(int u) {
  if (u <= n) {
    in[u] = out[u] = ++tym;
    what[tym] = u;
    position[p[u]] = tym;
  } else {
    in[u] = INT_MAX;
    out[u] = INT_MIN;
    for (int v : g[u]) {
      setPar(v, u);
      dfs(v);
      in[u] = min(in[u], in[v]);
      out[u] = max(out[u], out[v]);
    }
  }
}
int getHighest(int u, int tag) {
  for (int i = lg - 1; i >= 0; --i) {
    if (dp[i][u]) {
      if (elist[dp[i][u] - n].tag >= tag) {
        u = dp[i][u];
      }
    }
  }
  return u;
}
int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
int mx[N];
void build(int u = 1, int b = 1, int e = n) {
  if (b == e) {
    return void(mx[u] = p[what[b]]);
  }
  int mid = (b + e) >> 1;
  build(u << 1, b, mid);
  build(u << 1 | 1, mid + 1, e);
  mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
}
int Max(int l, int r, int u = 1, int b = 1, int e = n) {
  if (l <= b and e <= r) return mx[u];
  if (b > r or e < l) return INT_MIN;
  int mid = (b + e) >> 1;
  return max(Max(l, r, u << 1, b, mid), Max(l, r, u << 1 | 1, mid + 1, e));
}
void makeZero(int pos, int u = 1, int b = 1, int e = n) {
  if (b == e) {
    return void(mx[u] = 0);
  }
  int mid = (b + e) >> 1;
  if (pos <= mid) {
    makeZero(pos, u << 1, b, mid);
  } else {
    makeZero(pos, u << 1 | 1, mid + 1, e);
  }
  mx[u] = max(mx[u << 1], mx[u << 1 | 1]);
}
int main(int argc, char const *argv[]) {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = 1; i < N; ++i) {
    par[i] = i, sub[i] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &elist[i].l, &elist[i].r);
  }
  vector<ii> updates;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    updates.emplace_back(x, y);
    if (x == 2) {
      elist[y].tag = i;
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (!elist[i].tag) {
      elist[i].tag = q + i;
    }
  }
  vi perm(m);
  iota(begin(perm), end(perm), 1);
  sort(begin(perm), end(perm),
       [](int x, int y) { return elist[x].tag > elist[y].tag; });
  for (int i : perm) {
    int nu = n + i;
    int x = find(elist[i].l);
    int y = find(elist[i].r);
    if (x != y) {
      par[x] = par[y] = nu;
      g[nu].emplace_back(x);
      g[nu].emplace_back(y);
    }
  }
  for (int i = 2; i <= 4; ++i) {
  }
  set<int> roots;
  for (int i = 1; i <= n; ++i) {
    roots.insert(find(i));
  }
  for (int x : roots) {
    setPar(x, 0);
    dfs(x);
  }
  build();
  vi ans;
  for (int i = 0; i < (int)(updates).size(); ++i) {
    int tag = i + 1;
    auto [op, u] = updates[i];
    if (op == 1) {
      int anc = getHighest(u, tag);
      int mxVal = Max(in[anc], out[anc]);
      ans.emplace_back(mxVal);
      if (mxVal) makeZero(position[mxVal]);
    } else {
    }
  }
  for (int x : ans) {
    printf("%d\n", x);
  }
  return 0;
}
