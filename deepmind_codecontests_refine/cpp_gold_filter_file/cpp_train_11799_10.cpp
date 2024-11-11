#include <bits/stdc++.h>
using namespace std;
pair<int, int> h[1010];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) scanf("%d%d", &h[i].first, &h[i].second);
  sort(h, h + n);
  int ans = 2;
  for (int i = 1; i < n; i++) {
    int d = 2 * h[i].first - h[i].second - 2 * h[i - 1].first - h[i - 1].second;
    if (2 * t == d)
      ans++;
    else if (2 * t < d)
      ans += 2;
  }
  printf("%d\n", ans);
  return 0;
}
