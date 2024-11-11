#include <bits/stdc++.h>
using namespace std;
int N, K, R, X;
int main() {
  scanf("%d %d", &N, &K);
  X = K;
  while (true) {
    if (N < X) {
      printf("-1\n");
      return 0;
    }
    if (N < 2 * X) {
      printf("%d\n", X);
      return 0;
    }
    X += K;
  }
  return 0;
}
