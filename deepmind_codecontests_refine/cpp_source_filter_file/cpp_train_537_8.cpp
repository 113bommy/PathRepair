#include <bits/stdc++.h>
using namespace std;
int t, n, k, d, m, ks;
int a[110][110];
int u[110][110];
int ans[110];
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k >> d;
    ks = 0;
    for (int r = 0; r < d; r++) {
      cin >> a[i][r];
      u[a[i][r]][i]++;
      if (u[a[i][r]][i] == 1) ks++;
    }
    m = ks;
    for (int r = d; r < n; r++) {
      cin >> a[i][r];
      if (u[r - d][i] == 1) ks--;
      u[a[i][r - d]][i]--;
      u[a[i][r]][i]++;
      if (u[a[i][r]][i] == 1) ks++;
      m = min(ks, m);
    }
    ans[i] = m;
  }
  for (int i = 0; i < t; i++) cout << ans[i] << '\n';
  return 0;
}
