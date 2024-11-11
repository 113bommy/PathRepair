#include <bits/stdc++.h>
using namespace std;
int h, a[10001], s;
bool p = 1;
int main() {
  scanf("%d", &h);
  for (int i = 0; i <= h; i++) {
    scanf("%d", a + i);
    s += a[i];
  }
  for (int i = 1; i <= h; i++) {
    if (a[i] > 1 && a[i - 1] > 1) p = 0;
  }
  if (p) {
    printf("perfect\n");
  } else {
    printf("ambiguous\n");
    int par = 0;
    int c = 0;
    for (int i = 0; i <= h; i++) {
      for (int j = 0; j < a[i]; j++) {
        printf("%d ", par);
        c += 1;
      }
      par = c;
    }
    printf("\n");
    par = 0;
    c = 0;
    for (int i = 0; i <= h; i++) {
      for (int j = 0; j < a[i]; j++) {
        if (i > 0 && a[i - 1] > 1)
          printf("%d ", (j % 2) ? par : par - 1);
        else
          printf("%d ", par);
        c += 1;
      }
      par = c;
    }
    printf("\n");
  }
  return 0;
}
