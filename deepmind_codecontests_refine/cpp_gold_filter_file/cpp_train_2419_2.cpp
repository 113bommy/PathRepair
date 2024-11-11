#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, m, a;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &a, &m);
    if (a % m == 0)
      printf("%lld \n", a % m);
    else
      printf("%lld \n", (1 + (long long)a / m) * m - a);
  }
}
