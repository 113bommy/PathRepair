#include <bits/stdc++.h>
using namespace std;
void syntex_error() {
  long long i, j, k, l, r, n, m, a, b, c, x, y, z, sum = 0LL;
  cin >> n;
  vector<long long> pos[n + 10];
  long long dis[n + 10];
  long long ans[n + 10];
  memset(dis, -1, sizeof(dis));
  ;
  memset(ans, -1, sizeof(ans));
  ;
  for (i = 0; i < n; i++) {
    cin >> x;
    pos[x].push_back(i + 1);
  }
  for (i = 1; i <= n; i++) {
    if ((int)pos[i].size() == 0) continue;
    x = 0;
    for (auto now : pos[i]) {
      dis[i] = max(dis[i], now - x);
      x = now;
    }
    dis[i] = max(dis[i], n - x + 1);
  }
  x = n;
  for (i = 1; i <= n; i++) {
    if (dis[i] == -1) continue;
    for (j = dis[i]; j <= x; j++) ans[j] = i;
    x = min(x, dis[i] - 1);
  }
  for (i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long TC = 1LL;
  cin >> TC;
  while (TC--) {
    syntex_error();
  }
  return 0;
}
