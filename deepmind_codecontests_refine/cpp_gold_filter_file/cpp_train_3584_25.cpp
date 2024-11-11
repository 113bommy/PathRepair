#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 5) {
    printf("1 2 3\n");
    printf("1 3 3\n");
    printf("2 4 2\n");
    printf("4 5 1\n");
    printf("3 4\n");
    printf("3 5\n");
  } else {
    int n2 = n / 2;
    for (int i = 1; i <= n2; i++) {
      printf("%d %d 1\n", i, i + (n - n2));
    }
    if (n % 2 == 1) {
      printf("%d %d 1\n", n2, n2 + 1);
    }
    int t = 1;
    for (int i = n2; i > 1; i--) {
      printf("%d %d %d\n", i - 1, i, t);
      t += 2;
    }
    t = n - n2;
    for (int i = n - 1; i > t; i--) {
      printf("%d %d\n", i, i + 1);
    }
    printf("%d %d\n", n - 2, n);
  }
  return 0;
}
