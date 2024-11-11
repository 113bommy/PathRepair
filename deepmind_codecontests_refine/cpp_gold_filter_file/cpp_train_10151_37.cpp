#include <bits/stdc++.h>
unsigned long long int gcd(unsigned long long int v1,
                           unsigned long long int v2) {
  if (v1 % v2 == 0) return v2;
  return gcd(v2, v1 % v2);
}
unsigned long long int min(unsigned long long int v1,
                           unsigned long long int v2) {
  if (v1 < v2) return v1;
  return v2;
}
int main() {
  unsigned long long int t, t1, w, b, re, uc, sl;
  double v, w1, b1;
  scanf("%lld%lld%lld", &t, &w, &b);
  t1 = t;
  uc = gcd(w, b);
  w1 = w;
  b1 = b;
  v = w1 / uc * b1;
  if (v <= t + 1000) {
    sl = w / uc * b;
    re = (t / sl) * min(w, b) - 1;
    t = t - (t / sl) * sl;
    re = re + min(t + 1, min(w, b));
  } else {
    re = min(w, b) - 1;
    if (re > t) re = t;
  }
  uc = 1;
  if (re > 0) uc = gcd(re, t1);
  if (re > 0)
    printf("%lld/%lld", re / uc, t1 / uc);
  else
    printf("0/1");
  return 0;
}
