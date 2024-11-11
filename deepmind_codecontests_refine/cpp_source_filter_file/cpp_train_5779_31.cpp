#include <bits/stdc++.h>
using namespace std;
const long long infi = 1000000000000000009;
long long primes[109];
long long ar[1009][2];
long long co = 0;
bool check(long long num) {
  long long c = 0, j;
  for (j = 2; j * j <= num; j++) {
    if (num % j == 0) {
      c++;
      break;
    }
  }
  return c;
}
int main() {
  long long i, j, k;
  long long n;
  scanf("%lld", &n);
  for (i = 2; i <= 100; i++) {
    if (check(i) == 0) primes[co++] = i;
  }
  for (i = 0; i < co; i++) {
    for (j = 0; j < co; j++) {
      if (ar[primes[i] + primes[j]][0] == 0) {
        ar[primes[i] + primes[j]][0] = primes[i];
        ar[primes[i] + primes[j]][1] = primes[j];
      }
      if (ar[primes[i]][0] == 0) {
        ar[primes[i]][0] = primes[i];
      }
      if (ar[primes[j]][0] == 0) {
        ar[primes[j]][0] = primes[j];
      }
    }
  }
  long long c = 0;
  if (check(n) == 0) {
    printf("1\n%lld\n", n);
    exit(0);
  }
  if (check(n - 2) == 0) {
    printf("2\n2 %lld\n", n - 2);
    exit(0);
  }
  for (i = 4; i <= 98; i += 2) {
    if (check(n - i) == 0) {
      printf("3\n%lld %lld %lld\n", ar[i][0], ar[i][1], n - i);
      exit(0);
    }
  }
  return 0;
}
