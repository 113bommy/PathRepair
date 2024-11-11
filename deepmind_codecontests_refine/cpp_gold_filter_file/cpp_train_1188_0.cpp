#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
const double pi = acos(-1);
int fac[120000], ni_fac[120000], n, pos[120000], a[120000];
int Pow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mo;
    x = 1ll * x * x % mo;
    y /= 2;
  }
  return res;
}
int C(int x, int y) {
  return 1ll * fac[x] * ni_fac[y] % mo * ni_fac[x - y] % mo;
}
int work(int l, int r, int s) {
  if (l < 1 || r > n) return 0;
  int ans = (l == r ? 1 : Pow(2, r - l - 1));
  for (int i = s + 1; i <= n; ++i)
    if (pos[i]) {
      int x = pos[i], y = i - s - 1;
      if (x < l) {
        int t = l - x - 1;
        if (y < t) return 0;
        ans = 1ll * ans * C(y, t) % mo;
        r += y - t;
        l = x;
      } else if (x > r) {
        int t = x - r - 1;
        if (y < t) return 0;
        ans = 1ll * ans * C(y, t) % mo;
        l -= y - t;
        r = x;
      } else
        return 0;
      s = i;
    }
  if (l < 1 || r > n) return 0;
  return 1ll * ans * C(l - 1 + n - r, l - 1) % mo;
}
int main() {
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mo;
  ni_fac[n] = Pow(fac[n], mo - 2);
  for (int i = n - 1; i >= 0; --i)
    ni_fac[i] = 1ll * ni_fac[i + 1] * (i + 1) % mo;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pos[a[i]] = i;
  int s = 1;
  while (s <= n && pos[s] == 0) s++;
  int ans;
  if (s > n)
    ans = Pow(2, n - 1);
  else
    ans = (work(pos[s] - s + 1, pos[s], s) +
           (s == 1 ? 0 : work(pos[s], pos[s] + s - 1, s))) %
          mo;
  printf("%d\n", ans);
}
