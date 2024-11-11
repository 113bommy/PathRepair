#include <bits/stdc++.h>
using namespace std;
int a, x, y, z;
int b[2000009][2];
int main() {
  scanf("%d", &a);
  for (int i = 0; i < a * 2; i++) scanf("%1d", &b[i][0]);
  for (int j = 0; j < a * 2; j++) scanf("%1d", &b[j][1]);
  for (int i = 0; i < a * 2; i++) {
    if (b[i][1] == 1 && b[i][0] == 1) z++;
    if (b[i][0] == 1 && b[i][1] == 0) x++;
    if (b[i][0] == 0 && b[i][1] == 1) y++;
  }
  if (z % 2 == 1) {
    x++;
    if (x + 1 < y)
      printf("Second");
    else if (x > y)
      printf("First");
    else
      printf("Draw");
  } else {
    if (y < x)
      printf("First");
    else if (y > x + 1)
      printf("Second");
    else
      printf("Draw");
  }
  getchar();
  getchar();
}
