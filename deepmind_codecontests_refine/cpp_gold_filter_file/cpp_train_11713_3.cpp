#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int n, m;
int p[110];
int px[110];
double f[110][100010];
double ps[110][100010];
void solve() {
  cin >> n >> m;
  if (m == 1) {
    cout << 1;
    return;
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    px[i] = px[i - 1] + p[i];
  }
  f[0][0] = m - 1;
  for (int i = 0; i <= m * n; i++) ps[0][i] = m - 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m * i; j++) {
      f[i][j] = ps[i - 1][j - 1];
      if (j - p[i] >= 0) f[i][j] -= f[i - 1][j - p[i]];
      if (j - m - 1 >= 0) f[i][j] -= ps[i - 1][j - m - 1];
      f[i][j] /= (double)(m - 1);
    }
    for (int j = 0; j <= m * n; j++)
      ps[i][j] = (j ? ps[i][j - 1] : 0) + f[i][j];
  }
  double ans = 1;
  for (int i = 1; i < px[n]; i++) ans += f[n][i];
  cout.precision(15);
  cout << fixed << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(1337);
  solve();
  return 0;
}
