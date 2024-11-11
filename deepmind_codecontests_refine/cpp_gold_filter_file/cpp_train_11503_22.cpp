#include <bits/stdc++.h>
using namespace std;
const int M = 100001;
int n, m, d[M], h[M], sig = 0, ans = 0;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> d[i] >> h[i];
    if (i == 1) {
      ans = d[i] + h[i] - 1;
      continue;
    }
    if (abs(h[i] - h[i - 1]) > (d[i] - d[i - 1])) sig = 1;
    int tmp =
        max(h[i], h[i - 1]) + ((d[i] - d[i - 1]) - abs(h[i] - h[i - 1])) / 2;
    ans = max(ans, max(h[i], tmp));
  }
  ans = max(ans, h[m] + n - d[m]);
  if (sig)
    cout << "IMPOSSIBLE";
  else
    cout << ans;
  return 0;
}
