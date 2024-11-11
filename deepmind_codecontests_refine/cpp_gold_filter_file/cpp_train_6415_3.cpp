#include <bits/stdc++.h>
using namespace std;
int main() {
  int Q;
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    int val;
    scanf("%d", &val);
    if (val % 4 == 0) {
      if (val < 4) {
        printf("-1\n");
      } else {
        printf("%d\n", val / 4);
      }
    }
    if (val % 4 == 1) {
      if (val < 9) {
        printf("-1\n");
      } else {
        printf("%d\n", (val - 9) / 4 + 1);
      }
    }
    if (val % 4 == 2) {
      if (val < 6) {
        printf("-1\n");
      } else {
        printf("%d\n", (val - 6) / 4 + 1);
      }
    }
    if (val % 4 == 3) {
      if (val < 15) {
        printf("-1\n");
      } else {
        printf("%d\n", (val - 15) / 4 + 2);
      }
    }
  }
  return 0;
}
