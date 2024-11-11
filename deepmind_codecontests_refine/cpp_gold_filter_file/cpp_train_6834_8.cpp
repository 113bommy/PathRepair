#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int k;
  while (~scanf("%d", &k)) {
    if (k > 36)
      printf("-1\n");
    else {
      int even = k / 2;
      int odd = k % 2;
      for (int i = 0; i < even; ++i) {
        putchar('8');
      }
      for (int i = 0; i < odd; ++i) {
        putchar('6');
      }
      printf("\n");
    }
  }
  return 0;
}
