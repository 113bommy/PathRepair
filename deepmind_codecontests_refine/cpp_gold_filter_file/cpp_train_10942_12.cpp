#include <bits/stdc++.h>
using namespace std;
long long int s, a, b, c, x, tut, tut1;
int main() {
  scanf("%lld", &x);
  for (int i = 1; i <= x; i++) {
    scanf("%lld %lld %lld %lld", &s, &a, &b, &c);
    tut = s / c;
    tut1 = (tut / a) * b;
    printf("%lld\n", tut + tut1);
  }
}
