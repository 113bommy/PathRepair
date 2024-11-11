#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, k = 0, k1 = 0, k2 = 0, k3 = 0, l = 0;
  char a[110];
  scanf("%s", &a);
  n = strlen(a);
  for (i = 0; i < n; i++) {
    switch (a[i]) {
      case 'n':
        k++;
        break;
      case 'i':
        k1++;
        break;
      case 'e':
        k2++;
        break;
      case 't':
        k3++;
        break;
    }
    if (k >= 2 && k1 >= 1 && k2 >= 3 && k3 >= 1) {
      l++;
      k = k - 2;
      k1 = k1 - 1;
      k2 = k2 - 3;
      k3 = k3 - 1;
    }
  }
  printf("%d", l);
}
