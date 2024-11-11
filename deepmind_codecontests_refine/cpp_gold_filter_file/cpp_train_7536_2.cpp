#include <bits/stdc++.h>
using namespace std;
long long ar[100009];
long long sum[100009];
long long gcd(long long a, long long b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
int main() {
  long long n, i, j;
  scanf("%I64d", &n);
  ar[0] = sum[0] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &ar[i]);
  }
  sort(ar, ar + n + 1);
  for (i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + ar[i];
  }
  long long a, b, c, d, p, q, ans, temp;
  ans = p = q = 0;
  for (i = 1; i <= n; i++) {
    a = sum[i - 1];
    b = sum[n] - sum[i];
    temp = b - a;
    a = i - (n - i);
    b = a * ar[i];
    temp += b;
    if (temp < 0) temp *= -1;
    ans += temp;
  }
  p = gcd(ans, n);
  ans /= p;
  n /= p;
  printf("%I64d %I64d", ans, n);
  return 0;
}
