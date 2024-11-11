#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 65;
const int LGN = 19;
int sz, ptr, tr[N * LGN][2], rt[N], val[N * LGN], pos[N];
vector<pair<int, int> > blk[N];
inline int create(int l, int r) {
  val[ptr] = min(val[l], val[r]);
  tr[ptr][0] = l;
  tr[ptr][1] = r;
  return ptr++;
}
int update(int v, int l, int r, int ind, int x) {
  if (l == r) {
    val[ptr] = max(val[v], x);
    return ptr++;
  }
  int m = (l + r) / 2;
  if (ind <= m)
    return create(update(tr[v][0], l, m, ind, x), tr[v][1]);
  else
    return create(tr[v][0], update(tr[v][1], m + 1, r, ind, x));
}
int query(int v, int s, int e, int l, int r) {
  if (l <= s && e <= r) return val[v];
  int m = (s + e) / 2;
  if (r <= m) return query(tr[v][0], s, m, l, r);
  if (m < l) return query(tr[v][1], m + 1, e, l, r);
  return min(query(tr[v][0], s, m, l, r), query(tr[v][1], m + 1, e, l, r));
}
void compress(vector<array<int, 3> > &coords) {
  sz = 0;
  for (auto x : coords) {
    pos[++sz] = x[0];
    pos[++sz] = x[1];
  }
  sort(pos + 1, pos + sz + 1);
  sz = unique(pos + 1, pos + sz + 1) - pos - 1;
  for (auto &x : coords) {
    x[0] = lower_bound(pos + 1, pos + sz + 1, x[0]) - pos;
    x[1] = lower_bound(pos + 1, pos + sz + 1, x[1]) - pos;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  int n, m, k;
  cin >> n >> m >> k;
  memset(tr, 0, sizeof(tr));
  memset(val, 0, sizeof(val));
  vector<array<int, 3> > coords;
  for (int i = 1; i <= k; i++) {
    int l, r, p;
    cin >> l >> r >> p;
    coords.push_back({l, r, p});
  }
  compress(coords);
  for (auto x : coords) {
    blk[x[1]].push_back({x[0], x[2]});
  }
  ptr = 1;
  rt[0] = 0;
  for (int r = 1; r <= sz; r++) {
    rt[r] = rt[r - 1];
    for (auto pp : blk[r]) {
      rt[r] = update(rt[r], 1, n, pp.second, pp.first);
    }
  }
  for (int i = 1; i <= m; i++) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ind = upper_bound(pos + 1, pos + sz + 1, y) - pos - 1;
    if (ind < 1 || ind > sz) {
      cout << "no" << endl;
      continue;
    }
    int tmp = query(rt[ind], 1, n, a, b);
    if (tmp == 0 || pos[tmp] < x) {
      cout << "no" << endl;
    } else {
      cout << "yes" << endl;
    }
  }
  return 0;
}
