#include <bits/stdc++.h>
using namespace std;
const long long inf = ~0ull >> 1;
int q;
int b, w;
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &b, &w);
    int a = min(b, w);
    if (a == b && w > 3 * b + 1) {
      printf("NO\n");
      continue;
    }
    if (a == w && b > 3 * w + 1) {
      printf("NO\n");
      continue;
    }
    if (a == b) {
      printf("YES\n");
      for (int i = 0; i < b; i++) {
        printf("%d %d\n", 3 + i * 2, 2);
        printf("%d %d\n", 2 + i * 2, 2);
      }
      w -= b;
      if (w) printf("%d %d\n", 2 + b * 2, 2);
      w--;
      if (w) {
        int d = min(w, b);
        for (int i = 0; i < d; i++) {
          printf("%d %d\n", 3 + i * 2, 1);
        }
        w -= d;
      }
      if (w) {
        int d = min(w, b);
        for (int i = 0; i < d; i++) {
          printf("%d %d\n", 3 + i * 2, 3);
        }
        w -= d;
      }
      continue;
    }
    if (a == w) {
      printf("YES\n");
      for (int i = 0; i < b; i++) {
        printf("%d %d\n", 2 + i * 2, 2);
        printf("%d %d\n", 1 + i * 2, 2);
      }
      b -= w;
      if (b) printf("%d %d\n", 1 + b * 2, 2);
      b--;
      if (b) {
        int d = min(w, b);
        for (int i = 0; i < d; i++) {
          printf("%d %d\n", 2 + i * 2, 1);
        }
        b -= d;
      }
      if (b) {
        int d = min(w, b);
        for (int i = 0; i < d; i++) {
          printf("%d %d\n", 2 + i * 2, 3);
        }
        b -= d;
      }
      continue;
    }
  }
  return 0;
}
