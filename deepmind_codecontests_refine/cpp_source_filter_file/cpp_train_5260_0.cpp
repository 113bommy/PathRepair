#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  char a[n + 1];
  scanf(" %s", a);
  if (k > n * 25) {
    printf("-1\n");
    return 0;
  }
  char x;
  for (int i = 0; a[i] != '\0' && k; i++) {
    if (a[i] < 'm') {
      x = 'z' - a[i];
      if (k >= x) {
        k -= x;
        a[i] = 'z';
      } else {
        a[i] = a[i] + k;
        k = 0;
      }
    } else {
      x = a[i] - 'a';
      if (k >= x) {
        k -= x;
        a[i] = 'a';
      } else {
        a[i] = a[i] + k;
        k = 0;
      }
    }
  }
  if (k) {
    printf("-1\n");
    return 0;
  }
  printf("%s\n", a);
}
