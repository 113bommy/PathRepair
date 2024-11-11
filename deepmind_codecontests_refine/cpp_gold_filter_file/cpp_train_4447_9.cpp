#include <bits/stdc++.h>
using namespace std;
long long n, h, hh, k, l, r, H, ans;
int main() {
  scanf("%lld%lld", &n, &h);
  hh = floor(sqrt(2 * n)) - 1;
  while ((hh + 1) * (hh + 2) <= 2 * n) hh++;
  if (h > hh) h = hh;
  l = h;
  r = hh;
  ans = h;
  while (l <= r) {
    H = (l + r) / 2;
    long long s = H * (H + 1) / 2 + (h + H - 1) * (H - h) / 2;
    if (s <= n) {
      ans = H;
      l = H + 1;
    } else
      r = H - 1;
  }
  H = ans;
  n -= H * (H + 1) / 2 + (h + H - 1) * (H - h) / 2;
  k = n / H;
  if (n % H > 0) k++;
  printf("%lld\n", k + H + H - h);
}
