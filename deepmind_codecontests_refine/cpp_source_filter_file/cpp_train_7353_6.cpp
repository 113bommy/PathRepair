#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001] = {0};
int main() {
  int i, j, k, l = 2, m = -1, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &k);
    b[k]++;
    if (m < k)
      ;
    { m = k; }
  }
  for (i = m; i >= 0; i--) {
    if (b[i] % 2 == 1) {
      l = 1;
      break;
    }
  }
  if (l == 1) {
    printf("Conan\n");
  } else {
    printf("Agasa\n");
  }
  return 0;
}
