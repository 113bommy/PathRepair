#include <bits/stdc++.h>
using namespace std;
void FJ() {}
int main() {
  int n;
  scanf("%d", &n);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i % 2 == 0)
        printf("#");
      else {
        int p = i % 4;
        if (p == 1) {
          if (j == m - 1)
            printf("#");
          else
            printf(".");
        } else {
          if (j == 0)
            printf("#");
          else
            printf(".");
        }
      }
    }
    if (i != n - 1) puts("");
  }
  return 0;
}
