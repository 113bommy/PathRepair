#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if (a < b) {
    printf("0");
    return 0;
  }
  if (a == b) {
    printf("infinity");
    return 0;
  }
  a -= b;
  int c = sqrt(a);
  int ans = 0;
  for (int i = 1; i <= c; i++) {
    if (a % i == 0) {
      if (i > b) ans++;
      if (a / i > b && a / i != c) ans++;
    }
  }
  printf("%d", ans);
  return 0;
}
