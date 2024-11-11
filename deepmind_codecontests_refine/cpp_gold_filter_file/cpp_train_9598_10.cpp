#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  while (scanf("%d%d%d", &n, &a, &b) != EOF) {
    if (a + 1 < n - b) {
      printf("%d\n", b + 1);
    } else {
      printf("%d\n", n - a);
    }
  }
  return 0;
}
