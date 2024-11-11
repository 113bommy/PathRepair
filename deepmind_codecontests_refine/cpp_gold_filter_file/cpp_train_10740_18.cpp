#include <bits/stdc++.h>
using namespace std;
int q, b, w;
int main() {
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int x = 2;
    scanf("%d%d", &b, &w);
    swap(b, w);
    if (b > w) swap(b, w), x = 3;
    if (b * 3 + 1 < w) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    for (int i = 1; i <= b; ++i) printf("%d %d\n", x, i * 2);
    for (int i = 1; i <= b; ++i) {
      printf("%d %d\n", x, i * 2 - 1);
      --w;
    }
    if (w > 0) {
      printf("%d %d\n", x, b * 2 + 1);
      w--;
    }
    if (w > 0) {
      for (int i = 1; i <= b && w > 0; ++i, w--)
        printf("%d %d\n", x + 1, i * 2);
    }
    if (w > 0) {
      for (int i = 1; i <= b && w > 0; ++i, --w)
        printf("%d %d\n", x - 1, i * 2);
    }
  }
  return 0;
}
