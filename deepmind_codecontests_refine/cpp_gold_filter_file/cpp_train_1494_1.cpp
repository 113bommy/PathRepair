#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 2e5 + 10;
int n, m, k;
vector<int> G[maxn];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    G[x].push_back(i);
  }
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    int l = 0, sum = 1, dis = 0;
    for (int r = 1; r < G[i].size(); r++) {
      int w = G[i][r] - G[i][r - 1] - 1;
      dis += w;
      sum++;
      while (dis > k) {
        dis -= (G[i][l + 1] - G[i][l] - 1);
        sum--;
        l++;
      }
      ans = max(ans, sum);
    }
  }
  printf("%d\n", ans);
  return 0;
}
