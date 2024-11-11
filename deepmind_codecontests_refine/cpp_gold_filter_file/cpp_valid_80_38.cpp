#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e4 + 50;
int a[MAX], n;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%1d", &a[i]);
    int l1 = -1, r1 = -1, l2 = -1, r2 = -1;
    for (int i = n / 2 + 1; i <= n; i++) {
      if (a[i] == 0) {
        l1 = l2 = 1;
        r1 = i;
        r2 = i - 1;
        break;
      }
    }
    if (l1 != -1) {
      printf("%d %d %d %d\n", l1, r1, l2, r2);
      continue;
    }
    for (int i = 1; i <= n / 2; i++) {
      if (a[i] == 0) {
        l1 = i;
        l2 = i + 1;
        r1 = r2 = n;
        break;
      }
    }
    if (l1 != -1) {
      printf("%d %d %d %d\n", l1, r1, l2, r2);
      continue;
    }
    printf("1 %d 1 %d\n", n -= (n & 1), n / 2);
  }
  return 0;
}
