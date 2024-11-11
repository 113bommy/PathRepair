#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c[100010];
  scanf("%d", &n);
  int x = 0;
  for (int a = 1; a <= n; a++) {
    scanf("%d", &c[a]);
    x += (c[a]);
  }
  x = abs(x);
  if (x % n != 0)
    printf("%d\n", (n - 1));
  else if (x % n == 0)
    printf("%d\n", n);
  return 0;
}
