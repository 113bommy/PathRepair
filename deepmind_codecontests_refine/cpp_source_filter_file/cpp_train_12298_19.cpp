#include <bits/stdc++.h>
const int MAX = 2e9;
const int MIN = -2e9;
const double eps = 1e-8;
const double PI = acos(-1.0);
using namespace std;
const int N = 105;
int st[N], ed[N];
int main() {
  int n, p1, p2, p3, t1, t2;
  while (~scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2)) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &st[i], &ed[i]);
      ans += (ed[i] - st[i]) * p1;
    }
    for (int i = 1; i < n; ++i) {
      int t = st[i] - ed[i - 1];
      if (t < t1) {
        ans += t * p1;
      } else if (t < t2) {
        ans += t1 * p1 + (t - t1) * p2;
      } else {
        ans += t1 * p1 + t2 * p2 + (t - (t1 + t2)) * p3;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
