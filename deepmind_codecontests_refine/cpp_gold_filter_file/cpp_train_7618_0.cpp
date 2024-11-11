#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 7;
long long power(long long x, long long y) {
  long long res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long ncr(long long n, long long r) {
  long long res = 1;
  if (r > n) return 0;
  if (r > n - r) r = n - r;
  for (long long i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int n, m, i, j, a[N][N], sum;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", a[i] + j);
  for (i = n; i; i--)
    for (j = m; j; j--) {
      if (!a[i][j]) a[i][j] = min(a[i + 1][j], a[i][j + 1]) - 1;
      sum += a[i][j];
    }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (a[i][j] <= a[i - 1][j] || a[i][j] <= a[i][j - 1]) {
        printf("-1");
        return 0;
      }
  printf("%d", sum);
  return 0;
}
