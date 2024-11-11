#include <bits/stdc++.h>
using namespace std;
int main() {
  long long K;
  cin >> K;
  int n = 0;
  long long k = K;
  while (k != 0) {
    k /= 2;
    n += 1;
  }
  if (n == 0) n += 1;
  long long a = 0;
  long long b = (1 << n);
  for (int i = 0; i <= n; i++) {
    a += (1 << i);
  }
  printf("2 3\n");
  printf("%lld %lld %lld\n", a, b, a);
  printf("%lld %lld %lld\n", K, a, K);
  return 0;
}
