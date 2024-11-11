#include <bits/stdc++.h>
using namespace std;
int main() {
  int ncase;
  for (scanf("%d", &ncase); ncase--;) {
    int n;
    scanf("%d", &n);
    if (n % 4 == 0) {
      printf("%d\n", n / 4);
      continue;
    }
    if (n % 4 == 2) {
      printf("%d\n", n == 2 ? -1 : n / 4);
      continue;
    }
    if (n % 4 == 1) {
      printf("%d\n", n <= 5 ? -1 : n / 4 - 1);
      continue;
    }
    if (n % 4 == 3) {
      printf("%d\n", n <= 11 ? -1 : n / 4 - 1);
      continue;
    }
  }
  return 0;
}
