#include <bits/stdc++.h>
using namespace std;
int a[5010], b[5010], n, m;
int pri[100010], isp[100010], cnt;
void init() {
  for (int i = 2; i * i < 100010; ++i)
    if (!isp[i])
      for (int j = i * i; j < 100010; j += i) isp[j] = 1;
  for (int i = 2; i < 100010; ++i)
    if (!isp[i]) pri[cnt++] = i;
}
int g(int x) {
  int id = lower_bound(b, b + m, x) - b;
  if (id < m && b[id] == x) return -1;
  return 1;
}
int f(int x) {
  int ans = 0, tmp;
  for (int i = 0; i < cnt && pri[i] <= x / pri[i]; ++i)
    if (x % pri[i] == 0) {
      tmp = 0;
      while (x % pri[i] == 0) {
        ++tmp;
        x /= pri[i];
      }
      ans += tmp * g(pri[i]);
    }
  if (x > 1) ans += g(x);
  return ans;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int gg[5010];
int main() {
  init();
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 0; i < m; ++i) scanf("%d", b + i);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += f(a[i]);
    if (i)
      gg[i] = gcd(gg[i - 1], a[i]);
    else
      gg[i] = a[i];
  }
  int tmp, d = 1;
  for (int i = n - 1; i >= 0; --i) {
    tmp = f(gg[i] / d);
    if (tmp < 0) {
      ans -= tmp * (i + 1);
      d *= gg[i];
    }
  }
  printf("%d\n", ans);
}
