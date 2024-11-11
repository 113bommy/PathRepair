#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int inf = 1e9;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long x[n + 1][m + 1];
  long long cum[200][200];
  memset(cum, 0, sizeof(cum));
  int a, b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> x[i][j];
      cum[i][j] = cum[i][j - 1] + x[i][j];
    }
  }
  cin >> a >> b;
  int ans = maxn;
  for (int i = 1; i <= n + 1 - a; i++) {
    for (int j = 1; j <= m + 1 - b; j++) {
      int k = 0;
      int tot = 0;
      while (k < a) {
        tot += ((cum[i + k][j + b - 1]) - cum[i][j - 1]);
        k++;
      }
      ans = min(ans, tot);
    }
  }
  for (int i = 1; i <= n + 1 - b; i++) {
    for (int j = 1; j <= m + 1 - a; j++) {
      int k = 0;
      int tot = 0;
      while (k < b) {
        tot += ((cum[i + k][j + a - 1]) - cum[i][j - 1]);
        k++;
      }
      ans = min(ans, tot);
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  solve();
  return 0;
}
