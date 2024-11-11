#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  int a[105];
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = n; i >= 1; i--) {
    if (k % a[i] == 0) {
      printf("%d\n", a[i]);
      break;
    }
  }
  return 0;
}
