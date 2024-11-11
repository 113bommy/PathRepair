#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
inline int add(int x, int y) {
  return x + y >= 998244353 ? x + y - 998244353 : x + y;
}
inline int add(int x, int y, int z) { return add(add(x, y), z); }
inline int sub(int x, int y) { return x - y < 0 ? x - y + 998244353 : x - y; }
inline int mul(int x, int y) { return 1LL * x * y % 998244353; }
inline int mul(int x, int y, int z) { return mul(mul(x, y), z); }
int fac[2000005], inv[2000005], pinv[2000005];
void init() {
  fac[0] = 1;
  for (int i = 1; i < 2000005; i++) fac[i] = mul(fac[i - 1], i);
  inv[0] = inv[1] = 1;
  for (int i = 2; i < 2000005; i++)
    inv[i] = mul(998244353 - 998244353 / i, inv[998244353 % i]);
  pinv[0] = 1;
  for (int i = 1; i < 2000005; i++) pinv[i] = mul(pinv[i - 1], inv[i]);
}
int C(int x, int y) { return x >= y ? mul(fac[x], pinv[x - y], pinv[y]) : 0; }
int a[2000005], n, ct[2000005];
signed main() {
  init();
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = read(), ct[a[i]]++;
  int maxn = *max_element(a + 1, a + n + 1);
  int ans = 1, sum = 0, sum2 = 0;
  for (int i = 1; i <= maxn; i++) {
    sum2 += ct[i - 1];
    if (i - 1 > n) ct[i - 1] += ct[i - 1 - n];
    sum += ct[i - 1];
    if (sum > i) break;
    int r = i - sum;
    ans = add(ans, sub(C(r + n - 1, n - 1), C(r + sum2 - 1, n - 1)));
  }
  cout << ans << endl;
  return 0;
}
