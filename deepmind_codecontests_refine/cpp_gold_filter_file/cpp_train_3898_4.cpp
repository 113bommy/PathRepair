#include <bits/stdc++.h>
using namespace std;
long m, k, p, a, b;
vector<long> g[200000];
long used[200000];
long dep[200000];
long level[200000];
long l, r, mid;
void dfs(long v) {
  used[v] = 1;
  level[dep[v]]++;
  for (int i = 0; i < g[v].size(); i++) {
    long q = g[v][i];
    if (used[q]) continue;
    dep[q] = dep[v] + 1;
    dfs(q);
  }
}
long long ttl, lev, qlev, tcost;
long long d, upl;
void pop(long val) {
  ttl -= (level[qlev]);
  tcost -= ttl;
  if (ttl <= 0 || tcost < 0) ttl = tcost = 0;
}
void add(long val) {
  if (ttl == val) return;
  if (d < level[upl]) {
    long span = min(level[upl] - d, val - ttl);
    ttl += span;
    tcost += (qlev - upl) * span;
    d += span;
    return;
  }
  d = 0;
  upl--;
}
bool solve(long val) {
  if (val == 0) return true;
  if (val == 1) return (k > 0);
  long long bcost = 2e9;
  upl = m;
  d = 0;
  ttl = 0;
  tcost = 0;
  for (int i = m + 1; i; --i) {
    qlev = i;
    if (upl > qlev) {
      upl = qlev;
      d = 0;
    }
    while (ttl < val && upl > 1) {
      add(val);
    }
    if (tcost < bcost && ttl == val) bcost = tcost;
    pop(val);
  }
  if (bcost <= p) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> k >> p;
  for (int i = 1; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dep[1] = 1;
  dfs(1);
  l = 0;
  r = m - 1;
  if (r > k) r = k;
  while (l < r) {
    long mid = l + r + 1;
    mid /= 2;
    if (solve(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
  cin.get();
  cin.get();
  return 0;
}
