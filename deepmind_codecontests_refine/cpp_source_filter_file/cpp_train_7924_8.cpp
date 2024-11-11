#include <bits/stdc++.h>
using namespace std;
long long int powmod(long long int a, int b, int n) {
  long long int rm = 1;
  while (b) {
    if (b % 2) {
      rm = (rm * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return rm;
}
int a[int(1e5 + 10)], t = 0, k;
long long int fun(int v1, int v2, int p1, int p2, int it, int f, int i) {
  long long int t1 = 0;
  if (v1 <= it) {
    if (v2 > a[i - 1]) {
      if (p2 >= f) {
        if (p1 < a[i + 1]) {
          t1 = (long long int)(min(v2, it) - max(a[i - 1] + 1, v1) + 1) *
               (long long int)(min(a[i + k] - 1, p2) - max(f, p1) + 1);
        }
      }
    }
  }
  return t1;
}
int main() {
  int prv = 1;
  a[++t] = 4;
  a[++t] = 7;
  for (int i = 2; i <= 9; ++i) {
    int f = t;
    for (int j = prv; j <= f; ++j) {
      a[++t] = a[j] * 10 + 4;
      a[++t] = a[j] * 10 + 7;
    }
    prv = f + 1;
  }
  a[t + 1] = 2e9;
  int p1, p2, v1, v2;
  cin >> p1 >> p2 >> v1 >> v2 >> k;
  long long int ans = 0;
  a[0] = 0;
  for (int i = 1; i <= t - k + 1; i++) {
    int it = a[i], f = a[i + k - 1];
    long long int t1, t2;
    t1 = fun(v1, v2, p1, p2, it, f, i);
    t2 = fun(p1, p2, v1, v2, it, f, i);
    ans += t1 + t2;
    if (k == 1 && t1 && t2) ans--;
  }
  double fans = ans, g = p2 - p1 + 1;
  g *= v2 - v1 + 1;
  fans /= g;
  printf("%.10lf\n", fans);
  return 0;
}
