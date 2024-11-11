#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, p;
  scanf("%d %d", &n, &m);
  int price = 0;
  for (int i = 0; i < n; ++i) {
    int tmp = 1000000000;
    for (int j = 0; j < m; ++j) {
      scanf("%d", &p);
      tmp = min(tmp, p);
    }
    price = max(price, tmp);
  }
  printf("%d\n", price);
  return 0;
}
