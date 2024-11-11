#include <bits/stdc++.h>
using namespace std;
struct dsu_save {
  int u, ru, szu;
  int v, rv, szv;
};
struct dsu_with_rollback {
  vector<int> p, r, sz;
  stack<dsu_save> op;
  dsu_with_rollback() {}
  dsu_with_rollback(int n) {
    p.resize(n + 1);
    r.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      r[i] = 0;
      sz[i] = 1;
    }
  }
  int findt(int x) {
    if (x == p[x]) return x;
    return findt(p[x]);
  }
  int join(int a, int b) {
    a = findt(a);
    b = findt(b);
    if (a == b) return 0;
    if (r[a] < r[b]) swap(a, b);
    op.push({a, r[a], sz[a], b, r[b], sz[b]});
    if (r[a] == r[b]) {
      r[a]++;
    }
    p[b] = a;
    sz[a] += sz[b];
    return 1;
  }
  void rollback() {
    if (op.size() == 0) return;
    dsu_save lop = op.top();
    op.pop();
    p[lop.u] = lop.u;
    r[lop.u] = lop.ru;
    sz[lop.u] = lop.szu;
    p[lop.v] = lop.v;
    r[lop.v] = lop.rv;
    sz[lop.v] = lop.szv;
  }
  int sizen(int nod) { return sz[findt(nod)]; }
};
struct edgejoin {
  int u, v;
};
const int N_DAYS = 5 * 1e5 + 5;
vector<edgejoin> aint[4 * N_DAYS + 5];
vector<int> query[N_DAYS + 5];
struct dsu_with_undo {
  int N_nodes;
  dsu_with_rollback dsu;
  dsu_with_undo(int n) {
    N_nodes = n;
    dsu = dsu_with_rollback(n);
  }
  void add_edge(int nod, int l, int r, int ql, int qr, edgejoin e) {
    if (l > r || l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
      aint[nod].push_back(e);
      return;
    }
    int mid = (l + r) / 2;
    add_edge(2 * nod, l, mid, ql, qr, e);
    add_edge(2 * nod + 1, mid + 1, r, ql, qr, e);
  }
  void add_q(int day, int nod) { query[day].push_back(nod); }
  void dfs(int nod, int l, int r) {
    int nru = 0;
    for (auto upd : aint[nod]) {
      nru += dsu.join(upd.u, upd.v);
    }
    if (l == r) {
      for (auto node : query[l]) {
        cout << dsu.sizen(node) << "\n";
      }
    } else {
      int mid = (l + r) / 2;
      dfs(2 * nod, l, mid);
      dfs(2 * nod + 1, mid + 1, r);
    }
    while (nru--) {
      dsu.rollback();
    }
  }
};
vector<int> input[N_DAYS];
int lastofday[N_DAYS];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  int nday = 1;
  for (int i = 1; i <= q; i++) {
    int t;
    cin >> t;
    input[i].push_back(t);
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      input[i].push_back(x);
      input[i].push_back(y);
    } else if (t == 2) {
      int x;
      cin >> x;
      input[i].push_back(x);
    } else if (t == 3) {
      lastofday[nday] = i;
      nday++;
    }
  }
  int nrday = nday;
  lastofday[nrday] = q;
  dsu_with_undo ds(n);
  nday = 1;
  for (int i = 1; i <= q; i++) {
    int t;
    t = input[i][0];
    if (t == 1) {
      int x, y;
      x = input[i][1];
      y = input[i][2];
      ds.add_edge(1, 1, q, i, lastofday[min(nday + k - 1, nrday)], {x, y});
    } else if (t == 2) {
      int x;
      x = input[i][1];
      ds.add_q(i, x);
    } else if (t == 3)
      nday++;
  }
  ds.dfs(1, 1, q);
  return 0;
}
