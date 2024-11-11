#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const double pi =
    3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int MR = 1e5 + 10;
int maxDeg;
vector<int> g[MR];
bool done[MR];
int t;
vector<pair<int, int> > res;
void dfs(int nr, int wy) {
  assert(wy == t - 1);
  done[nr] = 1;
  res.push_back(make_pair(nr, t));
  int ileC = 0;
  for (int i : g[nr]) ileC += !done[i];
  int we = t;
  if (t == maxDeg && ileC) {
    t = maxDeg - ileC - 1;
    res.push_back(make_pair(nr, t));
  }
  for (int i : g[nr])
    if (!done[i]) {
      ileC--;
      t++;
      dfs(i, t - 1);
      t++;
      res.push_back(make_pair(nr, t));
      if (t == maxDeg && ileC) {
        t = we - ileC;
        res.push_back(make_pair(nr, t));
      }
    }
  assert(t >= wy);
  if (nr && t > wy) {
    t = wy;
    res.push_back(make_pair(nr, t));
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n - 1); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < (n); ++i) maxDeg = max(maxDeg, (int)g[i].size());
  dfs(0, -1);
  printf("%d\n", res.size());
  for (const auto& p : res) printf("%d %d\n", p.first + 1, p.second);
  return 0;
}
