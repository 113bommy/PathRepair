#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const double INF = 1e12;
const double eps = 1e-9;
int n;
long long a[N];
long long maxSubArray() {
  long long ret = a[0], cur = a[0];
  for (int i = 1; i < n - 1; i++) {
    cur = max(a[i], cur + a[i]);
    ret = max(ret, cur);
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, a);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d", a + i + 1);
    a[i] = abs(a[i + 1] - a[i]);
    if (i % 2) a[i] = -a[i];
  }
  long long res1 = maxSubArray();
  for (int i = 0; i < n - 1; i++) a[i] = -a[i];
  long long res2 = maxSubArray();
  printf("%lld", max(res1, res2));
  return 0;
}
