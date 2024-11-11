#include <bits/stdc++.h>
using namespace std;
int INP, AM, REACHEOF;
const int BUFSIZE = (1 << 12) + 17;
char BUF[BUFSIZE + 1], *inp = BUF;
int n, a[4011], b[4011];
int main() {
  while (scanf("%d", &n) == 1) {
    n *= 2;
    int sum = 0;
    for (int i = (1), _b = (n); i <= _b; i++) {
      int x;
      scanf("%d.%d", &x, &a[i]);
      sum += a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = (1), _b = (n); i <= _b; i++)
      if (a[i] == 0)
        b[i] = 0;
      else
        b[i] = 1000;
    sort(b + 1, b + n + 1);
    int res = sum;
    int low = 0, high = 0;
    for (int i = (1), _b = (n / 2); i <= _b; i++)
      low += b[i], high += b[n / 2 + i];
    for (int i = low; i <= high; i += 1000) res = min(res, abs(sum - i));
    printf("%.3lf\n", res / 1000.0);
  }
  return 0;
}
