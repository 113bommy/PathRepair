#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, z, d[100010], p[100010];
vector<long long int> G[100010], grp[1010];
void dfs(int x, int y, int z) {
  p[x] = y;
  d[x] = z;
  grp[d[x] % (k - 1)].push_back(x);
  for (int w : G[x])
    if (w != y) {
      if (d[w]) {
        if (d[x] - d[w] >= k - 1) {
          cout << 2 << endl;
          cout << d[x] - d[w] + 1 << endl;
          for (int i = x; i != w; i = p[i]) cout << i << " ";
          cout << w;
          exit(0);
        }
      } else
        dfs(w, x, z + 1);
    }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (k = 1; k * k < n; k++)
    ;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a == b) continue;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, 1, 1);
  cout << 1 << endl;
  for (int i = 0;; i++) {
    if (grp[i].size() >= k) {
      for (int j = 0; j < k; j++) cout << grp[i][j] << " ";
      exit(0);
    }
  }
}
