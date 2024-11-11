#include <bits/stdc++.h>
using namespace std;
int n, x, q;
void un() {
  if (x == 1)
    x = 2;
  else
    x = 1;
}
int main() {
  scanf("%d", &n);
  x = 2;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &q);
    if ((q) % 2 == 1) printf("%d\n", x);
    if ((q) % 2 == 0) {
      un();
      printf("%d\n", x);
    }
  }
  return 0;
}
