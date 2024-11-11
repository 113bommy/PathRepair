#include <bits/stdc++.h>
using namespace std;
bool Q = false;
struct line {
  mutable int64_t m, c;
  mutable long double x;
  line(int64_t M, int64_t C, int64_t X) : m(M), c(C), x(X) {}
  bool operator<(const line& next) const {
    if (Q == false) {
      return m > next.m;
    } else
      return x < next.x;
  }
  int64_t get(int64_t X) { return m * X + c; }
};
struct hull : multiset<line> {
  long double cross(iterator a, iterator b) {
    long double A = a->m, B = a->c, C = b->m, D = b->c;
    return (D - B) / (A - C);
  }
  bool isect(iterator a, iterator b) {
    if (b == end()) {
      a->x = (int64_t)(1e17 + 1);
      return false;
    }
    if (a->m == b->m)
      a->x = ((a->c > b->c) ? -(int64_t)(1e17 + 1) : (int64_t)(1e17 + 1));
    else
      a->x = cross(a, b);
    return a->x >= b->x;
  }
  void add(int64_t M, int64_t C) {
    iterator pre, curr, next;
    curr = insert(line(M, C, 0));
    next = pre = curr;
    next++;
    while (isect(curr, next)) next = erase(next);
    if (curr != begin() && isect(--pre, curr)) isect(pre, curr = erase(curr));
    while ((curr = pre) != begin() && (--pre)->x >= curr->x)
      isect(pre, erase(curr));
  }
  int64_t query(int64_t X) {
    Q = true;
    line curr = *lower_bound(line(0, 0, X));
    Q = false;
    return curr.get(X);
  }
};
vector<int64_t> adj[(int64_t)(1e5 + 5)], ans((int64_t)(1e5 + 5)),
    a((int64_t)(1e5 + 5)), b((int64_t)(1e5 + 5));
hull cht[(int64_t)(1e5 + 5)];
void dfs(int64_t c, int64_t pre) {
  for (auto x : adj[c]) {
    if (x == pre) continue;
    dfs(x, c);
    if (cht[c].size() < cht[x].size()) swap(cht[x], cht[c]);
    for (auto& x : cht[x]) cht[c].add(x.m, x.c);
  }
  if (!cht[c].empty()) ans[c] = cht[c].query(a[c]);
  cht[c].add(b[c], ans[c]);
}
void solve() {
  int64_t n;
  cin >> n;
  for (int64_t i = 1; i <= n; i++) cin >> a[i];
  for (int64_t i = 1; i <= n; i++) cin >> b[i];
  for (int64_t i = 1; i < n; i++) {
    int64_t u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  for (int64_t i = 1; i <= n; i++) cout << ans[i] << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t = 1;
  while (t--) solve();
  return 0;
}
