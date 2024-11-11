#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n % 2 == 0) {
      int t = (n - 2) / 2 + 2;
      printf("%d\n", t);
      int s = 1, r = 1;
      printf("%d %d\n", s, r);
      for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
          s = i / 2 + 1;
          r = s;
        } else {
          s = i / 2 + 1;
          r = i / 2 + 2;
        }
        printf("%d %d\n", s, r);
      }
    } else {
      int t = (n - 3) / 2 + 2;
      printf("%d\n", t);
      int s = 1, r = 1;
      printf("%d %d\n", s, r);
      for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
          s = i / 2 + 1;
          r = s;
        } else {
          s = i / 2 + 1;
          r = i / 2 + 2;
        }
        printf("%d %d\n", s, r);
      }
    }
  }
}
