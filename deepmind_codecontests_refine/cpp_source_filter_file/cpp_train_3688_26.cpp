#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a, b;
  int d[105] = {0};
  int i, j, k, l, m;
  scanf("%d", &n);
  for (i = 0; i < (n - 1); i++) scanf("%d", &d[i]);
  scanf("%d %d", &a, &b);
  int hasil = 0;
  for (i = a + 1, j = 0; i <= b; i++, j++) {
    hasil += d[j];
  }
  printf("%d\n", hasil);
  return 0;
}
