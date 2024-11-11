#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d\n", &n);
    for (int a = 0; a < n; a++) {
      printf("%d ", 3 + a * 6);
    }
    printf("\n");
  }
  return 0;
}
