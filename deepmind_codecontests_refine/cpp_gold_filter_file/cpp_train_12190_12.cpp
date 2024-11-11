#include <bits/stdc++.h>
using namespace std;
long long n, m;
int x, d;
int main() {
  while (cin >> n >> m) {
    long long sum = 0, ans = 0;
    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &x, &d);
      if (n & 1) {
        if (d < 0) {
          long long t = n >> 1;
          t = t * (t + 1);
          sum += t * d;
        } else {
          long long t = n * (n - 1) / 2;
          sum += t * d;
        }
      } else {
        if (d < 0) {
          long long t = n >> 1;
          t = t * (t + 1);
          sum += (t - n / 2) * d;
        } else {
          long long t = n * (n - 1) / 2;
          sum += t * d;
        }
      }
      sum += x * n;
    }
    printf("%.7f\n", (double)sum / n);
  }
  return 0;
}
