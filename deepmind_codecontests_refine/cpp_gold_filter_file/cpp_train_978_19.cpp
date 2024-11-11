#include <bits/stdc++.h>
using namespace std;
long long a[1000005], b[1000005];
int n, tot, cnt[1000005];
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
int main() {
  long long ans = 1;
  srand(time(NULL));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
  }
  for (int step = 0; step < 10; step++) {
    long long val = a[(rand() << 15 | rand()) % n];
    tot = 0;
    for (long long i = 1; i * i <= val; i++) {
      if (val % i == 0) {
        b[tot++] = i;
        if (i != val / i) {
          b[tot++] = val / i;
        }
      }
    }
    sort(b, b + tot);
    fill(cnt, cnt + tot, 0);
    for (int i = 0; i < n; i++) {
      cnt[lower_bound(b, b + tot, gcd(a[i], val)) - b]++;
    }
    for (int i = tot - 1; i >= 0; i--) {
      if (b[i] <= ans) break;
      int sum = 0;
      for (int j = i; j < tot; j++) {
        if (b[j] % b[i] == 0) sum = sum + cnt[j];
      }
      if (sum * 2 >= n) {
        ans = b[i];
      }
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
