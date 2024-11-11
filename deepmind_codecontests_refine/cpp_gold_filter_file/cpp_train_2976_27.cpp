#include <bits/stdc++.h>
using namespace std;
int a[100100];
int b[100100];
int n;
int p;
bool check(long double t) {
  long double need = 0.0;
  long double have = (long double)p * t;
  for (int i = 0; i < n; i++) {
    need += (long double)a[i] * t;
    have += min((long double)a[i] * t, (long double)b[i]);
  }
  return need <= have;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &p);
  for (int i = 0; i < n; i++) scanf("%d %d", &a[i], &b[i]);
  long double l = 0.0, r = 1e11;
  for (int step = 0; step < 222; step++) {
    long double mid = (l + r) / 2.0;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  if (l > 5e10)
    printf("-1");
  else
    printf("%.11lf", (double)l);
  return 0;
}
