#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int l, Ans;
long long t, a, b, k;
long long c[N];
int main() {
  scanf("%I64d%I64d%I64d", &t, &a, &b);
  long long m = b;
  if (t == 1 && a == 1) {
    if (m == 1)
      puts("inf");
    else
      puts("0");
    return 0;
  }
  int Ans = 0;
  if (a > 1) {
    if (b > 1) {
      long long x = b;
      while (!(x % a)) x /= a;
      Ans = x == 1;
    }
  } else
    Ans = a == b;
  if (t <= a && a <= b) {
    long long n = b;
    while (n) {
      c[++l] = n % a;
      n /= a;
    }
    long long s = a, x = 1;
    for (int i = 1; i <= l; i++) {
      s -= x * c[i];
      x *= t;
      if (s < 0) break;
    }
    Ans += !s;
  }
  printf("%d\n", Ans);
  return 0;
}
