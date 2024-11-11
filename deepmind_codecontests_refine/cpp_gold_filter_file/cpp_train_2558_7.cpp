#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 4;
int main() {
  int n;
  scanf("%d", &n);
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y2);
    x1 = abs(x1);
    y1 = abs(y1);
    x1 %= 2;
    y1 %= 2;
    printf("%d\n", (2 * x1 + y1) + 1);
  }
  return 0;
}
