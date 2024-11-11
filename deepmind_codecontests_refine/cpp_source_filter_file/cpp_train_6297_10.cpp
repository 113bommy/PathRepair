#include <bits/stdc++.h>
using namespace std;
void out(int ans) {
  cout << ans << "\n";
  exit(0);
}
const long long INF = 1000000000000000000ll;
const long long MOD = 1000000007;
int koll[100500], kolp[100500];
vector<vector<int> > grl, grp, grpp;
vector<int> comp, used;
int numcomp;
void dfsComp(int v) {
  comp[v] = numcomp;
  for (size_t i = 0; i < (int)grl[v].size(); ++i) {
    int nv = grl[v][i];
    if (comp[nv] == -1) dfsComp(nv);
  }
}
void dfsColor(int v) {
  for (int nv : grpp[v])
    if (used[nv] == used[v])
      out(0);
    else if (used[nv] < 0) {
      used[nv] = 1 - used[v];
      dfsColor(v);
    }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  grl.assign(n, vector<int>());
  grp.assign(n, vector<int>());
  grpp.assign(n, vector<int>());
  int kp = 0;
  for (int i = 0; i < m; ++i) {
    int v1, v2, w;
    scanf("%d%d%d", &v1, &v2, &w);
    --v1;
    --v2;
    if (w) {
      koll[v1]++;
      koll[v2]++;
      grl[v1].push_back(v2);
      grl[v2].push_back(v1);
    } else {
      kp++;
      kolp[v1]++;
      kolp[v2]++;
      grp[v1].push_back(v2);
      grp[v2].push_back(v1);
    }
  }
  comp.assign(n, -1);
  numcomp = 0;
  for (size_t i = 0; i < n; ++i)
    if (comp[i] < 0) {
      dfsComp(i);
      numcomp++;
    }
  for (int i = 0; i < n; ++i)
    for (int nv : grp[i]) {
      grpp[comp[i]].push_back(comp[nv]);
      grpp[comp[nv]].push_back(comp[i]);
    }
  int ans = (MOD + 1) / 2;
  used.assign(n, -1);
  for (size_t i = 0; i < numcomp; ++i)
    if (used[i] < 0) {
      used[i] = 0;
      dfsColor(i);
      ans += ans;
      if (ans >= MOD) ans -= MOD;
    }
  out(ans);
  return 0;
}
