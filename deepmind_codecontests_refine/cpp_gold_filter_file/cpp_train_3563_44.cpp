#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const int N = 1e6 + 5;
int n, k;
bool color[81];
int a[81][81];
long long dis[11][81];
int v[2][81];
long long getColor() {
  v[0][0] = 0;
  v[1][0] = 0;
  for (int i = 1; i <= n; ++i) {
    color[i] = rand() % 2;
    int *cur = v[color[i]];
    cur[++cur[0]] = i;
  }
  memset(dis, INF, sizeof(dis));
  dis[0][1] = 0;
  for (int ki = 1; ki <= k; ++ki) {
    for (int i = 1; i <= n; ++i) {
      int *other = v[1 ^ color[i]];
      for (int ji = 1; ji <= other[0]; ++ji) {
        int j = other[ji];
        dis[ki][i] = min(dis[ki][i], dis[ki - 1][j] + a[i][j]);
      }
    }
  }
  return dis[k][1];
}
void solve() {
  srand(time(0));
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) scanf("%lld", &a[i][j]);
  }
  long long ans = 1e18;
  for (int i = 1; i <= 20000; ++i) ans = min(ans, getColor());
  printf("%lld\n", ans);
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
