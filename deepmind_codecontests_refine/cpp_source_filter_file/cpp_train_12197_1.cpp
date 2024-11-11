#include <bits/stdc++.h>
const int INF = 1 << 29;
int cmp(const void* a, const void* b);
long long maxv(long long a, long long b);
long long minv(long long a, long long b);
long long gcd(long long u, long long v);
int main() {
  char s[] = "aeiou";
  long long k, n, m;
  scanf("%lld", &k);
  if (k <= 35) {
    printf("-1\n");
    return 0;
  }
  for (long long i = 5; i <= k; i++) {
    if (k % i != 0) continue;
    n = i;
    m = k / i;
    if (m < 5) {
      printf("-1\n");
      return 0;
    }
    break;
  }
  for (long long i = 0; i < (n); i++) {
    for (long long j = 0; j < (m); j++) {
      printf("%c", s[(i + j) % 5]);
    }
  }
}
int cmp(const void* a, const void* b) {
  if (*(long long*)a - *(long long*)b < 0) return -1;
  if (*(long long*)a - *(long long*)b > 0) return 1;
  return 0;
}
long long maxv(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long minv(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long gcd(long long u, long long v) {
  if (v == 0) return u;
  return gcd(v, u % v);
}
