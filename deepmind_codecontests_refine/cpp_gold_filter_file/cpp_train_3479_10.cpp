#include <bits/stdc++.h>
using namespace std;
int a[5005];
int ans[5005 * 2];
int main() {
  int m, t, n = 0, maxx = 0;
  scanf("%d", &m);
  memset(a, 0, sizeof(a));
  for (int i = 0; i < m; i++) {
    scanf("%d", &t);
    a[t]++;
  }
  for (int i = 1; i < 5005; i++) {
    if (a[i] != 0) {
      a[i]--;
      ans[n] = i;
      n++;
      maxx = i;
    }
  }
  for (int i = maxx - 1; i >= 1; i--) {
    if (a[i] != 0) {
      ans[n] = i;
      n++;
    }
  }
  printf("%d\n", n);
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", ans[i]);
  }
  printf("%d\n", ans[n - 1]);
  return 0;
}
