#include <bits/stdc++.h>
using namespace std;
int n, m;
int color[400100];
int u, v;
vector<int> ga[400100];
int din[400100], dout[400100], nd[400100];
int timer;
void dfs(int u, int p) {
  timer++;
  din[u] = timer;
  nd[timer] = u;
  for (int i = 0; i < ga[u].size(); i++) {
    int v = ga[u][i];
    if (v != p) dfs(v, u);
  }
  dout[u] = timer;
}
struct segment_tree {
  long long dat[1600100];
  bool put[1600100];
  void push(int x) {
    if (put[x]) {
      dat[x * 2] = dat[x * 2 + 1] = dat[x];
      put[x] = false;
      put[x * 2] = put[x * 2 + 1] = true;
    }
  }
  void calc(int x) { dat[x] = dat[x * 2] | dat[x * 2 + 1]; }
  void build(int x, int l, int r) {
    if (l < r) {
      int y = (l + r) >> 1;
      build(x * 2, l, y);
      build(x * 2 + 1, y + 1, r);
      calc(x);
      put[x] = false;
    } else {
      dat[x] = (1LL << (color[nd[l]]));
      put[x] = true;
    }
  }
  void modify(int x, int l, int r, int ll, int rr, long long val) {
    if (r < ll || l > rr) {
      return;
    }
    if (ll <= l && rr >= r) {
      dat[x] = val;
      put[x] = true;
      return;
    }
    push(x);
    int y = (l + r) >> 1;
    modify(x * 2, l, y, ll, rr, val);
    modify(x * 2 + 1, y + 1, r, ll, rr, val);
    calc(x);
  }
  long long get(int x, int l, int r, int ll, int rr) {
    if (r < ll || l > rr) {
      return 0LL;
    }
    if (ll <= l && rr >= r) {
      return dat[x];
    }
    push(x);
    int y = (l + r) >> 1;
    long long res = get(x * 2, l, y, ll, rr);
    res |= get(x * 2 + 1, y + 1, r, ll, rr);
    calc(x);
    return res;
  }
} seg;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> color[i];
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    ga[u].push_back(v);
    ga[v].push_back(u);
  }
  dfs(1, -1);
  seg.build(1, 1, n);
  int type, aa, bb;
  for (int i = 1; i <= m; i++) {
    cin >> type;
    if (type == 1) {
      cin >> aa >> bb;
      seg.modify(1, 1, n, din[aa], dout[aa], (1 << bb));
    }
    if (type == 2) {
      cin >> aa;
      cout << __builtin_popcountll(seg.get(1, 1, n, din[aa], dout[aa])) << endl;
    }
  }
  return 0;
}
