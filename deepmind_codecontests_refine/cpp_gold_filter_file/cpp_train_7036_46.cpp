#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
int X[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int mx = 0;
    memset(X, 0, sizeof(X));
    for (int i = 0; i < 250; i++) {
      int x;
      scanf("%d", &x);
      mx = max(mx, x);
      if (x < N) X[x]++;
    }
    if (mx > 2000) {
      printf("poisson\n");
      return 0;
    }
    int d = mx;
    for (int i = 0; i < mx; i++) {
      int cnt = 0;
      for (int j = i; j < mx; j++) {
        cnt += X[j];
        if (cnt >= 125) {
          d = min(d, j - i + 1);
          break;
        }
      }
    }
    if (100 * d < 33 * mx) {
      printf("poisson\n");
    } else {
      printf("uniform\n");
    }
  }
  return 0;
}
