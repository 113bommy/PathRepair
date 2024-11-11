#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x, k, s = 0;
  scanf("%d%d%d", &n, &k, &i);
  if (n > k) {
    for (; n - k; n--) {
      scanf("%d", &x);
      s += x;
    }
    printf("%d", s + k * i);
  } else {
    printf("%d", n * x);
  }
  return 0;
}
