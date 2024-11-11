#include <bits/stdc++.h>
using namespace std;
int len, bD, aD, n, lw;
int dist[105];
pair<int, int> w[1005], ans[1005];
int main() {
  scanf("%d%d%d%d", &len, &bD, &aD, &n);
  w[lw++] = make_pair(-bD - 1, -bD);
  w[lw++] = make_pair(len + bD, len + bD + 1);
  for (int i = 0; i <= len; ++i) ans[i] = make_pair(-1, 0);
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d%d", &t, &dist[i]);
    if (t == 1) {
      for (int j = 0; j < lw - 1; ++j)
        if (w[j].second + bD + dist[i] + aD <= w[j + 1].first) {
          ans[i] = w[lw++] =
              make_pair(w[j].second + bD, w[j].second + bD + dist[i]);
          sort(w, w + lw);
          break;
        }
      printf("%d\n", ans[i].first);
    } else {
      int k = dist[i] - 1, j;
      for (j = 0; j < lw; ++j)
        if (w[j] == ans[k]) break;
      swap(w[j], w[lw - 1]);
      --lw;
      sort(w, w + lw);
    }
  }
  return 0;
}
