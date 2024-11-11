#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  if (n <= 2) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int N;
  if (scanf("%d", &N) == EOF) {
    return 0;
  }
  if (isprime(N)) {
    printf("1\n%d\n", N);
  } else {
    bool primes[2000];
    fill(primes, primes + 5000, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i < 2000; i++) {
      if (primes[i]) {
        for (int j = i + i; j < 2000; j += i) {
          primes[j] = false;
        }
      }
    }
    primes[2] = false;
    int cando[4000];
    fill(cando, cando + 4000, -1);
    for (int i = 0; i < 2000; i++) {
      for (int j = 0; j <= i; j++) {
        if (primes[i] && primes[j] && cando[i + j] == -1) {
          cando[i + j] = i;
        }
      }
    }
    for (int i = 0; i < 4000; i++) {
      if (cando[i] >= 0 && isprime(N - i)) {
        printf("3\n%d %d %d\n", N - i, cando[i], i - cando[i]);
        break;
      }
    }
  }
  return 0;
}
