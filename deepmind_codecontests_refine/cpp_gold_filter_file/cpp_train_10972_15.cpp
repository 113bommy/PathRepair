#include <bits/stdc++.h>
using namespace std;
long long cal(long long t, long long k) {
  if (t == 0) return 0;
  long long ans = 1, temp = 2;
  t++;
  while (t != 0) {
    if (t % 2 != 0) ans = (ans * temp) % 1000000009;
    t /= 2;
    temp = (temp * temp) % 1000000009;
  }
  ans = (ans - 2 + 1000000009) % 1000000009;
  ans = (k * ans) % 1000000009;
  return ans;
}
int main() {
  long long ans, i, n, m, k, p1, p2, temp;
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  p1 = 0;
  p2 = m / k;
  while (p2 - p1 > 100) {
    temp = (p1 + p2) / 2;
    if ((m - temp * k - 1) / (k - 1) + (m - temp * k) <= n - temp * k)
      p2 = temp;
    else
      p1 = temp;
  }
  for (i = p1; i <= p2 && ((m - i * k - 1) / (k - 1) + (m - i * k) > n - i * k);
       i++)
    ;
  ans = (m - i * k) % 1000000009;
  ans = (ans + cal(i, k)) % 1000000009;
  printf("%I64d", ans);
  return 0;
}
