#include <bits/stdc++.h>
using namespace std;
const int Max = 1e6 + 5;
int tx[Max], ty[Max], x[Max], y[Max], dis[Max], ma[Max];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (int i = 1; i <= m; i++) cin >> tx[i] >> ty[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (x[i] > tx[j] || y[i] > ty[j]) continue;
      dis[tx[j] - x[i] + 1] = max(dis[tx[j] - x[j] + 1], ty[j] - y[i] + 1);
    }
  }
  for (int i = 1e6; i >= 0; i--) ma[i] = max(ma[i + 1], dis[i]);
  int ans = 1e9;
  for (int i = 0; i <= 1e6; i++) {
    ans = min(ans, i + ma[i + 1]);
  }
  cout << ans << endl;
}
