#include <bits/stdc++.h>
int dbg = 1;
using namespace std;
int n, far, d, vec[250][250];
void dfs(int cu, int p, int h) {
  if (h >= d) {
    d = h;
    far = cu;
  }
  for (int i = 1; i <= n; i++)
    if (i != p && vec[cu][i]) dfs(i, cu, h + 1);
}
int main() {
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    vec[a][b] = 1;
    vec[b][a] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (vec[i][j]) {
        vec[i][j] = 0;
        vec[j][i] = 0;
        d = 0;
        dfs(i, i, 0);
        d = 0;
        dfs(far, far, 0);
        int one = d;
        d = 0;
        dfs(j, j, 0);
        d = 0;
        dfs(far, far, 0);
        ans = max(ans, d * one);
        vec[i][j] = 1;
        vec[j][i] = 1;
      }
  cout << ans << endl;
  return 0;
}
