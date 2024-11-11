#include <bits/stdc++.h>
using namespace std;
long long f[1000001], If[1000001], cor[1000001], T[1000001], part[1000001];
long long modu = 1000000007;
long long inv(long long x) {
  long long t, p;
  for (t = modu - 2, p = 1; t; t /= 2) {
    if (t % 2) p = p * x % modu;
    x = x * x % modu;
  }
  return p;
}
int main() {
  long long n, k, tmp, sum;
  scanf("%lld%lld", &n, &k);
  int i;
  f[0] = If[0] = 1;
  for (i = 1; i <= n; i++) {
    f[i] = f[i - 1] * i % modu;
    If[i] = If[i - 1] * inv(i) % modu;
  }
  part[0] = 0;
  for (i = 1; i <= n; i++) {
    if (i == 1) {
      T[1] = 1, part[1] = 1, cor[1] = 1;
    } else if (i < k) {
      T[i] = f[i], part[i] = (part[i - 1] + T[i] * If[i] % modu) % modu;
      cor[i] = (T[i - 1] + (i - 1) * cor[i - 1] % modu) % modu;
    } else {
      tmp = part[i - 1] - part[i - k - 1];
      tmp = (tmp + modu) % modu;
      T[i] = f[i - 1] * tmp % modu;
      part[i] = (part[i - 1] + T[i] * If[i] % modu) % modu;
      cor[i] = (T[i - 1] + (i - 1) * cor[i - 1] % modu) % modu;
    }
  }
  sum = (f[n] - cor[n] + modu) % modu;
  printf("%lld\n", sum);
  return 0;
}
