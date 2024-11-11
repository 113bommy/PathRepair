#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
long long t, w, b;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  scanf("%I64d%I64d%I64d", &t, &w, &b);
  long long x = min(w, b);
  long long gc = gcd(w, b);
  long long d = t / (w / gc) / b;
  long long tot = d * x;
  long long res;
  if (d)
    res = t - d * b * (w / gc) + 1;
  else
    res = t + 1;
  long long xx = min(res, min(w, b));
  tot += xx;
  tot--;
  long long gc2 = gcd(tot, t);
  printf("%I64d/%I64d\n", tot / gc2, t / gc2);
  return 0;
}
