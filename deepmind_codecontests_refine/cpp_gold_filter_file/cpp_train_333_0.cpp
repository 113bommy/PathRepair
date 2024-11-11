#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const unsigned long long nmax = 200002;
unsigned long long n, k, a[nmax], s[nmax], t[nmax], c[nmax], r = UINT64_MAX, A,
                                                             B;
int main() {
  scanf("%llu%llu", &n, &k);
  for (unsigned long long i = 1; i <= n; ++i) scanf("%llu", a + i);
  sort(a + 1, a + n + 1);
  for (unsigned long long i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
  for (unsigned long long i = n; i >= 1; --i) t[i] = t[i + 1] + a[i];
  for (unsigned long long i = 1; i <= n; ++i) {
    if (a[i] == a[i - 1])
      c[i] = c[i - 1] + 1;
    else
      c[i] = 1;
    if (c[i] >= k) {
      puts("0");
      return 0;
    }
  }
  for (unsigned long long i = 1; i <= n; ++i) {
    if (i >= k) {
      A = i * a[i] - s[i] - (i - k);
      r = min(r, A);
    }
    if (n - i + 1 >= k) {
      B = t[i] - (n - i + 1) * a[i] - (n - i + 1 - k);
      r = min(r, B);
    }
    r = min(r, i * a[i] - s[i] + t[i] - (n - i + 1) * a[i] - (n - k));
  }
  printf("%llu\n", r);
  return 0;
}
