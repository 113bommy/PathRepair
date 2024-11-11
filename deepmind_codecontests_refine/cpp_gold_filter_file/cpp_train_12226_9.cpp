#include <bits/stdc++.h>
using namespace std;
int main() {
  int dui, sheng;
  scanf("%d%d", &dui, &sheng);
  if (sheng <= (dui - 1) / 2) {
    printf("%d\n", dui * sheng);
    for (int i = 0; i < dui; i++) {
      for (int t = 1; t <= sheng; t++) {
        printf("%d %d\n", i + 1, (i + t) % dui + 1);
      }
    }
  } else
    printf("-1");
}
