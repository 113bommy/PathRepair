#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 5;
inline int gi() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
inline int fpow(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = (long long)res * x % mod;
    k >>= 1;
    x = (long long)x * x % mod;
  }
  return res;
}
int n, s, t;
int a[maxn], low[maxn], mx[maxn], num[maxn], vis[maxn];
void update(int p, int x) {
  if (x > mx[p])
    mx[p] = x, num[p] = 1;
  else
    num[p] += mx[p] == x;
}
int check(int x) {
  for (int p, c; x > 1;) {
    p = low[x];
    c = 0;
    while (x % p == 0) x /= p, ++c;
    if (c == mx[p] && num[p] == 1) return 0;
  }
  return 1;
}
int main() {
  n = gi();
  s = 1;
  for (int i = 1; i <= n; ++i) a[i] = gi();
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= a[n]; ++i)
    if (!low[i])
      for (int j = i; j <= a[n]; j += i)
        if (!low[j]) low[j] = i;
  for (int i = n, v, x, p, c; i; --i)
    if (mx[v = a[i]])
      for (vis[i] = 1, x = v - 1; x > 1;
           s = (long long)s * fpow(p, max(0, c - mx[p])) % mod, update(p, c)) {
        p = low[x];
        c = 0;
        while (x % p == 0) x /= p, ++c;
      }
    else
      update(v, 1), s = (long long)s * v % mod;
  for (int i = 1; i <= n; ++i)
    if ((vis[i] && check(a[i] - 1)) || (!vis[i] && check(a[i]))) t = 1;
  printf("%d\n", (s + t) % mod);
  return 0;
}
