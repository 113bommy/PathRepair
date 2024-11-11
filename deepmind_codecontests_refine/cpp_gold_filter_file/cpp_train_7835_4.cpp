#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int sum = 0, n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    sort(a, a + n);
    if (sum > 0) {
      puts("YES");
      printf("%d", a[n - 1]);
      for (i = n - 2; i >= 0; i--) {
        printf(" %d", a[i]);
      }
      puts("");
    } else if (sum < 0) {
      puts("YES");
      printf("%d", a[0]);
      for (i = 1; i < n; i++) {
        printf(" %d", a[i]);
      }
      puts("");
    } else
      puts("NO");
  }
  return 0;
}
