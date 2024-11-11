#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long f[N];
int n, k, p[10];
inline void doit(long long v, long long w) {
  for (int i = 1e6; i >= v; i--) f[i] = max(f[i], w + f[i - v]);
}
inline void Push(long long vv, long long ww) {
  int now = min((long long)k, (int)1e6 / vv);
  for (int i = 1; i <= now; i <<= 1) now -= i, doit(1ll * i * vv, 1ll * i * ww);
  doit(1ll * now * vv, 1ll * now * ww);
}
int main() {
  scanf("%d", &k);
  k = 3 * (k - 1);
  for (int i = 0; i <= 5; i++) scanf("%d", &p[i]);
  for (int i = 0; i <= 1e6; i++) {
    int x = i, s, now = 0;
    while (x) {
      s = x % 10;
      if (s % 3 == 0) f[i] += 1ll * p[now] * (s / 3);
      x /= 10;
      now++;
    }
  }
  int sz = 1;
  for (int i = 0; i <= 5; i++) Push(3 * sz, p[i]), sz *= 10;
  scanf("%d", &n);
  int t;
  for (int i = 1; i <= n; i++) scanf("%d", &t), printf("%d\n", f[t]);
}
