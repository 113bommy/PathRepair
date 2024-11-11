#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    if (n == 2) {
      printf("1\n0\n");
      continue;
    } else if (n == 3) {
      printf("1\n1\n");
      continue;
    } else if (n == 4) {
      printf("2\n0 1\n");
      continue;
    } else if (n == 5) {
      printf("2\n1 0\n");
      continue;
    } else if (n == 6) {
      printf("2\n1 1\n");
      continue;
    } else if (n == 7) {
      printf("2\n1 2\n");
      continue;
    }
    int days;
    for (int i = 3; i <= 30; i++) {
      if (n <= (2 << i) - 1) {
        days = i;
        break;
      }
    }
    printf("%d\n", days);
    for (int i = 1; i <= days - 2; i++) {
      printf("%d ", 1 << (i - 1));
    }
    int predicted = (1 << days) - 1;
    int x = 0, y = 0;
    if (predicted + (1 << (days - 1)) <= n) {
      x = (1 << days - 2);
      y = n - (predicted + (1 << (days - 1)));
    } else {
      x = (n - predicted) / 2;
      y = (n - predicted) % 2;
    }
    printf("%d %d\n", x, y);
  }
}
