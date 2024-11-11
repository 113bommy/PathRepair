#include <bits/stdc++.h>
using namespace std;
const long long INF = 2147483647;
long long a[1000005];
queue<long long> q;
void check(long long o) {
  long long n = o;
  long long s = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      s = 2;
      q.push(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) q.push(n);
}
int main() {
  long long n, i, j;
  scanf("%I64d", &n);
  long long sum = 0;
  long long o = 0;
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    sum += a[i];
  }
  if (sum == 0) {
    printf("0");
    return 0;
  }
  if (sum == 1)
    printf("-1");
  else {
    check(sum);
    long long ans = 1e18;
    while (!q.empty()) {
      long long k = q.front();
      q.pop();
      sum = 0;
      long long pre = 0;
      for (i = 1; i <= n; i++) {
        pre = (pre + a[i]) % k;
        sum += min(pre, k - pre);
      }
      ans = min(ans, sum);
    }
    printf("%I64d", ans);
  }
  return 0;
}
