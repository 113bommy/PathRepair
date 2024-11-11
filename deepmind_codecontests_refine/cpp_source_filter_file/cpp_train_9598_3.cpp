#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  while (scanf("%d%d%d", &n, &a, &b) != EOF) {
    if (a <= n - b) {
      printf("%d\n", n - a);
    } else {
      printf("%d\n", n - b);
    }
  }
  return 0;
}
