#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
int n;
int a[MAXN];
int b[MAXN];
int calc(int x) {
  if (b[n] <= x) return n;
  int t = lower_bound(b + 1, b + n + 1, x + 1) - b;
  return t - 1;
}
int calc(int l, int r) { return calc(r) - calc(l - 1); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long rr = 0;
  for (int j = 1; j < 25; j++) {
    int d2 = 1 << j, d1 = d2 >> 1, d3 = d2 + d1, d4 = d2 << 1;
    for (int i = 1; i <= n; i++) b[i] = a[i] % d2;
    sort(b + 1, b + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += calc(d1 - b[i], d2 - b[i] - 1);
      ans += calc(d3 - b[i], d4 - b[i] - 1);
      if ((b[i] << 1) & d1) ans--;
    }
    ans /= 2;
    if (ans & 1) rr += d1;
  }
  printf("%lld\n", rr);
  return 0;
}
