#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%1d", &a[i]);
  }
  printf("%d\n", n);
  bool ok = 1;
  for (int i = k + 1; i <= n; ++i) {
    if (a[i] < a[i - k]) {
      break;
    } else if (a[i] > a[i - k]) {
      ok = 0;
      break;
    }
  }
  if (!ok) {
    a[k]++;
    for (int i = k; i >= 1; --i) {
      if (a[i] >= 10) {
        a[i] -= 10;
        a[i - 1]++;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (i <= k) {
      printf("%d", a[i]);
    } else
      printf("%d", a[i] = a[i - k]);
  }
  puts("");
}
