#include <bits/stdc++.h>
long long a[300009], b[300009], c[300009];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++) scanf("%lld %lld", &a[i], &b[i]);
    for (int i = 1; i < n; i++) {
      if (b[i] >= a[i + 1])
        c[i] = 0;
      else
        c[i] = a[i + 1] - b[i], sum += c[i];
    }
    if (b[n] < a[1])
      c[n] = a[1] - b[n], sum += a[1] - b[n];
    else
      c[n] = 0;
    long long min = a[1] - c[n];
    for (int i = 2; i <= n; i++)
      if (a[i] - c[i - 1] < min) min = a[i] - c[i - 1];
    sum += min;
    printf("%lld\n", sum);
  }
}
