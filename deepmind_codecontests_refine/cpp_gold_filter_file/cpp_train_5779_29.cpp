#include <bits/stdc++.h>
using namespace std;
bool not_prime[100010];
int n;
inline void sieve() {
  not_prime[1] = true;
  for (int i = 2; i < 100001; ++i) {
    if (not_prime[i]) continue;
    int x = i + i;
    while (x < 100001) {
      not_prime[x] = true;
      x += i;
    }
  }
}
bool is_prime(int x) {
  if (x == 1) return false;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
int main(void) {
  sieve();
  scanf("%d", &n);
  if (n <= 7) {
    printf("1\n%d\n", n);
    return 0;
  }
  n -= 3;
  int a, b;
  for (int i = 3; i < 100001; ++i) {
    if (!not_prime[i] && is_prime(n - i)) {
      a = i;
      b = n - i;
      break;
    }
  }
  printf("3\n");
  printf("3 %d %d\n", a, b);
  return 0;
}
