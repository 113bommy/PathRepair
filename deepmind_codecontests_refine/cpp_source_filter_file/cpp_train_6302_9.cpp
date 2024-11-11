#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
  int n;
  scanf("%d", &n);
  int j = 1, x, y;
  for (int i = 1; i <= 360; i++) {
    if (i < 10) {
      a[j] = i;
      j++;
    } else if (i <= 99) {
      a[j] = i / 10;
      a[j + 1] = i % 10;
      j += 2;
    } else if (i >= 100 && i <= 999) {
      a[j + 2] = i % 10;
      x = i / 10;
      a[j + 1] = x % 10;
      x /= 10;
      a[j] = x;
      j += 3;
    }
  }
  printf("%d\n", a[n]);
}
