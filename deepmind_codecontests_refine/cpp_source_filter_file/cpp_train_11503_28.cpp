#include <bits/stdc++.h>
using namespace std;
map<int, int> d, dh;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> d[i] >> dh[i];
  }
  int ans = 0;
  for (int i = 2; i <= m; i++) {
    if (0 < abs(dh[i] - dh[i - 1]) - abs(d[i] - d[i - 1])) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    int k = max(dh[i], dh[i - 1]);
    ans = max(ans, (abs(d[i] - d[i - 1]) - abs(dh[i] - dh[i - 1])) / 2 + k);
  }
  ans = max(ans, dh[1] + d[1] - 1);
  ans = max(ans, dh[m] + m - d[m]);
  cout << ans;
}
