#include <bits/stdc++.h>
using namespace std;
void print_yes(int a_x, int a_y, int b_x, int b_y) {
  printf("YES\n%d %d\n%d %d\n%d %d\n", a_x, a_y, b_x, b_y, 0, 0);
}
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  for (int i = 1; i < a; i++) {
    for (int j = 1; j < a; j++) {
      if (i * i + j * j == a * a) {
        if ((double)b * i / a == round((double)b * i / a) &&
            (double)b * j / a == round((double)b * j / a) && b * j / a != i) {
          print_yes(i, j, -b * i / a, b * j / a);
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}
