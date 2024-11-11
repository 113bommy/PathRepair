#include <bits/stdc++.h>
using namespace std;
const int n = 8;
const int lcmx = 3360;
const int lmt = lcmx * n;
long long W;
long long cnt[n];
bool vis[lmt + 1];
int d[lmt + 1];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> W;
  for (int i = 0; i < n; i++) cin >> cnt[i];
  long long pkg = 0;
  for (int i = 0; i < n; i++) {
    int c = lcmx / (i + 1);
    pkg += cnt[i] / c;
    cnt[i] %= c;
  }
  vis[0] = true;
  for (int i = 0; i < n; i++) {
    memset(d, 0, sizeof d[0] * (lmt + 1));
    for (int x = 0; x <= lmt; x++) {
      if (!vis[x] || d[x] >= cnt[i]) continue;
      if (x + i + 1 <= lmt && !vis[x + i + 1]) {
        vis[x + i + 1] = true;
        d[x + i + 1] = d[x] + 1;
      }
    }
  }
  long long ans = 0;
  for (int x = 0; x <= lmt && x <= W; x++) {
    if (vis[x]) ans = max(ans, min(pkg, (W - x) / lcmx) * lcmx + x);
  }
  cout << ans << '\n';
  return 0;
}
