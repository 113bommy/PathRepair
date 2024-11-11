#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k <= (((float)n * n) / 2) + 0.5) {
    printf("YES\n");
    if (n == 5 && k == 2) {
      for (int i = 0; i < n; ++i) {
        if (i & 1) {
          for (int j = 0; j < n; ++j) printf("L");
        } else {
          for (int j = 0; j < n; ++j) printf("S");
        }
        printf("\n");
      }
    } else {
      for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j)
          if (((i + j) & 1) && k > 0) {
            printf("L");
            --k;
          } else
            printf("S");
        printf("\n");
      }
    }
  } else
    printf("NO\n");
  return 0;
}
