#include <bits/stdc++.h>
using namespace std;
const long long MAX = 200005;
long long n;
vector<long long> adjlist[MAX];
long long stat[MAX], timer = 0, in[MAX], out[MAX], st[MAX * 4], lazy[MAX * 4];
void dfs(long long pos, long long parent) {
  in[pos] = ++timer;
  for (long long v : adjlist[pos]) {
    if (v != parent) {
      dfs(v, pos);
    }
  }
  out[pos] = timer;
}
void input() {
  cin >> n;
  for (long long i = 2; i <= n; i++) {
    long long x;
    cin >> x;
    adjlist[i].push_back(x);
    adjlist[x].push_back(i);
  }
  dfs(1, -1);
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    stat[in[i]] = x;
  }
}
void build(long long stat[], long long v, long long tl, long long tr,
           long long l, long long r) {
  if (tl == tr) {
    st[v] = stat[tl];
    return;
  }
  long long mid = (tl + tr) >> 1;
  build(stat, v * 2 + 1, tl, mid, l, r);
  build(stat, v * 2 + 2, mid + 1, tr, l, r);
  st[v] = st[v * 2 + 1] + st[v * 2 + 2];
}
void update(long long v, long long tl, long long tr, long long l, long long r) {
  if (lazy[v] % 2 != 0) {
    st[v] = (tr - tl + 1) - st[v];
    if (tl != tr) {
      lazy[v * 2 + 1] += lazy[v];
      lazy[v * 2 + 2] += lazy[v];
      lazy[v * 2 + 1] %= 2;
      lazy[v * 2 + 2] %= 2;
    }
    lazy[v] = 0;
  }
  if (tl > r || tr < l) {
    return;
  }
  if (l <= tl && tr <= r) {
    st[v] = (tr - tl + 1) - st[v];
    if (tl != tr) {
      lazy[v * 2 + 1]++;
      lazy[v * 2 + 2]++;
    }
    return;
  }
  long long mid = (tl + tr) >> 1;
  update(v * 2 + 1, tl, mid, l, r);
  update(v * 2 + 2, mid + 1, tr, l, r);
  st[v] = st[v * 2 + 1] + st[v * 2 + 2];
}
long long query(long long v, long long tl, long long tr, long long l,
                long long r) {
  if (lazy[v] % 2 != 0) {
    st[v] = (tr - tl + 1) - st[v];
    if (tl != tr) {
      lazy[v * 2 + 1] += lazy[v];
      lazy[v * 2 + 2] += lazy[v];
      lazy[v * 2 + 1] %= 2;
      lazy[v * 2 + 2] %= 2;
    }
    lazy[v] = 0;
  }
  if (tl > r || tr < l) {
    return 0;
  }
  if (l <= tl && tr <= r) {
    return st[v];
  }
  long long mid = (tl + tr) >> 1;
  return query(v * 2 + 1, tl, mid, l, r) + query(v * 2 + 2, mid + 1, tr, l, r);
}
void solve() {
  build(stat, 1, 1, n, 1, n);
  long long q;
  cin >> q;
  while (q--) {
    string s;
    long long v;
    cin >> s >> v;
    if (s == "get") {
      cout << query(1, 1, n, in[v], out[v]) << endl;
    } else {
      update(1, 1, n, in[v], out[v]);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  input();
  solve();
}
