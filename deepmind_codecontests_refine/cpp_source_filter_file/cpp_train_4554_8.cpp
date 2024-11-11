#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
const int Inf = 1 << 30;
double a[105];
int main() {
  int n, cnt;
  double pos, pp, ans, sum;
  while (~scanf("%d", &n)) {
    sum = 0;
    pos = 4.444444445;
    pos *= n;
    for (int i = 1; i <= n; i++) {
      scanf("%lf", &a[i]);
      sum += a[i];
    }
    cnt = 0;
    sort(a + 1, a + 1 + n);
    while (sum < pos) {
      cnt++;
      sum += 5 - a[cnt];
    }
    printf("%d\n", cnt);
  }
  return 0;
}
