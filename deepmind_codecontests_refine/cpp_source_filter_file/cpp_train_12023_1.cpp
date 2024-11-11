#include <bits/stdc++.h>
using namespace std;
int n, u, v, ffp[20011], fsp[20011], sfp[20011], ssp[20011], nlv[20011];
vector<int> t[20011];
void dfs1(int v) {
  if (t[v].empty())
    nlv[v] = 1;
  else
    for (auto it : t[v]) dfs1(it), nlv[v] += nlv[it];
}
void dfs2(int v) {
  if (!t[v].empty()) {
    ffp[v] = sfp[v] = 0, fsp[v] = 1, ssp[v] = 20011;
    for (auto it : t[v]) {
      dfs2(it);
      ffp[v] = max(ffp[v], nlv[v] - nlv[it] + fsp[it]);
      fsp[v] += ffp[it] - 1;
      sfp[v] += ssp[it];
      ssp[v] = min(ssp[v], sfp[v]);
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
