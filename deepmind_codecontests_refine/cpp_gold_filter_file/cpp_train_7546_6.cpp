#include <bits/stdc++.h>
using namespace std;
bool isp[200005];
int p[200005], pn;
int c[200005];
inline int haha(int n, int g) {
  int ret = 0;
  for (long long i = g; i <= n; i *= g) ret += n / i;
  return ret;
}
void cal(int n, int d) {
  for (int i = 0; i < pn && p[i] <= n; ++i) c[i] += d * haha(n, p[i]);
}
long long mod_pow(long long x, int n, int mod) {
  long long s = 1;
  while (n) {
    if (n & 1) s = (s * x) % mod;
    x = (x * x) % 1000000007;
    n >>= 1;
  }
  return s;
}
int gao() {
  long long ret = 1;
  for (int i = 0; i < pn; ++i)
    ret = (ret * mod_pow(p[i], c[i], 1000000007)) % 1000000007;
  return (int)ret;
}
int main() {
  pn = 0;
  memset(isp, 1, sizeof(isp));
  for (int i(2), _b(200005); i < _b; ++i)
    if (isp[i]) {
      p[pn++] = i;
      for (int j = i + i; j < 200005; j += i) isp[j] = 0;
    }
  int n;
  memset(c, 0, sizeof(c));
  scanf("%d", &n);
  cal(n + n - 1, 1);
  cal(n, -1);
  cal(n - 1, -1);
  int p = gao();
  p = (p + p - n) % 1000000007;
  printf("%d\n", (p + 1000000007) % 1000000007);
  return 0;
}
