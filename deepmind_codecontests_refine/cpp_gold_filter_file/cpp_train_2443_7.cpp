#include <bits/stdc++.h>
using namespace std;
long long int prime[100010];
long long int n;
struct lala {
  long long int d, x, y;
  lala() {}
  lala(long long int _d, long long int _x, long long int _y) {
    d = _d;
    x = _x;
    y = _y;
  }
};
void sieve_with_bit_masking() {
  long long int i, j, k, l;
  prime[1] = 1;
  prime[2] = 0;
  for (i = 2; i <= sqrt(100010); i++) {
    for (j = i * i; j <= 100010; j += i) {
      prime[j] = 1;
    }
  }
}
void input() { scanf("%lld", &n); }
lala extended_euclid(long long int a, long long int b) {
  if (b == 0) {
    return lala(a, 1, 0);
  } else {
    lala temp = extended_euclid(b, a % b);
    lala temp1 = lala(temp.d, temp.y, temp.x - ((a / b) * temp.y));
    return temp1;
  }
}
void solve() {
  long long int i, j;
  if (n == 1) {
    printf("YES\n");
    printf("%lld", 1LL);
    puts("");
    return;
  }
  if (n == 4) {
    printf("YES\n");
    printf("%lld", 1LL);
    puts("");
    printf("%lld", 3LL);
    puts("");
    printf("%lld", 2LL);
    puts("");
    printf("%lld", 4LL);
    puts("");
    return;
  }
  if (prime[n] == 1) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (i = 1; i <= n - 1; i++) {
    if (i == 1) {
      printf("%lld", 1LL);
    } else {
      lala temp = extended_euclid(i - 1, n);
      printf("%lld", (temp.x + 1 + n) % n);
    }
    puts("");
  }
  printf("%lld", n);
  puts("");
}
int main() {
  long long int i, j;
  sieve_with_bit_masking();
  input();
  solve();
  return 0;
}
