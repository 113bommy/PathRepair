#include <bits/stdc++.h>
using namespace std;
bool solve(int);
int main() {
  int test = 0;
  while (solve(test++))
    ;
  return 0;
}
const int N = 1000 * 1000 + 5;
int n;
vector<int> g[N];
bool sl[N];
bool l[N];
void dfs(int v, int p) {
  int csl = 0, cl = 0, nl = 0;
  for (int i = 0; i < int(int(g[v].size())); ++i) {
    int to = g[v][i];
    if (to != p) {
      dfs(to, v);
      if (sl[to])
        csl++;
      else if (l[to])
        cl++;
      else
        nl++;
    }
  }
  sl[v] = (nl + cl == 0 && csl <= 1);
  l[v] = (nl + cl == 0 && csl <= 2);
}
bool calc(int v, int p, int mx, bool can) {
  int csl = 0, cl = 0, nl = 0;
  vector<int> vv;
  for (int i = 0; i < int(int(g[v].size())); ++i) {
    int to = g[v][i];
    if (to != p) {
      if (sl[to])
        csl++;
      else if (l[to])
        cl++;
      else {
        nl++;
        vv.push_back(to);
      }
    }
  }
  bool res = true;
  if (csl <= 2 && cl == 0 && nl <= 1 && can) {
    for (int i = 0; i < int(int(vv.size())); ++i)
      res &= calc(vv[i], v, mx, csl <= 1);
  } else {
    if (nl > mx)
      res = false;
    else
      for (int i = 0; i < int(int(vv.size())); ++i)
        res &= calc(vv[i], v, 1, false);
  }
  return res;
}
bool solve(int) {
  if (scanf("%d", &n) != 1) return false;
  for (int i = 0; i < int(n); ++i) g[i].clear();
  for (int _ = 0; _ < int(n - 1); ++_) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, 0);
  puts(calc(0, 0, 2, true) ? "Yes" : "No");
  return true;
}
