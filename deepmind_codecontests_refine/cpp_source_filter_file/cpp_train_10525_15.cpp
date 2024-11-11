#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005], x[200005], n, t, tmp;
int main() {
  scanf("%lld%lld", &n, &t);
  for (register int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (register int i = 1; i <= n; i++) scanf("%lld", &x[i]);
  for (register int i = 1; i <= n; i++)
    if (x[i] < x[i - 1] || x[i] < i) return puts("NO"), 0;
  for (register int i = 1; i <= n - 1; i++)
    b[i] = a[i + 1] + t - !(x[i] == x[i + 1]);
  b[n] = a[n] + t + 1;
  tmp = n;
  for (register int i = n; i >= 1; i--) {
    if (tmp != x[i] || b[i] <= b[i - 1]) return puts("NO"), 0;
    if (b[i - 1] - a[i] < t) tmp = i - 1;
  }
  puts("YES");
  for (register int i = 1; i <= n; i++) printf("%lld ", b[i]);
  return 0;
}
