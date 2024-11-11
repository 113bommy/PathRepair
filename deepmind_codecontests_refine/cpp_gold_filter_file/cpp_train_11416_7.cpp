#include <bits/stdc++.h>
using namespace std;
int get() {
  char c;
  while (!isdigit(c = getchar()))
    ;
  int k = c - '0';
  for (; isdigit(c = getchar()); k = k * 10 + c - '0')
    ;
  return k;
}
const int N = 5010, P = 1e9 + 7;
int n, d[N], pd[N], ipd[N], s[N * 2], f[N * 2];
int inv(int x) { return x > 1 ? 1ll * (P - P / x) * inv(P % x) % P : x == 1; }
int main() {
  n = get(), pd[0] = ipd[0] = 1;
  for (int i = 1; i <= (n - 1); ++i)
    d[i] = get(), pd[i] = pd[i - 1] * 1ll * d[i] % P, ipd[i] = inv(pd[i]);
  for (int i = n - 1; i >= (0); --i) {
    for (int j = 1; j <= ((n - 1 - i) << 1); ++j)
      f[j] = (f[j] + s[j + (i << 1)] * 1ll * (ipd[i] - ipd[i + 1] + P)) % P;
    int t = 1ll * pd[i] * pd[i] % P;
    t = (t & 1 ? t + P : t) >> 1, s[i << 1] = (s[i << 1] + t) % P;
    for (int j = i + 1; j <= (n - 1); ++j)
      s[i + j] = (s[i + j] + 1ll * pd[i] * pd[j]) % P;
  }
  for (int i = n - 1; i >= (1); --i)
    pd[i] = (pd[i] + pd[i + 1]) % P, f[i] = (f[i] + pd[i]) % P;
  for (int i = 1; i <= ((n - 1) << 1); ++i) printf("%d ", f[i]);
  return 0;
}
