#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, a, b;
int main() {
  scanf("%d %d %d", &n, &a, &b);
  int e = n / 2, o = n - e;
  int f = a * b / 2, g = a * b - f;
  if (g < o || f < e)
    printf("-1\n");
  else {
    for (int i = 1; i <= a; puts(""), i++)
      for (int j = 1; j <= b; j++)
        if ((i + j) & 1) {
          if (!o)
            printf("0 ");
          else
            printf("%d ", 2 * o - 1), --o;
        } else {
          if (!e)
            printf("0 ");
          else
            printf("%d ", 2 * e), --e;
        }
  }
  return 0;
}
