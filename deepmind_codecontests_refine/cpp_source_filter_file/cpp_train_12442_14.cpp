#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, p;
  scanf("%d %d", &n, &m);
  int price = 0;
  for (int i = 0; i < n; ++i) {
    int m = 1000000000;
    for (int j = 0; j < n; ++j) {
      scanf("%d", &p);
      m = min(m, p);
    }
    price = max(price, m);
  }
  printf("%d\n", price);
  return 0;
}
