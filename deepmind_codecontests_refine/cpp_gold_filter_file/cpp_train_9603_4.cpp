#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a, b, c, d, dif = 0;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (b >= a)
      printf("%d \n", b);
    else if (a > b && c <= d)
      printf("%d \n", -1);
    else {
      a -= b;
      dif = c - d;
      printf("%lld\n", (long long)(b + c * ceil(a / (double)dif)));
    }
  }
}
