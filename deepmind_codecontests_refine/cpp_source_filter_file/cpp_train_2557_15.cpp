#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10000000")
using namespace std;
const int c = 1000500;
int n, m, k;
vector<int> e[c];
int nk;
int p[c], s;
bool b[c];
void go(int i) {
  int j;
  b[i] = 1;
  ++p[nk];
  for (j = 0; j < e[i].size(); ++j)
    if (!b[e[i][j]]) go(e[i][j]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int i, j, t;
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &j, &t);
    e[j].push_back(t);
    e[t].push_back(j);
  }
  for (i = 1; i <= n; ++i)
    if (!b[i]) {
      ++nk;
      go(i);
    }
  int ans;
  if (k == 1)
    ans = nk - 2;
  else {
    s = 0;
    for (i = 1; i <= nk; ++i) s += min(k, p[i]);
    ans = max(0, nk - 1 - s / 2);
  }
  printf("%d\n", ans);
  return 0;
}
