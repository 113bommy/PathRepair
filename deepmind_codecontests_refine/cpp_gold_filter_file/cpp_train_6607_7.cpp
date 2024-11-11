#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, num;
  while (scanf("%d", &num) != EOF) {
    if (num & 1) {
      putchar('1');
      for (i = 2; i < num; i += 2) printf(" %d %d", i + 1, i);
      putchar('\n');
    } else {
      printf("2 1");
      for (i = 3; i < num; i += 2) printf(" %d %d", i + 1, i);
      putchar('\n');
    }
  }
  return 0;
}
