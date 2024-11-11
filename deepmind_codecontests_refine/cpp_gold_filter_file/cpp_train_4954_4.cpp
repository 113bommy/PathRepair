#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
vector<int> diags[MAXN];
void add_diag(int a, int b) {
  diags[a].push_back(b);
  diags[b].push_back(a);
}
bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }
  for (int i = 0; i < int(n); ++i) {
    diags[i].clear();
  }
  for (int i = 0; i < int(m); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    add_diag(a, b);
  }
  for (int i = 0; i < int(n); ++i) {
    int nxt = (i + 1) % n;
    add_diag(i, nxt);
    int prv = (i - 1 + n) % n;
    add_diag(i, prv);
  }
  for (int i = 0; i < int(n); ++i) {
    sort(begin(diags[i]), end(diags[i])),
        diags[i].resize(unique(begin(diags[i]), end(diags[i])) -
                        diags[i].begin());
    ;
  }
  return 1;
}
vector<int> g[MAXN];
vector<vector<int>> cycles;
map<pair<int, int>, set<int>> in_cycles;
set<pair<int, int>> was_right;
int dist_cw(int a, int b) { return (b - a + n) % n; }
bool have_diag(int a, int b) {
  int pos = lower_bound(begin(diags[a]), end(diags[a]), b) - diags[a].begin();
  return pos < ((int)(diags[a]).size()) && diags[a][pos] == b;
}
vector<int> get_right_cycle(int a, int b) {
  if (dist_cw(b, a) == 1) {
    return {};
  }
  if (was_right.count(make_pair(a, b))) {
    return {};
  }
  bool first = true;
  was_right.insert(make_pair(a, b));
  vector<int> res;
  res.push_back(a);
  res.push_back(b);
  while (1) {
    if (dist_cw(b, a) == 1) {
      was_right.insert(make_pair(b, a));
      break;
    }
    int pos = lower_bound(begin(diags[b]), end(diags[b]), a) - diags[b].begin();
    if (first) {
      assert(diags[b][pos] == a);
    } else {
      if (have_diag(b, a)) {
        break;
      }
    }
    first = 0;
    pos = (pos - 1 + ((int)(diags[b]).size())) % ((int)(diags[b]).size());
    int c = diags[b][pos];
    if (dist_cw(b, c) + dist_cw(c, a) == dist_cw(b, a)) {
      assert(!was_right.count(make_pair(b, c)));
      was_right.insert(make_pair(b, c));
      res.push_back(c);
      b = c;
    } else {
      assert(0);
    }
  }
  return res;
}
int ans[MAXN];
int sz[MAXN];
bool was[MAXN];
int N;
void dfs_sz(int v, int p) {
  sz[v] = 1;
  for (int to : g[v]) {
    if (was[to] || to == p) {
      continue;
    }
    dfs_sz(to, v);
    sz[v] += sz[to];
  }
}
int dfs_root(int v, int p, int s) {
  int mx_to = -1;
  for (int to : g[v]) {
    if (was[to] || to == p) {
      continue;
    }
    if (mx_to == -1 || sz[to] > sz[mx_to]) {
      mx_to = to;
    }
  }
  if (mx_to == -1) {
    return v;
  }
  if (sz[mx_to] * 2 <= s) {
    return v;
  }
  return dfs_root(mx_to, v, s);
}
int get_root(int v) {
  dfs_sz(v, -1);
  return dfs_root(v, -1, sz[v]);
}
void paint(int v, int ptr) {
  int r = get_root(v);
  ans[r] = ptr;
  was[r] = 1;
  for (int to : g[r]) {
    if (!was[to]) {
      paint(to, ptr + 1);
    }
  }
}
void paint() {
  N = ((int)(cycles).size());
  int E = 0;
  for (int i = 0; i < int(N); ++i) {
    E += ((int)(g[i]).size());
  }
  assert(E % 2 == 0);
  E /= 2;
  assert(E == N - 1);
  memset(was, 0, sizeof was);
  paint(0, 0);
}
void solve() {
  cycles.clear();
  in_cycles.clear();
  was_right.clear();
  for (int a = 0; a < int(n); ++a) {
    for (int b : diags[a]) {
      if (a > b) {
        continue;
      }
      vector<int> c = get_right_cycle(a, b);
      if (!c.empty()) {
        cycles.push_back(c);
      }
    }
  }
  sort(begin(cycles), end(cycles)),
      cycles.resize(unique(begin(cycles), end(cycles)) - cycles.begin());
  ;
  for (int i = 0; i < int(((int)(cycles).size())); ++i) {
    g[i].clear();
  }
  for (int i = 0; i < int(((int)(cycles).size())); ++i) {
    const vector<int>& cycle = cycles[i];
    for (int j = 0; j < int(((int)(cycle).size())); ++j) {
      int a = cycle[j];
      int b = cycle[(j + 1) % ((int)(cycle).size())];
      in_cycles[make_pair(a, b)].insert(i);
      in_cycles[make_pair(b, a)].insert(i);
    }
  }
  for (int a = 0; a < int(n); ++a)
    for (int b : diags[a]) {
      vector<int> who(begin(in_cycles[make_pair(a, b)]),
                      end(in_cycles[make_pair(a, b)]));
      assert(((int)(who).size()) <= 2);
      for (int i = 0; i < int(((int)(who).size())); ++i)
        for (int j = 0; j < int(i); ++j) {
          int A = who[i];
          int B = who[j];
          g[A].push_back(B);
          g[B].push_back(A);
        }
    }
  for (int i = 0; i < int(((int)(cycles).size())); ++i) {
    sort(begin(g[i]), end(g[i])),
        g[i].resize(unique(begin(g[i]), end(g[i])) - g[i].begin());
    ;
  }
  paint();
  for (int i = 0; i < int(((int)(cycles).size())); ++i) {
    sort(begin(cycles[i]), end(cycles[i]));
    reverse(begin(cycles[i]), end(cycles[i]));
  }
  vector<int> perm(((int)(cycles).size()));
  for (int i = 0; i < int(((int)(perm).size())); ++i) {
    perm[i] = i;
  }
  sort(begin(perm), end(perm), [](int i, int j) {
    const vector<int>& A = cycles[i];
    const vector<int>& B = cycles[j];
    for (int ii = 0; ii < int(min(((int)(A).size()), ((int)(B).size())));
         ++ii) {
      if (A[ii] != B[ii]) {
        return A[ii] < B[ii];
      }
    }
    return ((int)(A).size()) < ((int)(B).size());
  });
  for (int i = 0; i < int(((int)(cycles).size())); ++i) {
    printf("%d ", ans[perm[i]] + 1);
  }
  puts("");
}
int main() {
  while (read()) {
    solve();
  }
  return 0;
}
