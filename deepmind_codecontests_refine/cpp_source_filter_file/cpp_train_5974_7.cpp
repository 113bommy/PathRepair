#include <bits/stdc++.h>
using namespace std;
int flag[100000];
int main() {
  int n, k, i;
  memset(flag, 0, sizeof(flag));
  scanf("%d%d", &n, &k);
  long long a[100000];
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
  sort(a, a + n);
  int sum = n;
  for (i = 0; i < n; i++) {
    if (!flag[i]) {
      long long v = k * a[i];
      if (v > a[n - 1]) continue;
      int r, l, mid;
      r = n;
      l = i + 1;
      while (r >= l) {
        mid = (r + l) / 2;
        if (v > a[mid])
          l = mid + 1;
        else if (v < a[mid])
          r = mid - 1;
        else {
          flag[i] = 1;
          sum--;
          break;
        }
      }
    }
  }
  printf("%d\n", sum);
}
