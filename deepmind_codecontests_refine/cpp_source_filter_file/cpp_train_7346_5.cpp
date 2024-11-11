#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  int i, sum = 0;
  for (i = 1; i <= x; i++) {
    sum += i;
  }
  return sum;
}
int main() {
  int n, n1, i, b[70];
  scanf("%d", &n);
  for (i = 1; i <= 70; i++) {
    if (n >= f(i) && n <= f(i + 1)) {
      n1 = i;
      i = 71;
    }
  }
  for (i = 1; i <= n1; i++) {
    b[i] = i;
  }
  b[n1] += n - f(i - 1);
  printf("%d\n%d", n1, b[1]);
  for (i = 2; i <= n1; i++) {
    printf(" %d", b[i]);
  }
  return 0;
}
