#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, k;
int main() {
  scanf("%d", &n);
  if (n <= 2) {
    printf("%d\n", -1);
  } else {
    printf("%d\n", 35);
    printf("%d\n", 77);
    for (i = 1; i <= n - 2; i++) printf("%d\n", i * 55);
  }
  return 0;
}
