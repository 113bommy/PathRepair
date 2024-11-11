#include <bits/stdc++.h>
const long long N = 1e5 + 7;
const long double T = 1e18;
long long a[N], b[N];
long double intake[N];
int n;
long long P;
bool f(long double g) {
  long double needed = 0;
  for (int i = 0; i < n; i++) {
    long double need = (g - intake[i]) * a[i];
    if (need >= 0) needed += need;
  }
  long double income = g * P;
  return income >= needed;
}
int main() {
  scanf("%d%lld", &n, &P);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &a[i], &b[i]);
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  if (P >= sum) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    intake[i] = ((long double)b[i]) / ((long double)a[i]);
  }
  long double mi = 0, ma = T;
  for (long long i = 0; i < 200; i++) {
    long double mid = (mi + ma) / 2;
    if (f(mid))
      mi = mid;
    else
      ma = mid;
  }
  if (ma >= (T - 1000))
    printf("-1\n");
  else
    printf("%.9f\n", (double)mi);
  return 0;
}
