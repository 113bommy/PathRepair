#include <bits/stdc++.h>
const long long sg[31] = {0, 1, 2, 1, 4, 3, 2, 1, 5,  6, 2, 1, 8,  7,  5, 9,
                          8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};
const int maxn = 1e5 + 7;
using namespace std;
long long n;
long long ans, v[maxn], t;
int main() {
  scanf("%lld", &n);
  long long p = trunc(sqrt(n));
  ans = sg[1];
  for (long long i = 2; i <= p; i++) {
    if (v[i]) continue;
    long long c = i, k = 1;
    while (c * i <= n) {
      c *= i;
      if (c <= p)
        v[c] = 1;
      else
        t++;
      k++;
    }
    ans ^= sg[k];
  }
  if ((n - p - t) % 2 == 1) ans ^= sg[1];
  if (ans == 0)
    printf("Petya");
  else
    printf("Vasya");
}
