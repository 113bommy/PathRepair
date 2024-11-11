#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  if (n == 1)
    printf("0");
  else if (c > a && c > b) {
    printf("%d", (n - 1) * min(a, b));
  } else {
    printf("%d", min(a, b) + c * (n - 2));
  }
  return 0;
}
