#include <bits/stdc++.h>
using namespace std;
int n, top;
long long r[100005], h[100005], a[100005], ar[100005], b[100005], f[100005],
    ans;
long long c[100005];
long long query(int x) {
  long long ret = 0;
  for (; x; x -= (x & (-x))) ret = max(ret, c[x]);
  return ret;
}
void add(int x, long long y) {
  for (; x <= top; x += (x & (-x))) c[x] = max(c[x], y);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d%I64d", &r[i], &h[i]);
    b[i] = ar[i] = r[i] * r[i] * h[i];
  }
  sort(b + 1, b + n + 1);
  top = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + n + 1, ar[i]) - b;
  for (int i = 1; i <= n; i++) {
    f[i] = query(a[i] - 1) + ar[i];
    ans = max(ans, f[i]);
    add(a[i], f[i]);
  }
  printf("%.10lf\n", ans * acos(-1.0));
}
