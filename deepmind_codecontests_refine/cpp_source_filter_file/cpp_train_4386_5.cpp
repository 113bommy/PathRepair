#include <bits/stdc++.h>
using namespace std;
char x[1000000];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", x);
  for (int i = 0; i < n - 1; i++) {
    if (x[i] >= x[i + 1]) {
      x[i] = 0;
      printf("%s%s\n", x, x + i + 1);
      return 0;
    }
  }
  x[n - 1] = 0;
  printf("%s\n", x);
  return 0;
}
