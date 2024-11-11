#include <bits/stdc++.h>
using namespace std;
long long R, C, n, m, now, lft, rgt, slft, srgt, ans1, ans, sum[10001],
    e[10001], tot, head[10001], nxt[10001], pr[10001], ne[10001], a[10001];
void build(long long t, long long k) {
  tot++;
  e[tot] = k;
  nxt[tot] = head[t];
  head[t] = tot;
}
int main() {
  long long i, t, k, j, j1, j2, i1, i2;
  scanf("%lld%lld%lld%lld", &R, &C, &n, &m);
  for (i = 1; i <= n; i++) {
    scanf("%lld%lld", &t, &k);
    build(t, k);
  }
  for (i1 = R; i1; i1--) {
    for (j = head[i1]; j; j = nxt[j]) sum[e[j]]++;
    j2 = now = ans1 = 0;
    for (j = 1; j <= C; j++) {
      while (j2 + 1 <= C && now < m) {
        j2++;
        now += sum[j2];
      }
      if (now >= m) ans1 += C - j2 + 1;
      now -= sum[j];
    }
    for (i = 0; i <= C + 1; i++) {
      pr[i] = i - 1;
      ne[i] = i + 1;
    }
    for (i = 1; i <= C; i++) a[i] = sum[i];
    for (i = 1; i <= C; i++)
      if (!a[i]) {
        pr[ne[i]] = pr[i];
        ne[pr[i]] = ne[i];
      }
    for (i2 = R; i2 >= i1; i2--) {
      ans += ans1;
      for (i = head[i2]; i; i = nxt[i]) {
        j = e[i];
        lft = rgt = j;
        slft = a[j];
        srgt = 0;
        while (ne[rgt] <= C && slft + srgt + a[ne[rgt]] <= C) {
          rgt = ne[rgt];
          srgt += a[rgt];
        }
        while (1) {
          if (slft + srgt == m) ans1 -= (lft - pr[lft]) * (ne[rgt] - rgt);
          lft = pr[lft];
          if (!lft) break;
          slft += a[lft];
          if (slft > m) break;
          while (slft + srgt > m) {
            srgt -= a[rgt];
            rgt = pr[rgt];
          }
        }
        a[j]--;
        if (!a[j]) {
          pr[ne[j]] = pr[j];
          ne[pr[j]] = ne[j];
        }
      }
    }
  }
  printf("%lld", ans);
}
