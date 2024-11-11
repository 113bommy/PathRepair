#include <bits/stdc++.h>
using namespace std;
const int N = 500000 + 5;
int n, m, a[N], x, lst[N], cnt[N], v[N];
long long ans;
int prime[N], isp[N], pre[N], tot;
void getpri() {
  for (int i = 2; i < N; i++) {
    if (!isp[i]) prime[++tot] = i;
    for (int j = 1; j <= tot && i * prime[j] < N; j++) {
      isp[i * prime[j]] = 1;
      pre[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
void add(int c, int f, int pl) {
  if (c == tot + 1) {
    ans += f * cnt[pl];
    cnt[pl]++;
    return;
  }
  add(c + 1, f, pl);
  add(c + 1, -f, pl * lst[c]);
}
void dec(int c, int f, int pl) {
  if (c == tot + 1) {
    cnt[pl]--;
    ans += f * cnt[pl];
    return;
  }
  add(c + 1, f, pl);
  add(c + 1, -f, pl * lst[c]);
}
int main() {
  getpri();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  while (m--) {
    scanf("%d", &x);
    v[x] ^= 1;
    int t = x;
    x = a[x];
    tot = 0;
    while (pre[x]) {
      lst[++tot] = pre[x];
      while (pre[x] == lst[tot]) x /= pre[x];
    }
    if (x != lst[tot] && x != 1) lst[++tot] = x;
    if (v[t])
      add(1, 1, 1);
    else
      dec(1, -1, 1);
    printf("%lld\n", ans);
  }
  return 0;
}
