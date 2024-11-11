#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[] = {1, 2, 3, 5};
  int n, k;
  scanf("%d", &n), scanf("%d", &k);
  int m = k * (5 + (n - 1) * 6);
  printf("%d\n", m);
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (4); ++j) {
      printf("%d ", k * (a[j] + 6 * i));
    }
    printf("\n");
  }
  return 0;
}
