#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main() {
  int t, n, tmp = 1;
  scanf("%d", &t);
  while (t--) {
    tmp = 1;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
      scanf("%c", &a[i]);
    }
    for (int i = 0; i < n / 2; i++) {
      if ((int)a[i] != (int)a[n - 1 - i]) {
        if ((int)(a[i] + 2) != (int)a[n - 1 - i]) {
          if ((int)(a[i] + 2) != (int)a[n - 1 - i]) {
            tmp = 0;
          }
        }
      }
    }
    if (tmp == 0) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
