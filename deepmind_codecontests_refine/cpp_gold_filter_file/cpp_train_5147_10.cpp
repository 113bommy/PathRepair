#include <bits/stdc++.h>
using namespace std;
template <typename T>
T mabs(const T &a) {
  return a < 0 ? -a : a;
}
void run() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (n * k > n * (n - 1) / 2) {
    printf("-1\n");
    return;
  }
  printf("%d\n", n * k);
  for (int i = (0), ei = (n); i < ei; i++) {
    for (int j = 1; j <= k; j++) {
      int tb = (i + j) % n;
      printf("%d %d\n", i + 1, tb + 1);
    }
  }
}
int main() {
  run();
  return 0;
}
