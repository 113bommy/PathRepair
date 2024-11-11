#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    printf("3");
    return 0;
  }
  if (n == 3) {
    printf("5");
    return 0;
  }
  int res = 0;
  for (int i = 2; i <= 20; i++) {
    int i2 = i * i;
    i2 = (i2 + 1) / 2;
    if (i2 >= n) {
      res = i;
      break;
    }
  }
  printf("%d", res);
  return 0;
}
