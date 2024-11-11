#include <bits/stdc++.h>
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  double n, N;
  scanf("%lf", &n);
  N = n * n;
  long long kq = 1;
  double u, v;
  kq += 2 * (long long)((sqrt(N - 0.25) - sqrt(3) / 2) / sqrt(3));
  kq += 2 * (long long)((n - 1) / 3);
  for (int i = 1;; i++) {
    u = i;
    if ((3 * u + 1) * (3 * u + 1) > N) break;
    kq += 4 * min((long long)(sqrt((N - (3 * u + 1) * (3 * u + 1)) / 3)),
                  (long long)((sqrt((N - (3 * u + 0.5) * (3 * u + 0.5))) -
                               sqrt(3) / 2) /
                              sqrt(3)));
  }
  for (int i = 0;; i++) {
    u = i;
    if ((3 * u + 2.5) * (3 * u + 2.5) > N) break;
    kq += 4 * (min((long long)((sqrt(N - (3 * u + 2.5) * (3 * u + 2.5)) -
                                sqrt(3) / 2) /
                               sqrt(3)),
                   (long long)((sqrt(N - (3 * u + 2) * (3 * u + 2)) - sqrt(3)) /
                               sqrt(3))) +
               1);
  }
  printf("%I64d\n", kq);
}
