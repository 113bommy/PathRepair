#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2000;
const int mod = 1e9 + 7;
int a[N], n, k;
int l[N], r[N], st[N], ps[N];
int prog(int f, int sh, int n) {
  long long l = f + 1ll * sh * (n - 1);
  l += f;
  if (n % 2 == 0)
    n /= 2;
  else if (l % 2 == 0)
    l /= 2;
  l %= mod;
  n %= mod;
  return 1ll * l * n % mod;
}
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
int calc(int n, int i) {
  if (n < k) return 0;
  int l = 0;
  int r = n + 2;
  long long t = k;
  while (r - l > 0) {
    int mid = (r + l) / 2;
    mid++;
    if (k + 1ll * mid * (k - 1) > n)
      r = mid - 1;
    else
      l = mid;
  }
  int need = l;
  l = 0;
  r = need + 1;
  while (r - l > 0) {
    int mid = (r + l) / 2;
    if (i - k - mid * (k - 1) + 1 >= 1)
      l = mid + 1;
    else
      r = mid;
  }
  int lim1 = l;
  l = 0;
  r = need + 1;
  while (r - l > 0) {
    int mid = (r + l) / 2;
    if (n - k - mid * (k - 1) + 1 >= i)
      l = mid + 1;
    else
      r = mid;
  }
  int lim2 = l;
  int ans = 0;
  add(ans, need + 1);
  add(ans, 1ll * i * lim2 % mod);
  add(ans, prog(n - k - lim2 * (k - 1) + 1, k - 1, need - lim2 + 1));
  sub(ans, prog(i - k + 1, k - 1, lim1));
  sub(ans, need - lim1 + 1);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int sz = 0;
  for (int i = 1; i <= n; i++) {
    while (sz >= 1 && a[i] > st[sz]) sz--;
    l[i] = ps[sz] + 1;
    sz++;
    st[sz] = a[i];
    ps[sz] = i;
  }
  sz = 0;
  ps[sz] = n + 1;
  for (int i = n; i >= 1; i--) {
    while (sz >= 1 && a[i] >= st[sz]) sz--;
    r[i] = ps[sz] - 1;
    sz++;
    st[sz] = a[i];
    ps[sz] = i;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = ans + 1ll * a[i] * calc(r[i] - l[i] + 1, i - l[i] + 1) % mod;
    if (ans >= mod) ans -= mod;
  }
  cout << ans << "\n";
  return 0;
}
