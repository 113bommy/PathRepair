#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  bool a[200];
  memset(a, false, sizeof(a));
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    a[c] = true;
  }
  for (int j = k / 2; j >= 1; j--) {
    if (a[j] && !(k % j)) {
      printf("%d", k / j);
      break;
    }
  }
  return 0;
}
