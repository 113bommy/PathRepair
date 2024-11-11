#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, t, h[maxn], l[maxn], r[maxn], dp[maxn];
struct pt {
  int pos, height, type, ind;
  pt(int a, int b, int c, int d) : pos(a), height(b), type(c), ind(d) {}
  bool operator<(const pt &x) const {
    if (pos != x.pos) return pos < x.pos;
    if (type != x.type) return type > x.type;
    if (ind != x.ind) return ind < x.ind;
    return 0;
  }
};
vector<pt> v;
set<int> g[maxn];
set<pair<int, int> > st;
int solvedp(int u) {
  if (~dp[u]) return dp[u];
  int ans = 0;
  for (int v : g[u]) {
    ans = max(ans, min(solvedp(v), min(r[u], r[v]) - max(l[u], l[v])));
  }
  return dp[u] = ans;
}
int main() {
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &h[i], &l[i], &r[i]);
    v.push_back(pt(l[i], h[i], 0, i));
    v.push_back(pt(r[i], h[i], 1, i));
  }
  stable_sort(v.begin(), v.end());
  l[n] = l[n + 1] = -1e9;
  r[n] = r[n + 1] = 1e9;
  st.insert(make_pair(t, n));
  st.insert(make_pair(0, n + 1));
  for (int i = 0; i < (int)v.size(); i++) {
    pair<int, int> p = make_pair(v[i].height, v[i].ind);
    if (v[i].type) {
      st.erase(p);
    } else {
      st.insert(p);
      pair<int, int> x = *(--st.lower_bound(p));
      pair<int, int> y = *(st.upper_bound(p));
      if (g[y.second].count(x.second)) {
        g[y.second].erase(x.second);
      }
      g[y.second].insert(v[i].ind);
      g[v[i].ind].insert(x.second);
    }
  }
  memset(dp, -1, sizeof dp);
  dp[n + 1] = 2e9;
  printf("%d\n", solvedp(n));
  return 0;
}
