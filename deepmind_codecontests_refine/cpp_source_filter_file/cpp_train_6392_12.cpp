#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long double r;
  cin >> n >> r;
  long double now = 0.0, sum = 0.0, p = 2.0 * r + sqrt(2.0) * 2.0 * r;
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      now += 2.0 * r;
    else if (i == 2)
      now += 2.0 * r + sqrt(2.0) * r;
    else
      now += p + (long double)(i - 3) * 2.0 * r;
  }
  sum += now;
  int last = n;
  for (int i = 2; i <= n; i++) {
    if (last == 2) {
      now -= 2.0 * r + sqrt(2.0) * r;
    } else {
      now -= p + (long double)(i - 3) * 2.0 * r;
    }
    if (i == 1)
      now += 2.0 * r;
    else if (i == 2)
      now += 2.0 * r + sqrt(2.0) * r;
    else
      now += p + (long double)(i - 3) * 2.0 * r;
    sum += now;
    last--;
  }
  printf("%.15Lf\n", sum / (long double)n / (long double)n);
}
