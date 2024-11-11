#include <bits/stdc++.h>
using namespace std;
int n, a[100005], maxx[100005];
int main(void) {
  int i, j;
  while (~scanf("%d", &n)) {
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    maxx[n - 1] = 0;
    for (i = n - 2; i >= 0; i--) maxx[i] = max(maxx[i + 1], a[i + 1]);
    for (i = 0; i < n; i++) {
      if (a[i] >= maxx[i])
        printf("0 ");
      else
        printf("%d ", maxx[i] + 1 - a[i]);
    }
    puts("");
  }
  return 0;
}
