#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  long long n, m, k, ans;
  scanf("%lld%lld%lld", &n, &m, &k);
  if (n > m) {
    n += m;
    m = n - m;
    n -= m;
  }
  if (k > n + m - 2)
    ans = -1;
  else if (k + 1 == n || k + 1 == m)
    ans = n * m / (k + 1);
  else if (k < n)
    ans = max(n * (m / (k + 1)), m * (n / (k + 1)));
  else if (k >= n && k < m)
    ans = n * (m / (k + 1));
  else if (k >= m)
    ans = n / (k + 2 - m);
  printf("%d\n", ans);
  return 0;
}
