#include <bits/stdc++.h>
using namespace std;
int n;
int a[20];
bool b[5001] = {};
int main() {
  scanf("%d", &n);
  a[0] = 1, a[1] = 2;
  b[1] = b[2] = b[3] = true;
  for (int i = 2; i < n; ++i) {
    for (int j = 1; j <= 1000; ++j)
      if (!b[j]) {
        bool ok = true;
        for (int k = 0; k < (int)(i); ++k)
          if (b[j + a[k]]) {
            ok = false;
            break;
          }
        if (ok) {
          for (int k = 0; k < (int)(i); ++k) b[j + a[k]] = true;
          b[j] = true;
          a[i] = j;
          break;
        }
      }
  }
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(n); ++j)
      if (j == i) {
        printf("0 ");
      } else {
        printf("%d ", a[i] + a[j]);
      }
    printf("\n");
  }
  return 0;
}
