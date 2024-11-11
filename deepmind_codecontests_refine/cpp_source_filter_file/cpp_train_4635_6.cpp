#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e13;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  char ch[n][m];
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) cin >> ch[i][j];
  long long int dph[n][m], dpv[n][m];
  for (long long int i = 0; i < n; i++) {
    long long int sh = 0, sv = 0;
    for (long long int j = 0; j < m; j++) {
      if (j != 0 and ch[i][j] == '.' and ch[i][j - 1] == '.') sh++;
      if (i != 0 and ch[i - 1][j] == '.' and ch[i][j] == '.') sv++;
      dph[i][j] = sh;
      if (i - 1 >= 0) dph[i][j] += dph[i - 1][j];
      dpv[i][j] = sv;
      if (i - 1 >= 0) dpv[i][j] += dpv[i - 1][j];
    }
  }
  long long int q;
  cin >> q;
  while (q--) {
    long long int x, y, a, b;
    cin >> x >> y >> a >> b;
    x--;
    y--;
    a--;
    b--;
    long long int ans = dph[a][b] - dph[a][y];
    ans += (dpv[a][b] - dpv[x][b]);
    if (y - 1 >= 0) {
      ans -= dpv[a][y - 1];
    }
    if (x - 1 >= 0) {
      ans -= dph[x - 1][b];
    }
    if (x - 1 >= 0 and y - 1 >= 0) {
      ans += dpv[x][y];
      ans += dph[x - 1][y - 1];
    }
    cout << ans << "\n";
  }
}
