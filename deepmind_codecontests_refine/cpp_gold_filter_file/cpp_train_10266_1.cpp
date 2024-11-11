#include <bits/stdc++.h>
using namespace std;
const long long mxn = 3e5;
long long tin[mxn], tout[mxn];
long long seg_tree[2][4 * mxn + 5], lazy[2][4 * mxn + 5], clk;
vector<pair<long long, long long> > neibs[mxn];
void lazify(long long tp, long long id) {
  if (lazy[tp][id]) {
    seg_tree[tp][2 * id] += lazy[tp][id];
    seg_tree[tp][2 * id + 1] += lazy[tp][id];
    lazy[tp][2 * id] += lazy[tp][id];
    lazy[tp][2 * id + 1] += lazy[tp][id];
    lazy[tp][id] = 0;
  }
}
void upd(long long tp, long long val, long long l, long long r, long long bl,
         long long br, long long id) {
  if (l == bl && r == br) {
    seg_tree[tp][id] += val;
    lazy[tp][id] += val;
    return;
  }
  lazify(tp, id);
  long long mid = (bl + br) / 2;
  if (r <= mid)
    upd(tp, val, l, r, bl, mid, 2 * id);
  else if (l > mid)
    upd(tp, val, l, r, mid + 1, br, 2 * id + 1);
  else {
    upd(tp, val, l, mid, bl, mid, 2 * id);
    upd(tp, val, mid + 1, r, mid + 1, br, 2 * id + 1);
  }
  seg_tree[tp][id] = min(seg_tree[tp][2 * id], seg_tree[tp][2 * id + 1]);
}
long long qry(long long tp, long long l, long long r, long long bl,
              long long br, long long id) {
  if (l == bl && r == br) return seg_tree[tp][id];
  lazify(tp, id);
  long long mid = (bl + br) / 2;
  if (r <= mid) return qry(tp, l, r, bl, mid, 2 * id);
  if (l > mid) return qry(tp, l, r, mid + 1, br, 2 * id + 1);
  return min(qry(tp, l, mid, bl, mid, 2 * id),
             qry(tp, mid + 1, r, mid + 1, br, 2 * id + 1));
}
void dfs(long long v, long long depth) {
  tin[v] = ++clk;
  upd(0, depth, clk, clk, 1, mxn, 1);
  for (pair<long long, long long> ud : neibs[v]) {
    long long u = ud.first, d = ud.second;
    dfs(u, depth + d);
  }
  tout[v] = clk;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, q;
  cin >> n >> q;
  long long edge[2 * n - 1][3];
  for (long long i = 1; i <= 2 * n - 2; ++i) {
    for (long long j = 0; j <= 2; ++j) cin >> edge[i][j];
    if (i == n) dfs(1, 0);
    if (i < n)
      neibs[edge[i][0]].push_back({edge[i][1], edge[i][2]});
    else {
      long long depth = qry(0, tin[edge[i][0]], tin[edge[i][0]], 1, mxn, 1);
      upd(1, depth + edge[i][2], tin[edge[i][0]], tin[edge[i][0]], 1, mxn, 1);
    }
  }
  while (q--) {
    long long tp, a, b;
    cin >> tp >> a >> b;
    if (tp == 1) {
      if (a < n) {
        upd(0, b - edge[a][2], tin[edge[a][1]], tout[edge[a][1]], 1, mxn, 1);
        upd(1, b - edge[a][2], tin[edge[a][1]], tout[edge[a][1]], 1, mxn, 1);
        edge[a][2] = b;
      } else {
        upd(1, b - edge[a][2], tin[edge[a][0]], tin[edge[a][0]], 1, mxn, 1);
        edge[a][2] = b;
      }
    } else {
      if (tin[b] >= tin[a] && tin[b] <= tout[a])
        cout << qry(0, tin[b], tin[b], 1, mxn, 1) -
                    qry(0, tin[a], tin[a], 1, mxn, 1)
             << "\n";
      else
        cout << qry(0, tin[b], tin[b], 1, mxn, 1) +
                    qry(1, tin[a], tout[a], 1, mxn, 1) -
                    qry(0, tin[a], tin[a], 1, mxn, 1)
             << "\n";
    }
  }
  return 0;
}
