#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, n, odd = 0, even = 0;
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] % 2) {
        ++odd;
      } else {
        ++even;
      }
    }
    if (odd == 0 || (odd % 2 == 0 && even == 0)) {
      printf("No\n");
    } else if (odd % 2) {
      printf("Yes\n");
    } else {
      if (x < n) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
  }
  return 0;
}
