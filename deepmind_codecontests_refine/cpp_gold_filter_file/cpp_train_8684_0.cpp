#include <bits/stdc++.h>
long long mdc(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return mdc(b, a % b);
}
bool prime(long long a) {
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) return 0;
  }
  return 1;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    long long N;
    scanf("%I64d", &N);
    long long aux1 = N;
    long long aux2 = N + 1;
    while (!prime(aux1)) {
      aux1--;
    }
    while (!prime(aux2)) {
      aux2++;
    }
    long long num, den;
    if (N == 2) {
      num = aux2 - 2;
      den = 2 * aux2;
    } else {
      num = aux2 * (aux1 - 2) + 2 * (N - aux1 + 1);
      den = 2 * aux1 * aux2;
    }
    int m = mdc(num, den);
    num /= m;
    den /= m;
    printf("%I64d/%I64d\n", num, den);
  }
  scanf("%.d");
}
