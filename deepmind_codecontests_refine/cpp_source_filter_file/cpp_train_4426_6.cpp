#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const int MAXN = 2e5 + 10;
const int INF = 1e9;
struct SegmTree {
  vector<int> t;
  int sz;
  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;
    t.assign(sz * 2, INF);
  }
  void insert(int i) {
    int v = sz + i;
    t[v] = i;
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }
  void erase(int i) {
    int v = sz + i;
    t[v] = INF;
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }
  vector<int> get_mn(int cnt) {
    vector<int> res;
    for (int it = 0; it < (int)cnt; ++it) {
      int i = t[1];
      if (i == INF) {
        break;
      }
      erase(i);
      res.push_back(i);
    }
    for (int i : res) insert(i);
    return res;
  }
};
struct Query {
  int v, u, a, id;
  void read(int _id) {
    id = _id;
    scanf("%d%d%d", &v, &u, &a);
    --v;
    --u;
  }
};
vector<int> who_live[MAXN];
vector<int> pars[MAXN];
vector<int> g[MAXN];
bool was[MAXN];
vector<Query> qs_for_v[MAXN];
vector<Query> qs;
int n, m, q;
vector<int> ans[MAXN];
int sz[MAXN];
vector<int> pref_mn[MAXN];
bool read() {
  if (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  for (int i = 0; i < (int)n; ++i) {
    g[i].clear();
    pars[i].clear();
    qs_for_v[i].clear();
    who_live[i].clear();
    pref_mn[i].clear();
  }
  qs.clear();
  for (int i = 0; i < (int)q; ++i) {
    ans[i].clear();
  }
  for (int i = 0; i < (int)n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < (int)m; ++i) {
    int c;
    scanf("%d", &c);
    --c;
    who_live[c].push_back(i);
  }
  for (int i = 0; i < (int)q; ++i) {
    Query cur;
    cur.read(i);
    qs.push_back(cur);
  }
  return true;
}
void insert(vector<int>& arr, int i) {
  arr.push_back(i);
  for (int j = ((int)(arr).size()) - 1; j > 0; --j) {
    if (arr[j] > arr[j - 1]) {
      swap(arr[j], arr[j - 1]);
    } else {
      break;
    }
  }
  while (((int)(arr).size()) > 10) arr.pop_back();
}
void dfs_prec(int v, int p, vector<int>& arr) {
  vector<int> mem = arr;
  for (int i : who_live[v]) insert(arr, i);
  pref_mn[v] = arr;
  for (int to : g[v]) {
    if (to == p || was[to]) {
      continue;
    }
    dfs_prec(to, v, arr);
  }
  arr = mem;
}
void precalc_mn(int r) {
  vector<int> arr;
  dfs_prec(r, -1, arr);
}
void dfs_sz(int v, int p) {
  sz[v] = 1;
  for (int to : g[v]) {
    if (to == p || was[to]) {
      continue;
    }
    dfs_sz(to, v);
    sz[v] += sz[to];
  }
}
int dfs_root(int v, int p, int S) {
  int mx_to = -1;
  for (int to : g[v]) {
    if (to == p || was[to]) {
      continue;
    }
    if (mx_to == -1 || sz[to] > sz[mx_to]) {
      mx_to = to;
    }
  }
  if (mx_to == -1 || sz[mx_to] * 2 < S) {
    return v;
  }
  return dfs_root(mx_to, v, S);
}
int get_root(int v) {
  dfs_sz(v, -1);
  return dfs_root(v, -1, sz[v]);
}
void dfs_pars(int v, int p, int r) {
  pars[v].push_back(r);
  for (int to : g[v]) {
    if (to == p || was[to]) {
      continue;
    }
    dfs_pars(to, v, r);
  }
}
void go(int v, bool init) {
  int r = get_root(v);
  if (init) {
    dfs_pars(r, -1, r);
  } else {
    precalc_mn(r);
    for (auto Q : qs_for_v[r]) {
      vector<int> res(((int)(pref_mn[Q.u]).size()) +
                      ((int)(pref_mn[Q.v]).size()));
      merge(begin(pref_mn[Q.u]), end(pref_mn[Q.u]), begin(pref_mn[Q.v]),
            end(pref_mn[Q.v]), res.begin());
      res.resize(unique(begin(res), end(res)) - res.begin());
      for (int i = 0; i < (int)min(((int)(res).size()), Q.a); ++i) {
        ans[Q.id].push_back(res[i]);
      }
    }
  }
  was[r] = true;
  for (int to : g[r]) {
    if (!was[to]) {
      go(to, init);
    }
  }
}
void solve() {
  memset(was, false, sizeof was);
  go(0, true);
  for (auto Q : qs) {
    int r = -1;
    for (int i = 0;
         i < (int)min(((int)(pars[Q.u]).size()), ((int)(pars[Q.v]).size()));
         ++i) {
      if (pars[Q.u][i] == pars[Q.v][i]) {
        r = pars[Q.u][i];
      }
    }
    assert(r != -1);
    qs_for_v[r].push_back(Q);
  }
  memset(was, false, sizeof was);
  go(0, false);
  for (int i = 0; i < (int)q; ++i) {
    printf("%d ", ((int)(ans[i]).size()));
    for (int v : ans[i]) printf("%d ", v + 1);
    puts("");
  }
}
int main() {
  while (read()) {
    solve();
  }
  return 0;
}
