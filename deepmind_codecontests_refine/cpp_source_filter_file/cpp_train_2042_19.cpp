#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
long long a[MAXN], s1[MAXN], s2[MAXN];
inline long long read() {
  long long x = 0, f = 1;
  char ch = 0;
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int main() {
  long long n, x, y;
  scanf("%lld%lld%lld", &n, &x, &y);
  long long p = (long long)(x * 1.0 / y) + 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    s1[a[i]]++;
    s2[a[i]] += a[i];
  }
  for (long long i = 1; i < MAXN; ++i) s1[i] += s1[i - 1], s2[i] += s2[i - 1];
  long long ans = n * x;
  for (long long i = 2; i <= 1000000; ++i) {
    long long tot = 0;
    for (long long j = i; j <= 1000000 && tot < ans + 4; j += i) {
      long long k = max(j - i, j - p);
      k = max(k, 0LL);
      tot +=
          ((s1[j] - s1[k]) * j - (s2[j] - s2[k])) * y + (s1[k] - s1[j - i]) * x;
    }
    ans = min(tot, ans);
  }
  printf("%I64d\n", ans);
}
