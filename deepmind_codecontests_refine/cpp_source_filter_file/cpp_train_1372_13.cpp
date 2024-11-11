#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N], tim[N], st[N][2], t;
inline int find(int x) {
  int ret = 1;
  for (int l = 1, r = t, mid = (l + r >> 1); l <= r; mid = (l + r >> 1))
    if (st[mid][0] > x)
      ret = mid, r = mid - 1;
    else
      l = mid + 1;
  return st[ret][1];
}
int main() {
  scanf("%d", &n);
  t = 1;
  st[t][0] = st[t][1] = -1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int opt, x;
    scanf("%d%d", &opt, &x);
    if (opt == 1)
      scanf("%d", &a[x]), tim[x] = i;
    else {
      while (t > 1 && st[t][1] < x) t--;
      ++t;
      st[t][0] = i;
      st[t][1] = x;
    }
  }
  for (int i = 1; i <= n; i++)
    if (tim[i] > st[t][0])
      printf("%d ", a[i]);
    else
      printf("%d ", max(a[i], find(tim[i])));
  return 0;
}
