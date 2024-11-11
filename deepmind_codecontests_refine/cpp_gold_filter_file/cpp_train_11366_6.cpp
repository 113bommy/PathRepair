#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n, counting = 0, GCD;
  scanf("%d %d %d", &a, &b, &n);
  while (1) {
    int tempb = n, tempa = a;
    while (tempb) {
      int temp = tempb;
      tempb = tempa % tempb;
      tempa = temp;
    }
    GCD = tempa;
    if (n < GCD) {
      printf("1\n");
      exit(0);
    }
    n = n - GCD;
    tempb = n, tempa = b;
    while (tempb) {
      int temp = tempb;
      tempb = tempa % tempb;
      tempa = temp;
    }
    GCD = tempa;
    if (n < GCD) {
      printf("0\n");
      exit(0);
    }
    n = n - GCD;
  }
}
