#include <bits/stdc++.h>
using namespace std;
int n, h[100008], mayor, resp[100008], mayores[100008];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
  mayor = -1;
  for (int j = n - 1; j >= 0; j--) {
    mayores[j] = mayor;
    if (h[j] > mayor) {
      mayor = h[j];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (mayores[i] > h[i]) {
      resp[i] = mayores[i] - h[i] + 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      printf("%d", resp[i]);
    } else {
      printf(" %d", resp[i]);
    }
  }
  return 0;
}
