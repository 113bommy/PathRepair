#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int main() {
  int a[maxn];
  int n, d;
  scanf("%d %d", &n, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    long long p = upper_bound(a + i, a + 1 + n, a[i] + d) - 1 - a;
    long long a = (p - i - 1) * (p - i) / 2;
    sum += a;
  }
  printf("%lld\n", sum);
  return 0;
}
