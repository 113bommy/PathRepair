#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  while (cin >> n >> a >> b) {
    if (n > a * b)
      puts("-1");
    else {
      int l = 1, r = 2;
      for (int i = 0; i < (a); ++i) {
        for (int j = 0; j < (b); ++j) {
          if (j) putchar(' ');
          if ((i + j) % 2 == 0) {
            printf("%d", l <= n ? l : 0);
            l += 2;
          } else {
            printf("%d", r <= n ? r : 0);
            r += 2;
          }
        }
        puts("");
      }
    }
  }
  return 0;
}
