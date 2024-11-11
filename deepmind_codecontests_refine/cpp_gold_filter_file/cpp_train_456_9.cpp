#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, pair<int, int> > > g[2012];
int f[2012];
int l[3012], r[3012];
void dfs(int u, int s, int e) {
  f[u] = 1;
  for (typeof((g[u]).begin()) it = (g[u]).begin(); it != (g[u]).end(); it++) {
    int v = (*it).first, lt = (*it).second.first, rt = (*it).second.second;
    if (f[v] == 0 and lt <= s and rt >= e) dfs(v, s, e);
  }
}
int reach(int s, int e) {
  for (int(i) = 0; (i) < (n); (i)++) f[i] = 0;
  dfs(0, s, e);
  return f[n - 1];
}
int main() {
  scanf("%d%d", &n, &m);
  int t1, t2, t3, t4;
  for (int(i) = 0; (i) < (m); (i)++) {
    scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
    t1--;
    t2--;
    l[i] = t3;
    r[i] = t4;
    g[t1].push_back(make_pair(t2, make_pair(t3, t4)));
    g[t2].push_back(make_pair(t1, make_pair(t3, t4)));
  }
  sort(l, l + m);
  sort(r, r + m);
  int lp = 0, rp = 0, mxi = 0;
  while (1) {
    if (reach(l[lp], r[rp]) == 1) {
      mxi = max(mxi, r[rp] - l[lp] + 1);
      rp += 1;
    } else
      lp += 1;
    if (rp >= m or lp >= m) break;
  }
  if (mxi != 0)
    cout << mxi;
  else
    cout << "Nice work, Dima!";
  return 0;
}
