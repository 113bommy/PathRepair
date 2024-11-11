#include <bits/stdc++.h>
using namespace std;
int prime[45000], a, b, k;
bool notprime[45000];
void ciur(int n) {
  int lim;
  lim = sqrt(n);
  prime[0] = 1;
  prime[1] = 2;
  for (int i = 4; i <= lim; i = i + 2) notprime[i] = 1;
  for (int i = 3; i <= lim; i = i + 2) {
    if (!notprime[i]) {
      prime[0]++;
      prime[prime[0]] = i;
      for (int j = i * i; j <= lim; j = j + 2 * i) notprime[j] = 1;
    }
  }
}
int f(int n, int p) {
  int x2, r;
  x2 = n / p;
  r = n / p;
  for (int i = 1; prime[i] < p && prime[i] <= x2 && i <= prime[0]; ++i) {
    r = r - f(x2, prime[i]);
  }
  return r;
}
int main() {
  scanf("%d%d%d", &a, &b, &k);
  ciur(b);
  if (k <= sqrt(b)) {
    if (notprime[k]) {
      printf("0");
      return 0;
    } else {
      printf("%d", f(b, k) - f(a - 1, k));
    }
  } else {
    for (int i = 1; i <= prime[0]; ++i) {
      if (k % prime[i] == 0) {
        printf("0");
        return 0;
      }
    }
    printf("%d", f(b, k) - f(a - 1, k));
  }
  return 0;
}
