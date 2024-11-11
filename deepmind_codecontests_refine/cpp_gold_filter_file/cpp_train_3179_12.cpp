#include <bits/stdc++.h>
using namespace std;
int a[1001];
int b[1001];
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int j = 0;
  for (i = 0; i < n; i += 2) {
    b[i] = a[j];
    j++;
  }
  for (i = 1; i < n; i += 2) {
    b[i] = a[j];
    j++;
  }
  int flag = 0;
  for (i = 0; i < n; i++) {
    if (i % 2 == 1) {
      if (b[i] < b[i - 1]) {
        flag = 1;
        break;
      }
    }
    if (i % 2 == 0) {
      if (b[i] > b[i - 1] && i >= 2) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1)
    printf("Impossible\n");
  else {
    for (i = 0; i < n; i++) printf("%d ", b[i]);
    printf("\n");
  }
}
