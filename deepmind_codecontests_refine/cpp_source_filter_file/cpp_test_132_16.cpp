#include <bits/stdc++.h>
using namespace std;
long long b[10];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 1; i <= 7; i++) {
      scanf("%d", &b[i]);
    }
    int i, j, k, c;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
    for (i = 1; i <= 7; i++) {
      for (j = i + 1; j <= 7; j++) {
        for (k = j + 1; j <= 7; k++) {
          for (c = 1; c <= 7; c++) {
            if (c != i && c != j && c != k && !f1 && !f2 && !f3 && !f4) {
              if (b[i] + b[j] == b[c]) f1 = 1;
            } else if (c != i && c != j && c != k && f1 == 1 && !f2 && !f3 &&
                       !f4) {
              if (b[i] + b[k] == b[c]) f2 = 1;
            } else if (c != i && c != j && c != k && f1 == 1 && f2 == 1 &&
                       !f3 && !f4) {
              if (b[j] + b[k] == b[c]) f3 = 1;
            } else if (c != i && c != j && c != k && f1 == 1 && f2 == 1 &&
                       f3 == 1 && !f4) {
              if (b[i] + b[j] + b[k] == b[c]) f4 = 1;
            }
            if (f1 && f2 && f3 && f4) break;
          }
          if (f1 && f2 && f3 && f4) break;
        }
        if (f1 && f2 && f3 && f4) break;
      }
      if (f1 && f2 && f3 && f4) break;
    }
    printf("%d %d %d ", b[i], b[j], b[k]);
    printf("\n");
  }
  return 0;
}
