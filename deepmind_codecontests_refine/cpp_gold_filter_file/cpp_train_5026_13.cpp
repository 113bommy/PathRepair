#include <bits/stdc++.h>
using namespace std;
long long T;
long long a, b, c, d;
int main() {
  cin >> T;
  while (T--) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    long long f1 = 0, f2 = 0;
    f1 = (a + b) % 2;
    if (a + d == 0) f2 = 1;
    if (b + c == 0) f2 = 2;
    if (f1 == 1 && f2 != 1)
      printf("Ya ");
    else
      printf("Tidak ");
    if (f1 == 1 && f2 != 2)
      printf("Ya ");
    else
      printf("Tidak ");
    if (f1 == 0 && f2 != 2)
      printf("Ya ");
    else
      printf("Tidak ");
    if (f1 == 0 && f2 != 1)
      printf("Ya ");
    else
      printf("Tidak ");
    printf("\n");
  }
  return 0;
}
