#include <bits/stdc++.h>
using namespace std;
const int N = 600;
int mod;
inline void upd(int& x, const int& y) {
  x += y - mod;
  x += x >> 31 & mod;
}
int f[N][N], n, m, B, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> B >> mod;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = x; j <= B; j++)
      for (int k = 1; k <= m; k++) upd(f[j][k], f[j - x][k - 1]);
  }
  for (int i = 1; i <= B; i++) upd(ans, f[i][m]);
  cout << ans << endl;
  return 0;
}
