#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5;
int n, minX, maxX, minY, maxY;
pair<int, int> p[MAXN];
int main() {
  scanf("%d", &n);
  minX = minY = 1e9;
  maxX, maxY = -1e9;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].first, &p[i].second);
    minX = min(minX, p[i].first);
    maxX = max(maxX, p[i].first);
    minY = min(minY, p[i].second);
    maxY = max(maxY, p[i].second);
  }
  int generalAns = 2 * (maxX - minX) + 2 * (maxY - minY);
  int ans3 = 0;
  pair<int, int> crit[4] = {
      pair<int, int>(1e9, 1e9), pair<int, int>(-1e9, -1e9),
      pair<int, int>(-1e9, -1e9), pair<int, int>(1e9, 1e9)};
  for (int i = 0; i < n; ++i) {
    if (crit[0].first > p[i].first) {
      crit[0] = p[i];
    }
    if (crit[1].first < p[i].first) {
      crit[1] = p[i];
    }
    if (crit[2].second < p[i].second) {
      crit[2] = p[i];
    }
    if (crit[3].second > p[i].second) {
      crit[3] = p[i];
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      for (int k = 0; k < n; ++k) {
        int tmp = abs(crit[i].first - crit[j].first) +
                  abs(crit[i].second - crit[j].second);
        tmp +=
            abs(crit[j].first - p[k].first) + abs(crit[j].second - p[k].second);
        tmp +=
            abs(p[k].first - crit[i].first) + abs(p[k].second - crit[i].second);
        ans3 = max(ans3, tmp);
      }
    }
  }
  printf("%d", ans3);
  for (int i = 4; i <= n; ++i) {
    printf(" %d", generalAns);
  }
  printf("\n");
}
