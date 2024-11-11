#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 100;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long qpow(long long base, int t) {
  long long ret = 1;
  while (t) {
    if (t & 1) ret = ret * base % mod;
    base = base * base % mod;
    t >>= 1;
  }
  return ret;
}
void FWT(long long* a, int n, int op) {
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += len * 2) {
      for (int j = i; j < i + len; j++) {
        int x = a[j], y = a[j + len];
        a[j] = (x + y);
        a[j + len] = (x - y);
        if (op == -1) a[j] /= 2, a[j + len] /= 2;
      }
    }
  }
}
long long b[maxn], a[maxn];
long long d[maxn];
char s[maxn];
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  int tot = 1 << n;
  for (int i = 0; i < tot; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++)
      if ((i & (1 << j)) == 0) cnt++;
    d[i] = min(cnt, n - cnt);
  }
  memset(a, 0, sizeof a);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) a[i] = a[i] * 2 + s[i] - '0';
  }
  for (int i = 0; i < m; i++) b[a[i]]++;
  FWT(d, tot, 1);
  FWT(b, tot, 1);
  for (int i = 0; i < tot; i++) d[i] *= b[i];
  FWT(d, tot, -1);
  long long ans = n * m;
  for (int i = 0; i < tot; i++) ans = min(ans, d[i]);
  printf("%lld\n", ans);
}
