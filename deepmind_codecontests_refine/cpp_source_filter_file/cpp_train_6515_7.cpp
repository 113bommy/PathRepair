#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, ma;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    ma = max(ma, x);
  }
  printf("%d\n", ma ^ x);
  return 0;
}
