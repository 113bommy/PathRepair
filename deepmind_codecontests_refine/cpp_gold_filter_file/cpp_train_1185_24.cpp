#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  long double answer = 0;
  long double misses = 1;
  while (true) {
    long double ll = misses * (long double)a / (long double)b;
    answer = answer + ll;
    if (ll < 1e-12) break;
    misses = misses * (1 - (long double)a / (long double)b) *
             (1 - (long double)c / (long double)d);
  }
  printf("%.12lf\n", (double)answer);
  return 0;
}
