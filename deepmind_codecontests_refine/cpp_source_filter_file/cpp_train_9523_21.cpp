#include <bits/stdc++.h>
static inline unsigned long long rdtsc() {
  unsigned long long d;
  __asm__ __volatile__("rdtsc" : "=A"(d));
  return d;
}
using namespace std;
const int inf = (int)1e9;
const double eps = 1e-9;
const int maxn = 110;
int a[maxn];
int main() {
  int n;
  long long m;
  scanf("%d%I64d", &n, &m);
  for (int i = 0; (i) < (n); ++i) a[i] = n - 1;
  int l = 0, r = n - 1;
  for (int i = 0; (i) < (n - 1); ++i) {
    if (m > (1 << (n - i - 2))) {
      a[r--] = i;
      m -= (1 << (n - i - 2));
    } else {
      a[l++] = i;
    }
  }
  for (int i = 0; (i) < (n); ++i) printf("%d%c", a[i] + 1, " \n"[i + 1 == n]);
  return 0;
}
