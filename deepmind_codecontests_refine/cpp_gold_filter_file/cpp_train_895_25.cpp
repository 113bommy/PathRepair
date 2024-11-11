#include <bits/stdc++.h>
const int N = 2e5 + 5;
std::bitset<(1 << 12)> a[N];
int cnt;
std::vector<std::pair<int, int> > v[N];
int main() {
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  cnt = k;
  for (int i = 1; i <= k; i++)
    for (int j = 1, x; j <= n; j++)
      scanf("%d", &x), v[j].push_back(std::make_pair(x, i));
  for (int j = 1; j <= n; j++) std::sort(v[j].begin(), v[j].end());
  for (int i = 1; i <= k; i++)
    for (int s = 0; s < (1 << k); s++)
      if (s & (1 << i - 1)) a[i][s] = 1;
  while (q--) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    if (op == 1)
      a[++cnt] = a[x] & a[y];
    else if (op == 2)
      a[++cnt] = a[x] | a[y];
    else {
      int sta = 0;
      for (int j = 0; j < k; j++) {
        sta += (1 << v[y][j].second - 1);
        if (a[x][sta] == 1) {
          printf("%d\n", v[y][j].first);
          break;
        }
      }
    }
  }
  return 0;
}
