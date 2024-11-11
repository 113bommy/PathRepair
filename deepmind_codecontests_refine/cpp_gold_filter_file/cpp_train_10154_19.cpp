#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long a[N], b[N], base[65], ans, tot;
int n, cnt;
void ins(long long x) {
  for (int i = 60; i >= 0; i--)
    if (x & (1ll << i))
      if (!base[i]) {
        base[i] = x;
        break;
      } else
        x ^= base[i];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld%lld", &a[i], &b[i]), ins(a[i] ^ b[i]), ans = (ans ^ a[i]);
  for (int i = 0; i <= 60; i++)
    if (base[i]) cnt++, tot |= base[i];
  if (cnt == 0 && tot == ans) return printf("0/1"), 0;
  for (int i = 60; i >= 0; i--)
    if (ans & (1ll << i))
      if (!base[i])
        break;
      else
        ans ^= base[i];
  if (ans) return printf("1/1"), 0;
  long long d = (1ll << cnt);
  printf("%lld/%lld\n", d - 1, d);
  return 0;
}
