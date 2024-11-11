#include <bits/stdc++.h>
using namespace std;
const int direc[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
vector<int> v[40];
int deg[40], n;
long long x[40], y[40];
void dfs(int p, int lst, int fath, long long len) {
  int np = 0;
  for (int i = 0; i < v[p].size(); i++) {
    if (v[p][i] == fath) continue;
    np++;
    if (np == 3 - lst) np++;
    x[v[p][i]] = x[p] + len * direc[np][0];
    y[v[p][i]] = y[p] + len * direc[np][1];
    dfs(v[p][i], np, p, len / 3);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, ti, tj; i < n; i++) {
    scanf("%d%d", &ti, &tj);
    ++deg[ti];
    ++deg[tj];
    v[ti].push_back(tj);
    v[tj].push_back(ti);
  }
  for (int i = 1; i <= n; i++) {
    if (deg[i] > 4) {
      puts("NO");
      return 0;
    }
  }
  x[1] = 0;
  y[1] = 0;
  dfs(1, -1, 0, 205891132094649);
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%I64d %I64d\n", x[i], y[i]);
  return 0;
}
