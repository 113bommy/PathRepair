#include <bits/stdc++.h>
using namespace std;
int a[110], ans[110];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int st = ((n + 1) / 2) - 1, dr = ((n + 1) / 2) + 1, poz = n - 1;
  ans[(n + 1) / 2] = a[n];
  while (st > 0 or dr <= n) {
    if (st > 0) {
      ans[st] = a[poz];
      poz--;
      st--;
    }
    if (dr <= n) {
      ans[dr] = a[poz];
      poz--;
      dr++;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
