#include <bits/stdc++.h>
using namespace std;
void divideByZero(const char *error) {
  printf(error);
  fclose(stdout);
  int a = 234;
  a = a / (a - a);
}
long parseLong() {
  long temp;
  scanf("%ld", &temp);
  return temp;
}
long long mod = 1000000007L;
long long pow2(long long n) {
  long long mult = 2, acc = 1;
  while (n > 0) {
    if (n % 2 == 1) acc = (acc * mult) % mod;
    n /= 2;
    mult = (mult * mult) % mod;
  }
  return acc;
}
int main() {
  char buff[200];
  scanf("%s", buff);
  long n = strlen(buff);
  long temp = pow2(0);
  long long acc = 0;
  for (long long pos = 0; pos < n; pos++)
    if (buff[pos] == '1') acc = (acc + pow2(2 * n - 2 - pos)) % mod;
  printf("%I64d", acc);
  return 0;
}
