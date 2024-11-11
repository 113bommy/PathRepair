#include <bits/stdc++.h>
using namespace std;
int mas[4000][4000] = {0}, i, j, vers[4000] = {0}, n, k, m, u, v, ans = 0, sum,
    b;
void dfs(int ver) {
  for (int fi = 1; fi <= n; ++fi)
    if (mas[ver][fi] == 1 && vers[fi] == 0) {
      vers[fi] = 1;
      dfs(fi);
    } else if (mas[ver][fi] == -1 && vers[fi] == 1)
      b = 0;
}
int main() {
  cin >> n >> k;
  for (i = 0; i < k; ++i) {
    cin >> u >> v;
    mas[u][v] = mas[v][u] = 1;
  }
  cin >> m;
  for (i = 0; i < m; ++i) {
    cin >> u >> v;
    mas[u][v] = mas[v][u] = -1;
  }
  for (i = 1; i <= n; ++i) {
    for (j = 1; j <= n; ++j) vers[j] = 0;
    b = 1;
    vers[i] = 1;
    dfs(i);
    sum = 0;
    if (b == 1) {
      for (j = 1; j <= n; ++j)
        if (vers[j] == 1) ++sum;
      if (ans < sum) ans = sum;
    }
  }
  cout << ans;
  return 0;
}
