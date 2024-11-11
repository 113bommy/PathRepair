#include <bits/stdc++.h>
long long f[1000005], a[1000005], m, v[1000005];
int n;
struct op {
  long long s, w;
} p[1000005];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  scanf("%d%I64d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    v[i] = a[i];
  }
  std::sort(a + 1, a + 1 + n);
  int cnt = 0;
  long long ans = 1, an = 0;
  p[cnt].s = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == p[cnt].s)
      p[cnt].w++;
    else
      p[++cnt].s = a[i], p[cnt].w = 1;
  }
  for (int i = 1; i <= cnt; i++) {
    long long s = 1;
    for (; s * p[i].s <= m; s++) f[s * p[i].s] += p[i].w;
  }
  for (int i = 1; i <= m; i++) {
    if (ans <= f[i]) ans = f[i], an = i;
  }
  long long ss = 1, flag = 0;
  for (int i = 1; i <= n; i++)
    if (an >= a[i] && an % a[i] == 0) {
      flag = 1;
      long long t = ss;
      ss = t * a[i] / gcd(t, a[i]);
    }
  if (!flag) {
    printf("1 0\n");
    return 0;
  }
  printf("%I64d %I64d\n", ss, ans);
  for (int i = 1; i <= n; i++)
    if (ss % v[i] == 0) printf("%d ", i);
}
