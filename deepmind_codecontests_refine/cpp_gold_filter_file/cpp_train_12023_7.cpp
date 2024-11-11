#include <bits/stdc++.h>
using namespace std;
int n, u, v, ffp[200011], fsp[200011], sfp[200011], ssp[200011], nlv[200011];
vector<int> t[200011];
void dfs1(int v) {
  if (t[v].empty())
    nlv[v] = 1;
  else
    for (auto it : t[v]) dfs1(it), nlv[v] += nlv[it];
}
void dfs2(int v) {
  if (!t[v].empty()) {
    ffp[v] = sfp[v] = 0, fsp[v] = 1, ssp[v] = 200011;
    for (auto it : t[v]) {
      dfs2(it);
      ffp[v] = max(ffp[v], nlv[v] - nlv[it] + fsp[it]);
      fsp[v] += ffp[it] - 1;
      sfp[v] += ssp[it];
      ssp[v] = min(ssp[v], sfp[it]);
    }
  } else
    ffp[v] = fsp[v] = sfp[v] = ssp[v] = 1;
}
int main() {
  cin >> n;
  for (int(i) = int(1); (i) <= int(n - 1); (i)++)
    cin >> u >> v, t[u].push_back(v);
  dfs1(1), dfs2(1), cout << ffp[1] << ' ' << sfp[1] << endl;
}
