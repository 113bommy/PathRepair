#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int K, c, x, y, m, n, cnt, t, mx;
pair<pair<int, int>, int> a[maxn + 5];
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= int(n); i++) {
    scanf("%d%d%d%d%d", &K, &c, &x, &y, &m);
    t = 0;
    for (int j = (1); j <= int(K); j++) {
      if (cnt <= maxn) a[++cnt] = make_pair(make_pair(t, c), i);
      if (j < K && c > (1LL * c * x + y) % m) t++;
      c = (1LL * c * x + y) % m;
    }
    mx = max(mx, t);
  }
  sort(a + 1, a + cnt + 1);
  printf("%d\n", mx);
  if (cnt <= maxn)
    for (int i = (1); i <= int(cnt); i++)
      printf("%d %d\n", a[i].first.second, a[i].second);
  return 0;
}
