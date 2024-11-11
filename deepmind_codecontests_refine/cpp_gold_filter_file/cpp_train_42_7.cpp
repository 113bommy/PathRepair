#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N], g2[N];
int n;
long long ret;
int main() {
  scanf("%d", &n);
  for (int i = 0, x, y; i < n; ++i) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g2[y].push_back(x);
  }
  for (int i = 0; i < N; ++i) {
    sort(g[i].begin(), g[i].end());
    sort(g2[i].begin(), g2[i].end());
  }
  for (int x = 0; x < N; ++x) {
    for (auto y : g[x]) {
      int l = upper_bound(g[x].begin(), g[x].end(), y) - g[x].begin();
      int r = upper_bound(g2[y].begin(), g2[y].end(), x) - g2[y].begin();
      while (l < (int)g[x].size() && r < (int)g2[y].size()) {
        int yy = g[x][l], xx = g2[y][r];
        if (xx - x < yy - y)
          ++r;
        else if (xx - x > yy - y)
          ++l;
        else {
          ret += binary_search(g[xx].begin(), g[xx].end(), yy);
          ++l, ++r;
        }
      }
    }
  }
  printf("%lld\n", ret);
  return 0;
}
