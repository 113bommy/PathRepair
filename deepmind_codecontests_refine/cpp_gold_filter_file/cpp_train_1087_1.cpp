#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
const double eps = 1e-8;
int a[N];
int main() {
  int k;
  scanf("%d", &k);
  int n = 0;
  int z = 0;
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    if (x != 0)
      a[n++] = x;
    else
      z = 1;
  }
  if (n == 0) {
    puts("0");
    return 0;
  }
  if (n == 1) {
    printf("%d\n", a[0] < 0 && z ? 0 : a[0]);
    return 0;
  }
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 0; i < n && a[i] > 0; i++) printf("%d ", a[i]);
  for (int i = n - 1; i - 1 >= 0 && a[i - 1] < 0; i -= 2)
    printf("%d %d ", a[i], a[i - 1]);
  return 0;
}
