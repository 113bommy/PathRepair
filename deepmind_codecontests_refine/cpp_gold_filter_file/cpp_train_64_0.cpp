#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  scanf("%d", &k);
  int maxn = 0;
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    if (x >= 500001) {
      maxn = max(maxn, 1000000 - x);
    }
    if (x <= 500000) {
      maxn = max(maxn, x - 1);
    }
  }
  printf("%d\n", maxn);
}
