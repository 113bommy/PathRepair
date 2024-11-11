#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    n--;
    n = n / 2;
    int sum = 1;
    int i;
    for (i = 1; i <= n; i++) {
      sum += 1;
    }
    printf("%d\n", sum);
  }
  return 0;
}
