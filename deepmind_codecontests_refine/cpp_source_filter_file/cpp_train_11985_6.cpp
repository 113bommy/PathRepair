#include <bits/stdc++.h>
const int maxn = 300005;
using namespace std;
vector<int> G[maxn];
vector<pair<int, long long> > op[maxn];
int n, m;
long long ans[maxn], sum[maxn << 2], lazy[maxn << 2];
void push_up(int rt) { sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; }
void push_down(int rt, int l, int r) {
  if (lazy[rt]) {
    int m = (l + r) >> 1;
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    sum[rt << 1] += lazy[rt] * (m - l + 1);
    sum[rt << 1 | 1] += lazy[rt] * (r - m);
    lazy[rt] = 0;
  }
}
void update(int l, int r, int rt, int L, int R, long long val) {
  if (L <= l && r <= R) {
    sum[rt] += (r - l + 1) * val;
    lazy[rt] += val;
    return;
  }
  push_down(rt, l, r);
  int m = (l + r) >> 1;
  if (L <= m) update(l, m, rt << 1, L, R, val);
  if (R > m) update(m + 1, r, rt << 1 | 1, L, R, val);
  push_up(rt);
}
long long query(int l, int r, int rt, int L) {
  if (l == r) {
    return sum[rt];
  }
  push_down(rt, l, r);
  int m = (l + r) >> 1;
  int ans = 0;
  if (L <= m)
    ans += query(l, m, rt << 1, L);
  else
    ans += query(m + 1, r, rt << 1 | 1, L);
  return ans;
}
void dfs(int u, int fa, int step) {
  for (auto x : op[u]) {
    update(1, n, 1, step, min(n, step + x.first), x.second);
  }
  ans[u] = query(1, n, 1, step);
  for (auto x : G[u]) {
    if (x == fa) continue;
    dfs(x, u, step + 1);
  }
  for (auto x : op[u]) {
    update(1, n, 1, step, min(n, step + x.first), -x.second);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, d, x;
    scanf("%d %d %I64d", &u, &d, &x);
    op[u].push_back({d, x});
  }
  dfs(1, -1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
