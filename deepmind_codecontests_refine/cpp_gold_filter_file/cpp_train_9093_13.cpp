#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, h, f[maxn];
int main() {
  while (scanf("%d%d", &n, &h) != EOF) {
    int k = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &f[i]);
      if (f[i] < f[k]) k = i;
    }
    if (n == 2)
      printf("0\n1 1\n");
    else {
      sort(f, f + n);
      int x = f[n - 1] + f[n - 2] - f[0] - f[1];
      int y = max(f[0] + f[n - 1] + h, f[n - 1] + f[n - 2]) -
              min(f[0] + f[1] + h, f[1] + f[2]);
      if (x <= y) {
        printf("%d\n1", x);
        for (int i = 1; i < n; ++i) printf(" 1");
        printf("\n");
      } else {
        printf("%d\n", y);
        for (int i = 0; i < n; ++i) {
          if (i) printf(" ");
          if (i == k)
            printf("1");
          else
            printf("2");
        }
        printf("\n");
      }
    }
  }
  return 0;
}
