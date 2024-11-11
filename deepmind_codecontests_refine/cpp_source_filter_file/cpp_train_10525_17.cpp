#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
long long a[maxn], b[maxn], x[maxn], n, t, tmp;
int main() {
  scanf("%lld%lld", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
  for (int i = 1; i <= n; i++)
    if (x[i] < x[i - 1] || x[i] < i) {
      printf("NO\n");
      return 0;
    }
  for (int i = 1; i <= n - 1; i++) b[i] = a[i + 1] + t - !(x[i] == x[i + 1]);
  b[n] = a[n] + t + 1;
  tmp = n;
  for (int i = n; i >= 1; i--) {
    if (tmp != x[i] || b[i] <= b[i - 1]) {
      printf("NO\n");
      return 0;
    }
    if (b[i - 1] - a[i] < t) tmp = i - 1;
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) printf("%lld ", b[i]);
  return 0;
}
