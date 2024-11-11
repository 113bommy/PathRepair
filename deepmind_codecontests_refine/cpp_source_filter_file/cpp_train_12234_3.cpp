#include <bits/stdc++.h>
using namespace std;
int f[10000004], n;
long long gcd(long long x, long long y) { return (y == 0) ? x : gcd(y, x % y); }
int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }
int calc(long long a, long long b) {
  if (f[a] == 0 || f[b] == 0) return 0;
  int p = Find(a), q = Find(b);
  if (p == q) return 0;
  f[p] = q;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    f[x] = x;
  }
  for (long long i = 2; i <= 10000000 << 1; i += 2) {
    for (int long long j = i + 1, a = i / 2 * (j + 1), b = j, c = i / 2 * i + j;
         a <= 10000000 && b <= 10000000; j += 2, a += i, b += j, c += j) {
      if (gcd(a, b) < 1) continue;
      n -= calc(a, b);
      if (c <= 10000000) n -= (calc(a, c) + calc(b, c));
    }
  }
  printf("%d\n", n);
  return 0;
}
