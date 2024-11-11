#include <bits/stdc++.h>
using namespace std;
int prime[100005];
int modpow(int a, int b, int mod) {
  if (b == 0) return 1;
  int x = modpow(a, b / 2, mod);
  if (b % 2) return (1ll * ((1ll * x * x) % mod) * a) % mod;
  return (1ll * x * x) % mod;
}
int main() {
  int i, j, k, n;
  for (i = 2; i <= 100000; i++) {
    if (prime[i] == 0) {
      for (j = 2 * i; j <= 100000; j += i) prime[j] = 1;
    }
  }
  scanf("%d", &n);
  if (n == 1) {
    printf("YES\n1\n");
  } else if (n == 4) {
    printf("YES\n1\n3\n2\n0\n");
  } else if (prime[n] == 1)
    printf("NO\n");
  else {
    printf("YES\n");
    printf("1\n");
    for (i = 2; i < n; i++) {
      printf("%d\n", (1ll * i * modpow(i - 1, n - 2, n)) % n);
    }
    printf("%d\n", n);
  }
  return 0;
}
