#include <bits/stdc++.h>
int n, P1, P2, P3, T1, T2, l[200], r[200];
inline int sleep(int T) {
  int sum = 0;
  if (T <= T1) return T * P1;
  T -= T1;
  sum += T1 * P1;
  if (T <= T2 - T1) return sum + T * P2;
  sum += T2 * P2;
  T -= T2;
  return sum + T * P3;
}
int main() {
  scanf("%u%u%u%u%u%u", &n, &P1, &P2, &P3, &T1, &T2);
  for (int i = 0; i < n; ++i) scanf("%u%u", &l[i], &r[i]);
  int total = 0;
  for (int i = 0; i < n; ++i) {
    total += (r[i] - l[i]) * P1;
    if (i > 0) total += sleep(l[i] - r[i - 1]);
  }
  printf("%u\n", total);
  return 0;
}
