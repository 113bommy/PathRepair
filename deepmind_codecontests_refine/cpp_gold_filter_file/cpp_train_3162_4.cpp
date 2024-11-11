#include <bits/stdc++.h>
using namespace std;
const int NMAX = 101;
vector<pair<int, int> > g[NMAX];
bool usd[NMAX];
bool flag;
int l = 0, r = 0, f;
void dfs(int v) {
  usd[v] = true;
  flag = true;
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i].second;
    if (!usd[to]) {
      flag = false;
      r += g[v][i].first;
      dfs(to);
    }
    if (to == f) {
      r += g[v][i].first;
      break;
    }
  }
  if (((int)g[v].size() == 0) || (flag)) {
    for (int i = 0; i < NMAX; i++)
      if (!usd[i])
        for (int j = 0; j < (int)g[i].size(); j++) {
          int to = g[i][j].second;
          if (to == v) {
            l += g[i][j].first;
            dfs(i);
          }
        }
  }
}
int n, a, b, c;
int main() {
  memset(usd, false, sizeof usd);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    g[a].push_back(pair<int, int>(c, b));
  }
  for (int i = 0; i < n; i++) {
    if ((int)g[i].size() == 1) {
      f = i;
      break;
    }
  }
  dfs(f);
  if (l == r)
    printf("0");
  else if (l < r)
    printf("%d", l);
  else
    printf("%d", r);
  return 0;
}
