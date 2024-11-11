#include <bits/stdc++.h>
using namespace std;
long long Hash(char* str) {
  int p = 31;
  long long P = 1;
  long long res = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    res += P * (str[i] - 'a');
    P *= p;
  }
  return res;
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  long long n;
  scanf("%I64d", &n);
  int fm = 0;
  long long tmp = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      fm++;
      if (fm <= 2) tmp *= i;
      if (fm == 3) break;
      if ((n / i) % i == 0) {
        fm++;
        if (fm <= 2) tmp *= i;
        if (fm == 3) break;
        if (((n / i) / i) % i == 0) {
          fm++;
          if (fm == 3) break;
        }
      }
    }
    if (fm == 3) break;
  }
  if (fm == 3)
    printf("1\n%I64d", tmp);
  else {
    if (fm == 0)
      printf("1\n0");
    else
      printf("2");
  }
  return 0;
}
