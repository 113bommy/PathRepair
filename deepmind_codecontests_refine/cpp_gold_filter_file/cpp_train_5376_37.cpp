#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d", &n);
  scanf("%d", &m);
  k = 1;
  for (int i = 1; i <= n; i++) {
    k = k * 2;
    if (k > m) {
      printf("%d", m);
      return 0;
    }
  }
  printf("%d", m % k);
}
