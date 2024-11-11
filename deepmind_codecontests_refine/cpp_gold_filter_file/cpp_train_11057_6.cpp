#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > viz[200010];
long long gd[200010];
long long sumB, k;
long long dfs(long long u, long long pai) {
  long long sum = 0;
  for (int i = 0; i < viz[u].size(); i++) {
    int v = viz[u][i].first;
    if (v != pai) {
      long long y = dfs(v, u);
      if (y % 2 == 1) {
        gd[v] = viz[u][i].second;
      } else
        gd[v] = 0;
      sum += y;
      sumB += viz[u][i].second * min(y, 2 * k - y);
    }
  }
  return sum + 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> k;
    for (int i = 1; i <= 2 * k; i++) viz[i].clear();
    for (int i = 1; i <= 2 * k - 1; i++) {
      int a, b, v;
      cin >> a >> b >> v;
      viz[a].push_back({b, v});
      viz[b].push_back({a, v});
    }
    sumB = 0;
    dfs(1, -1);
    long long sumG = 0;
    for (int i = 1; i <= 2 * k; i++) sumG += gd[i];
    printf("%lld %lld\n", sumG, sumB);
  }
}
