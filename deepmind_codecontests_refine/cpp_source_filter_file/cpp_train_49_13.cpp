#include <bits/stdc++.h>
using namespace std;
int x[500005], y[500005], z[500005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", x + i, y + i, z + i);
  }
  for (int i = 1; i < n; i++) {
    printf("(");
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf("+");
    printf("(");
    printf("%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", x[i] / 2, i - 1,
           i - 1);
    if (i > 1) printf(")");
  }
  printf("\n");
  for (int i = 1; i <= n; i++) {
    printf("(");
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf("+");
    printf("(");
    printf("%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))", y[i] / 2, i - 1,
           i - 1);
    if (i > 1) printf(")");
  }
  printf("\n");
  return 0;
}
