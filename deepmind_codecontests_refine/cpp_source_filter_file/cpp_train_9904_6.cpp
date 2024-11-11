#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17 + 10;
const int N = 1e5 + 10;
const long long mod = 1000000007;
const int base = 131;
map<string, int> ml;
long long a[N], n, m, t, k, flag, l[N], r[N], cnt;
long long lazy[N << 2];
long long tree[N << 2];
vector<int> st[N], en[N], v;
priority_queue<int> q;
void push_up(int rt) { tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]); }
void push_down(int rt) {
  if (lazy[rt]) {
    lazy[rt << 1] = lazy[rt];
    lazy[rt << 1 | 1] = lazy[rt];
    tree[rt << 1] += lazy[rt];
    tree[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
}
void build(int rt, int l, int r) {
  if (l == r) {
    cin >> tree[rt];
    return;
  }
  int m = l + r >> 1;
  build(rt << 1, l, m);
  build(rt << 1 | 1, m + 1, r);
  push_up(rt);
}
void update(int L, int R, int x, int rt, int l, int r) {
  if (L <= l && r <= R) {
    tree[rt] += x;
    lazy[rt] += x;
    return;
  }
  push_down(rt);
  int m = l + r >> 1;
  if (L <= m) update(L, R, x, rt << 1, l, m);
  if (R > m) update(L, R, x, rt << 1 | 1, m + 1, r);
  push_up(rt);
}
long long query(int L, int R, int rt, int l, int r) {
  if (L <= l && r <= R) return tree[rt];
  int m = l + r >> 1;
  push_down(rt);
  long long ans = -1e9;
  if (L <= m) ans = max(ans, query(L, R, rt << 1, l, m));
  if (R > m) ans = max(ans, query(L, R, rt << 1 | 1, m + 1, r));
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> n >> m;
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    l[i] = x;
    r[i] = y;
    st[x].push_back(y);
    en[y].push_back(x);
  }
  long long res = -inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < st[i].size(); j++) update(i, st[i][j], -1, 1, 1, n);
    cnt = query(1, n, 1, 1, n) - query(i, i, 1, 1, n);
    if (cnt > res) {
      res = cnt;
      k = i;
    }
    for (int j = 0; j < en[i].size(); j++) update(en[i][j], i, 1, 1, 1, n);
  }
  cout << res << endl;
  for (int i = 1; i <= m; i++) {
    if (k >= l[i] && k <= r[i]) v.push_back(i);
  }
  cout << v.size() << endl;
  for (auto x : v) cout << x << " ";
}
