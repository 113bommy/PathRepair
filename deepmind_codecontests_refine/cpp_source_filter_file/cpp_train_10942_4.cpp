#include <bits/stdc++.h>
using namespace std;
long long int n, s, a, b, c, tut, tut1;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld %lld %lld", &s, &a, &b, &c);
    tut = s / c;
    tut1 = (tut / a) * b;
    printf("%lld", tut + tut1);
  }
}
