#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 100;
int a[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  if (a[0] != a[n - 1]) {
    printf("%d", a[0]);
    for (int i = 0; i < n - 1; i++) printf(" %d", a[i]);
  } else {
    if (a[n - 1] == 1) {
      for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
      printf("2\n");
    } else {
      printf("1");
      for (int i = 0; i < n - 1; i++) printf(" %d", a[i]);
    }
  }
  return 0;
}
