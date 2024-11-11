#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  if (k > (n >> 1)) {
    k = n - k;
  }
  long long pt = 1LL;
  long long ct = 1LL;
  int cur = 1;
  for (int i = 0; i < n; i++) {
    pt += ct;
    cur += k;
    if (cur > n) {
      cur -= n;
      if (cur != 1) {
        ct++;
      }
    }
    if (cur + k > n + 1) {
      ct++;
    }
    printf("%d ", pt);
  }
  printf("\n");
  return 0;
}
