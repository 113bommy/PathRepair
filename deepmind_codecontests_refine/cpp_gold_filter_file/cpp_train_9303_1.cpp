#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[55], p, cnt;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (m <= k)
    printf("0");
  else {
    sort(a, a + n);
    p = n - 1;
    cnt = k;
    while (p >= 0) {
      cnt--;
      cnt += a[p--];
      if (cnt >= m) {
        printf("%d", n - p - 1);
        return 0;
      }
    }
    printf("-1");
  }
  return 0;
}
