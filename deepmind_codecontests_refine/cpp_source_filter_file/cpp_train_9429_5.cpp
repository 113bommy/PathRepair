#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(void) {
  int n, i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (n >= 55)
    printf("YES\n");
  else {
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n - 2; i++) {
      if (a[i] + a[i + 1] >= a[i + 2]) {
        printf("YES\n");
        return 0;
      }
    }
    printf("NO\n");
  }
  return 0;
}
