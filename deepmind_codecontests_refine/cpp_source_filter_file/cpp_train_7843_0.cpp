#include <bits/stdc++.h>
using namespace std;
int divs[1000000], c = 0;
void show(int *a, int *b) {
  for (int i = 1; i <= a[0]; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  for (int i = 1; i <= b[0]; ++i) {
    printf("%d ", b[i]);
  }
  printf("\n");
}
void compare(int *a, int *b) {
  for (int i = 1; i <= a[0]; ++i) {
    for (int j = 1; j <= b[0]; ++j) {
      if (a[i] == b[j]) {
        ++c;
        return;
      }
    }
  }
}
int main() {
  int x;
  scanf("%d", &x);
  int n[10], m[10];
  n[0] = 0;
  divs[0] = 0;
  for (int tmp = x; tmp > 0; tmp /= 10) n[++n[0]] = tmp % 10;
  for (int i = 1; i <= sqrt(x); ++i) {
    m[0] = 0;
    if (x % i == 0) {
      if (i * i != x) divs[++divs[0]] = x / i;
      for (int tmp = i; tmp > 0; tmp /= 10) m[++m[0]] = tmp % 10;
      compare(n, m);
    }
  }
  for (int i = 0; i <= divs[0]; ++i) {
    m[0] = 0;
    for (int tmp = divs[i]; tmp > 0; tmp /= 10) m[++m[0]] = tmp % 10;
    compare(n, m);
  }
  printf("%d\n", c);
  return 0;
}
