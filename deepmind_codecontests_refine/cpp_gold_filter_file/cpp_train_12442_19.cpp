#include <bits/stdc++.h>
using namespace std;
long long ditu[106][106];
int main() {
  int n, m;
  long long ans = -1;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> ditu[i][j];
  for (int i = 1; i <= n; i++) {
    long long xx = 99999999999;
    for (int j = 1; j <= m; j++) {
      xx = min(xx, ditu[i][j]);
    }
    ans = max(ans, xx);
  }
  cout << ans << endl;
}
