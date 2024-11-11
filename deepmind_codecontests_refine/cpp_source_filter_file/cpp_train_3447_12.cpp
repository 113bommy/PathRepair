#include <bits/stdc++.h>
using namespace std;
struct lca {
  int n;
  int lim = 21;
  int timer = 0;
  vector<vector<int>> g;
  vector<int> used;
  vector<int> p;
  vector<int> tin;
  vector<int> tout;
  vector<int> h;
  vector<vector<int>> up;
  void dfs(int cur, int pr, int hh) {
    h[cur] = hh;
    tin[cur] = timer;
    timer++;
    p[cur] = pr;
    used[cur] = 1;
    for (auto t : g[cur]) {
      if (!used[t]) {
        dfs(t, cur, hh + 1);
      }
    }
    tout[cur] = timer;
    timer++;
  }
  void get_up() {
    up.resize(lim, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
      up[0][i] = p[i];
    }
    for (int i = 1; i < lim; i++) {
      for (int j = 0; j < n; j++) {
        auto md = up[i - 1][j];
        if (md != -1) {
          up[i][j] = up[i - 1][md];
        } else {
          up[i][j] = -1;
        }
      }
    }
  }
  bool parent(int a, int b) { return tin[a] < tin[b] && tout[a] > tout[b]; }
  void go(int nn) {
    n = nn;
    g.resize(n);
    used.resize(n);
    p.resize(n);
    tin.resize(n);
    tout.resize(n);
    h.resize(n);
    for (int i = 1; i < n; i++) {
      int u;
      cin >> u;
      u--;
      g[u].push_back(i);
    }
    dfs(0, -1, 0);
    get_up();
  }
  int get(int a, int b) {
    if (a == b) {
      return a;
    } else if (parent(a, b)) {
      return a;
    } else if (parent(b, a)) {
      return b;
    } else {
      int cur = b;
      for (int i = lim - 1; i >= 0; i--) {
        if (up[i][cur] != -1 && !parent(up[i][cur], a)) {
          cur = up[i][cur];
        }
      }
      assert(p[cur] != -1);
      return p[cur];
    }
  }
};
lca uu;
int conq(int a, int b, int fl) {
  if (fl == 2) {
    return uu.get(a, b);
  } else if (fl == 1) {
    return min(a, b);
  } else {
    return max(a, b);
  }
}
struct sparce {
  int n;
  int flag = false;
  const int lim = 21;
  vector<vector<int>> sp;
  vector<int> pw;
  void init(const vector<int> &a) {
    sp.resize(lim, vector<int>(n));
    for (int i = 0; i < n; i++) {
      sp[0][i] = a[i];
    }
    for (int i = 1; i < lim; i++) {
      for (int j = 0; j + (1 << (i)) <= n; j++) {
        int f = sp[i - 1][j];
        int s = sp[i - 1][j + (1 << (i - 1))];
        sp[i][j] = conq(f, s, flag);
      }
    }
    pw.resize(n + 1, -1);
    pw[1] = 0;
    for (int i = 2; i <= n; i++) {
      pw[i] = pw[i / 2] + 1;
    }
  }
  void go(const vector<int> &a, int fl) {
    flag = fl;
    n = (int)a.size();
    init(a);
  }
  sparce() { n = 0; }
  int get(int l, int r) {
    int p = pw[r - l];
    int ln = (1 << p);
    int md = r - ln;
    return conq(sp[p][l], sp[p][md], flag);
  }
};
sparce for_lca;
sparce for_tin_min;
sparce for_tin_max;
int get_wth(int l, int r, int x) {
  if (l == x) {
    return (for_lca.get(l + 1, r));
  } else if (x + 1 == r) {
    return (for_lca.get(l, r - 1));
  } else {
    return uu.get(for_lca.get(l, x), for_lca.get(x + 1, r));
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  uu.go(n);
  cerr << "lca ready" << endl;
  vector<int> h = uu.h;
  vector<int> tin = uu.tin;
  vector<int> tmp(n);
  for (int i = 0; i < n; i++) {
    tmp[i] = i;
  }
  for_tin_max.go(tin, 0);
  for_tin_min.go(tin, 1);
  for_lca.go(tmp, 2);
  map<int, int> by_tin;
  for (int i = 0; i < n; i++) {
    by_tin[tin[i]] = i;
  }
  cerr << "ready to answer" << endl;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    auto was = for_lca.get(l, r);
    if (l <= was && r < was) {
      cout << was + 1 << ' ' << get_wth(l, r, was) << '\n';
    } else {
      int mntin = for_tin_min.get(l, r);
      int mxtin = for_tin_max.get(l, r);
      auto f = get_wth(l, r, by_tin[mntin]);
      auto s = get_wth(l, r, by_tin[mxtin]);
      assert(l <= by_tin[mntin] && by_tin[mntin] < r);
      assert(l <= by_tin[mxtin] && by_tin[mxtin] < r);
      if (h[f] > h[s]) {
        cout << by_tin[mntin] + 1 << ' ' << h[f] << '\n';
      } else {
        cout << by_tin[mxtin] + 1 << ' ' << h[s] << '\n';
      }
    }
  }
}
