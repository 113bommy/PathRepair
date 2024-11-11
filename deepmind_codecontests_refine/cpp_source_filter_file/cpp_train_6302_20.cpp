#include <bits/stdc++.h>
using namespace std;
int f(int a) {
  int rv = 0;
  while (a) {
    a /= 10;
    rv++;
  }
  return rv;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1;; ++i) {
    int cnt = f(i);
    if (cnt <= n) {
      cnt = n - cnt;
      while (cnt--) {
        i /= 10;
      }
      printf("%d\n", i % 10);
      return 0;
    }
    n -= cnt;
  }
}
