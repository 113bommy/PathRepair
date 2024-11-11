#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXV = MAXN * 5;
const long long INF = (long long)1e9 + 5;
const long long MOD = 1000000007;
struct DSU {
  int pa[MAXV];
  set<int> member[MAXV];
  void init() {
    for (int i = 0; i < MAXV; i++) {
      pa[i] = i;
      member[i].insert(i);
    }
  }
  int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (member[y].size() > member[x].size()) swap(x, y);
    for (int v : member[y]) member[x].insert(v);
    member[y].clear();
    pa[y] = x;
  }
} dsu;
struct Query {
  char t;
  int x, y, z;
};
int N, M, Q, C, st[MAXN], who[MAXV];
vector<int> col[MAXN];
vector<int> G[MAXV];
Query qs[MAXN * 2];
int get_id(int v, int c) {
  int pos = lower_bound(col[v].begin(), col[v].end(), c) - col[v].begin();
  assert(pos != col[v].size() && col[v][pos] == c);
  return st[v] + pos;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> C >> Q;
  Q += M;
  for (int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    col[x].push_back(c);
    col[y].push_back(c);
    qs[i] = {'+', x, y, c};
  }
  for (int i = M; i < Q; i++) {
    char t;
    int x, y, c = -1;
    cin >> t >> x >> y;
    if (t == '+') {
      cin >> c;
      col[x].push_back(c);
      col[y].push_back(c);
    }
    qs[i] = {t, x, y, c};
  }
  st[1] = 1;
  for (int i = 1; i <= N; i++) {
    col[i].push_back(0);
    sort(col[i].begin(), col[i].end());
    col[i].resize(unique(col[i].begin(), col[i].end()) - col[i].begin());
    st[i + 1] = st[i] + col[i].size();
    for (int j = st[i]; j < st[i + 1]; j++) {
      who[j] = i;
    }
  }
  dsu.init();
  for (int _q = 0; _q < Q; _q++) {
    char t = qs[_q].t;
    int x = qs[_q].x, y = qs[_q].y, c = qs[_q].z;
    if (t == '+') {
      dsu.merge(get_id(x, 0), get_id(y, c));
      dsu.merge(get_id(x, c), get_id(y, 0));
    } else {
      int v = dsu.find(get_id(x, 0));
      auto it = dsu.member[v].lower_bound(st[y]);
      bool ok = it != dsu.member[v].end() && st[y] <= *it && *it < st[y + 1];
      cout << (ok ? "Yes\n" : "No\n");
    }
  }
  return 0;
}
