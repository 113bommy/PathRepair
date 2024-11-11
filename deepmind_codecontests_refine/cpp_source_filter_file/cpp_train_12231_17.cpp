#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], ans[N];
int main() {
  int n, i, k, x, f;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", a + i);
  for (i = 0; i < n; i++) {
    for (k = 1; k < n;) {
      x = (i + k - 1) / k;
      f = 0;
      if (a[x - 1] > a[i]) {
        ans[k]++;
        f = 1;
      }
      if (x <= 1) break;
      k = (i + x - 2) / (x - 1);
      if (f) ans[k]--;
    }
  }
  for (i = 1; i < n; i++) {
    ans[i] += ans[i - 1];
    printf("%d ", ans[i]);
  }
}
