#include <bits/stdc++.h>
const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
using namespace std;
int a[11][11][11], n, m, k, x, y;
bool used[11][11][11];
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
char ss[11];
void dfs(int ii, int jj, int kk) {
  if (a[ii][jj][kk] == 1) return;
  if (used[ii][jj][kk] == true) return;
  used[ii][jj][kk] = true;
  for (int i = 0; i < 6; i++) {
    int inow = ii + dx[i];
    int jnow = jj + dy[i];
    int know = kk + dz[i];
    if (min(inow, min(jnow, know)) == -1) continue;
    if (inow == n || jnow == m || know == k) continue;
    dfs(inow, jnow, know);
  }
}
int main(int argc, const char* argv[]) {
  cin >> k >> n >> m;
  gets(ss);
  gets(ss);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      gets(ss);
      for (int k = 0; k < m; k++)
        if (ss[k] == '#') a[j][k][i] = 1;
    }
    gets(ss);
  }
  cin >> x >> y;
  --x;
  --y;
  dfs(x, y, 1);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int kk = 0; kk < k; kk++) ans += used[i][j][kk];
  cout << ans;
  return 0;
}
