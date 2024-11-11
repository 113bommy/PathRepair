#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
long long ksm(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = (r * a) % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}
void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inv(long long a, long long p) {
  long long d, x, y;
  exgcd(a, p, d, x, y);
  return d == 1 ? (x + p) % p : -1;
}
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 2e5 + 100;
int n, m, k, a[maxn], vis[maxn];
char p[maxn], t[maxn], q[maxn];
bool check(int x) {
  memset(vis, 0, sizeof(vis));
  int cnt = 0;
  for (int i = 1; i <= x; i++) vis[a[i]]++;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) q[++cnt] = t[i];
  int pos = 1;
  for (int i = 1; i <= cnt; i++) {
    if (q[i] == p[pos]) pos++;
    if (pos == m + 1) break;
  }
  return pos == m + 1;
}
int main() {
  scanf("%s", t + 1);
  scanf("%s", p + 1);
  n = strlen(t + 1);
  m = strlen(p + 1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 0, r = n, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1, ans = max(ans, mid);
    else
      r = mid - 1;
  }
  printf("%d\n", ans);
}
