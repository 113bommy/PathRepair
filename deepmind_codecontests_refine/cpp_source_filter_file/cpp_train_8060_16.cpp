#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int a[150];
  while (~scanf("%d %d", &n, &k)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    printf("%d\n", a[(n - 1) / 2]);
  }
  return 0;
}
