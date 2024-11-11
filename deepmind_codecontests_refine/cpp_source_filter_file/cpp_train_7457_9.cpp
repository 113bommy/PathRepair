#include <bits/stdc++.h>
using namespace std;
int a[100010], t[100010], f[10010];
int n, m, q, l, r, cnt;
int phi(int x) {
  int sz = sqrt(x);
  memset(t, 0, sizeof(t));
  int tot = 0;
  int ans = x;
  for (int i = 2; i <= sz; i++) {
    if (x % i == 0) t[++tot] = i;
    while (x % i == 0) x /= i;
  }
  if (x != 1) t[++tot] = x;
  for (int i = 1; i <= tot; i++) ans = ans / t[i] * (t[i] - 1);
  return ans;
}
long long mode(long long a, long long b) {
  if (a < b) return a;
  return a % b;
}
int solve(int l, int r, int dep) {
  if (l > r || dep >= cnt) return 1;
  int ep = solve(l + 1, r, dep + 1);
  long long nowx = a[l];
  long long ans = 1;
  for (; ep; ep >>= 1, nowx = mode(nowx * nowx, f[dep]))
    if (ep & 1) ans = mode(ans * nowx, f[dep]);
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  f[++cnt] = m;
  while (f[cnt] != 1) f[cnt + 1] = phi(f[cnt]), cnt++;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &l, &r);
    printf("%d\n", solve(l, r, 1) % m);
  }
}
