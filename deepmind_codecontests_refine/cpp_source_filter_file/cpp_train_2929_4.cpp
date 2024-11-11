#include <bits/stdc++.h>
long long nxt[50010][16], n, a[50010], top;
long long S[1000001], cnt[1000001], ind;
struct info {
  long long v, w;
} num[1000001];
bool cmp(info a, info b) { return a.v < b.v; }
long long gcd(long long a, long long b) { return (!b) ? a : gcd(b, a % b); }
long long f(long long n, long long a, long long b, long long c) {
  if (n == 1) return a / c;
  if (!b) return (a / c) * n;
  if (a >= c) return f(n, a % c, b, c) + 1ll * (a / c) * n;
  if (b >= c) return f(n, a, b % c, c) + (b / c) * ((n * (n - 1)) >> 1);
  long long m = ((a + b * (n - 1)) / c);
  return n * m + f(m, b - a + c - 1, c, b);
}
long long getans(long long l, long long r, long long u) {
  if (l < r) {
    u -= S[r - 1] - S[l];
    if (u <= 0) return 0;
    long long lim = (u - 1ll * num[l].v * num[l].w) / num[r].v,
              lim2 = u / num[r].v;
    long long ans = 0;
    if (1ll <= lim + 1ll) ans += std::min(lim, 1ll * num[r].w) * num[l].w;
    if (std::max(1ll, lim + 1) <= std::min(1ll * num[r].w, lim2)) {
      long long L = std::max(1ll, lim + 1), R = std::min(1ll * num[r].w, lim2);
      ans += f(R - L + 1, u - 1ll * num[r].v * R, num[r].v, num[l].v);
    }
    return ans;
  } else {
    long long lim = std::min(1ll * num[l].w, u / num[l].v);
    if (lim >= 0ll) return (num[l].w + 1) * lim - ((lim * (lim + 1)) >> 1ll);
  }
}
long long judge(long long u) {
  long long sum = 0, ans = 0;
  for (long long i = 1, j = 1; i <= top; i++) {
    sum += 1ll * num[i].v * num[i].w;
    while (sum - 1ll * num[j].v * num[j].w > u) {
      ans += getans(j, i, u);
      sum -= 1ll * num[j].v * num[j].w;
      ++j;
    }
    ans += getans(j, i, u);
    if (j != i) ans += getans(i, i, u);
    if (j < i) ans += (cnt[i - 1] - cnt[j]) * num[i].w;
    if (ans >= ind) return ans;
  }
  return ans;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld", a + i), nxt[i][0] = a[i];
  for (long long j = 1; j <= 15; j++)
    for (long long i = 1; i + (1 << j) - 1 <= n; i++)
      nxt[i][j] = gcd(nxt[i][j - 1], nxt[i + (1 << (j - 1))][j - 1]);
  for (long long i = 1; i <= n; i++) {
    long long nowpos = i, nowgcd = 0;
    while (nowpos <= n) {
      nowgcd = gcd(nowgcd, a[nowpos]);
      long long old = nowpos;
      for (long long j = 15; ~j; --j)
        if (nxt[nowpos][j] % nowgcd == 0 && nxt[nowpos][j] > 0)
          nowpos += 1 << j;
      num[++top] = (info){nowgcd, nowpos - old};
    }
  }
  std::sort(num + 1, num + top + 1, cmp);
  for (long long i = 1; i <= top; i++)
    S[i] = S[i - 1] + 1ll * num[i].v * num[i].w, cnt[i] = cnt[i - 1] + num[i].w;
  long long sum = 0;
  ind = ((1ll * n * (n + 1)) >> 1ll);
  ind = (ind * (ind + 1)) >> 1ll;
  ind = (ind + 1) >> 1ll;
  long long l = 1, r = 1e18, mid, ans = -1;
  while (l <= r) {
    mid = (l + r) >> 1ll;
    if (judge(mid) >= ind)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", ans);
}
