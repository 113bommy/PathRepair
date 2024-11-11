#include <bits/stdc++.h>
using namespace std;
bool x[105];
bool y[100];
int main() {
  int n, a, b;
  while (scanf("%d", &n) != EOF) {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &a, &b);
      x[a] = 1;
      y[b] = 1;
    }
    int countx = 0;
    int county = 0;
    for (int i = 0; i < 100; i++) {
      if (x[i] == 1) countx++;
      if (y[i] == 1) county++;
    }
    countx = min(countx, county);
    printf("%d\n", countx);
  }
  return 0;
}
