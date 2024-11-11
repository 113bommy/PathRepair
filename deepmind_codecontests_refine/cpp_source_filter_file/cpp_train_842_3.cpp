#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (2 * n / 3); i++) {
    printf("0 %d\n", i);
  }
  for (int i = 1; i <= (n - (2 * n / 3)); i++) {
    printf("3 %d\n", i);
  }
  return 0;
}
