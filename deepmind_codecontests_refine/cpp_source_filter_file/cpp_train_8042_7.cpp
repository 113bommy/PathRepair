#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, yui;
  scanf("%d\n", &t);
  for (yui = 0; yui < t; yui++) {
    int i, j, k, n;
    scanf("%d\n", &n);
    int a[n];
    for (i = 0; i < n; i++) {
      a[i] = 9;
    }
    for (i = 0; i < n / 4; i++) {
      a[n - i - 1] = 0;
    }
    if (n % 4 != 0) {
      a[n - i - 1] = 8;
    }
    int ans = 0;
    for (i = 0; i < n; i++) {
      printf("%d", a[i]);
    }
    printf("\n");
  }
  return 0;
}
