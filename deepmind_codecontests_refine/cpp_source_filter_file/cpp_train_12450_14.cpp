#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
long long arr[maxn];
long long brr[maxn];
long long n, p;
int ok(double time) {
  double cnt = 0;
  double charge = time * p;
  for (int i = 1; i <= n; i++) {
    if (arr[i] * time > brr[i]) {
      cnt += arr[i] * time - brr[i];
    }
  }
  if (cnt > charge) {
    return 0;
  }
  return 1;
}
int main() {
  scanf("%lld %lld", &n, &p);
  long long consume = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld", &arr[i], &brr[i]);
    consume += arr[i];
  }
  if (consume <= p) {
    printf("-1\n");
    return 0;
  }
  double l, r, m;
  l = 0;
  r = 2e9;
  for (int i = 1; i <= 60; i++) {
    m = (l + r) / 2.0;
    if (ok(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%lf\n", m);
}
