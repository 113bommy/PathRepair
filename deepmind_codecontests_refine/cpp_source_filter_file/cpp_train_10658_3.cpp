#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, N;
  double x, j, t = 0, mx;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%lf", &x);
    j += x;
    mx = max(mx, j / i);
  }
  printf("%lf\n", mx);
  return 0;
}
