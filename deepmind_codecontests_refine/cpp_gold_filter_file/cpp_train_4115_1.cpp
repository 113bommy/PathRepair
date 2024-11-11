#include <bits/stdc++.h>
using namespace std;
int a[500500];
int b[500500];
int main() {
  int n;
  scanf("%d", &n);
  int A = 0, B = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      a[1 + A] = a[n - A] = i;
      A++;
    } else {
      b[1 + B] = b[n - 1 - B] = i;
      B++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0)
      printf("%d ", n);
    else
      printf("%d ", a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0)
      printf("%d ", n);
    else
      printf("%d ", b[i]);
  }
  return 0;
}
