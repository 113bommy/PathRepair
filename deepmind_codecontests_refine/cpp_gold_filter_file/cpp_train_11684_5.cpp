#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int ara[n], cnt = 0, x = INT_MAX, cnt1 = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &ara[i]);
      if (ara[i] % 2 == 0) {
        x = i + 1;
      }
    }
    if (x != INT_MAX) {
      printf("1\n%d\n", x);
    } else {
      for (i = 0; i < n; i++) {
        cnt += ara[i];
        cnt1++;
        if (cnt % 2 == 0) {
          break;
        }
      }
      if (cnt != 0 && cnt % 2 == 0) {
        printf("%d\n", cnt1);
        for (i = 0; i < 2; i++) {
          printf("%d ", i + 1);
        }
        printf("\n");
      } else {
        printf("-1\n");
      }
    }
  }
  return 0;
}
