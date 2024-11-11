#include <bits/stdc++.h>
using namespace std;
int val[100009], pr[100009];
bool col[100009];
int cnt[2][100009 * 200];
vector<int> edge[100009];
long long int sz[2];
int dfs(int s) {
  int i, v;
  for (i = 0; i < edge[s].size(); i++) {
    v = edge[s][i];
    col[s] = dfs(v);
  }
  if (i == 0)
    col[s] = 0;
  else
    col[s] = 1 - col[s];
  sz[col[s]]++;
  cnt[col[s]][val[s]]++;
  return col[s];
}
int main() {
  int n, i, j;
  long long int r, exor;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (i = 2; i <= n; i++) {
    scanf("%d", &pr[i]);
    edge[pr[i]].push_back(i);
  }
  i = dfs(1);
  exor = 0;
  for (i = 1; i <= n; i++) {
    if (!col[i]) {
      exor ^= val[i];
    }
  }
  if (exor == 0) {
    r = (sz[0] * (sz[0] - 1)) / 2 + (sz[1] * (sz[1] - 1)) / 2;
    for (i = 1; i <= n; i++) {
      if (col[i]) r += cnt[0][val[i]];
    }
  } else {
    r = 0;
    for (i = 1; i <= n; i++) {
      if (col[i]) {
        r += cnt[0][exor ^ val[i]];
      }
    }
  }
  printf("%lld\n", r);
  return 0;
}
