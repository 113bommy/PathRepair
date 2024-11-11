#include <bits/stdc++.h>
using namespace std;
int n, a[1005];
int res = 1000000000, of, sta;
void check(int m) {
  int maxi = -1, mini = -1, x = -20000, i, first = 1000000000;
  for (i = 1; i <= n; i++) {
    if (x - a[i] <= 0) {
      maxi = max(maxi, a[i] - x);
      if (a[i] - x < first) first = a[i] - x;
    } else
      mini = max(mini, x - a[i]);
    x += m;
  }
  if (mini != -1 && mini >= res) return;
  if (res > max(maxi, mini)) {
    res = max(maxi, mini);
    of = m;
    sta = -20000;
  }
  x = -20000;
  for (i = 1;; i++) {
    if (mini == -1) {
      if (first == 0) mini = 1;
    } else
      mini++;
    maxi--;
    first--;
    if (mini != -1 && mini >= res) return;
    if (res > max(maxi, mini)) {
      res = max(maxi, mini);
      of = m;
      sta = x + i;
    }
  }
}
int main() {
  int i, m;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (m = 0; m <= 10000; m++) {
    check(m);
  }
  printf("%d\n%d %d\n", res, sta, of);
  return 0;
}
