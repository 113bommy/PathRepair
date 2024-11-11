#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K, div, rem, init, i;
  scanf("%d %d", &N, &K);
  if (N <= K)
    printf("%d\n%d", 1, 1);
  else if (N <= 2 * K + 1)
    printf("%d\n%d", 1, K + 1);
  else {
    div = N / (2 * K + 1) + 1;
    rem = N % (2 * K + 1);
    if (rem == 0) {
      init = K + 1;
      printf("%d\n", div - 1);
      for (i = 0; i < div - 1; i++) {
        printf("%d ", init);
        init += (2 * K + 1);
      }
    } else {
      init = (rem < (K + 1) ? rem : (K + 1));
      printf("%d\n", div);
      for (i = 0; i < div; i++) {
        printf("%d ", init);
        init += (2 * K + 1);
      }
    }
  }
}
