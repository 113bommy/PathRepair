#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a == 0) {
    printf("0\n");
    return 0;
  }
  if (b >= a) {
    printf("infinity\n");
    return 0;
  }
  a -= b;
  int ans = 0;
  for (int i = 1; i <= sqrt(a); i++) {
    if (a % i == 0) {
      if (i > b) ans++;
      int j = a / i;
      if (j != i && j > b) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
