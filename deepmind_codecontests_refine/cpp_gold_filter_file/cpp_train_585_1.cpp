#include <bits/stdc++.h>
using namespace std;
long long K, D, T;
int main() {
  while (scanf("%I64d%I64d%I64d", &K, &D, &T) == 3) {
    K <<= 1, D <<= 1, T <<= 1;
    long long a = (K + D - 1) / D * D;
    long long b = K + (a - K) / 2;
    long long res = T / b * a / 2;
    T %= b;
    if (T > K) {
      res += K / 2 + (T - K);
      printf("%.2lf\n", res * 1.0);
    } else {
      res += T / 2;
      printf("%.2lf\n", res + (T % 2 == 0 ? 0 : 0.5));
    }
  }
  return 0;
}
